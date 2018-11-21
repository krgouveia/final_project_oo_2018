#include "tilm4f120hqr.h"
// Simple serial console class

class cCircularBuffer
{
#define BUF_SIZE 32
#define NEWLINE 0x0d
#define LINEFEED 0x0a
public:
	cCircularBuffer()
	{
		head=tail=count=0;
	}
	int putBuf(char c)
	{
		if ( (head==tail) && (count!=0))
			return(1);  /* OverFlow */
		disable_interrupts();
		buffer[head++] = c;
		count++;
		if (head==BUF_SIZE)
			head=0;
		enable_interrupts();
		return(0);
	}
	char getBuf(void)
	{
		unsigned char Data;
		if ( count==0 )
			return (0);
		disable_interrupts();
		Data = buffer[tail++];
		if (tail == BUF_SIZE)
			tail = 0;
		count--;
		enable_interrupts();
		return (Data);
	}
	int getBufCount()
	{
		return count;
	}
	

private:
	int head,tail,count;
	char buffer[BUF_SIZE];
};
class cConsole
{
public:
	void print(const char *str)
	{
		eputs(str);
	}
	void print(int x)
	{
		// Output the number over the serial port as
		// as hexadecimal string.
		char TxString[9];
		int Index=8;
		TxString[Index]=0; // terminate the string
		Index--;
		while(Index >=0)
		{
			TxString[Index]=HexDigit(x & 0x0f);
			x = x >> 4;
			Index--;
		}
		eputs(TxString);
	}

	void println(const char *str)
	{
		print(str);
		print("\r\n");
	}	
	void println(int x)
	{
		print(x);
		print("\r\n");
	}
	char HexDigit(int Value)
	{
		if ((Value >=0) && (Value < 10))
			return Value+'0';
		else if ((Value >9) && (Value < 16))
			return Value-10 + 'A';
		else
			return 'z';
	}

	cConsole(int BaudRate)
	{
		int BaudRateDivisor;
		disable_interrupts();
		ComOpen = 1;
		ComError = 0;
	// Boost system speed up to 80MHz
	
	// Turn on the clock for GPIOA (uart 0 uses it) - not sure if I need this
		SET_BIT(SYSCTL_RCGC2,BIT0); 		 // turn on GPIOA
		SET_BIT(SYSCTL_GPIOHBCTL,BIT0);      // turn on AHB access to GPIOA	
	// Turn on the clock for the UART0 peripheral	
		SYSCTL_RCGCUART |= BIT0;

	// Ensure alternate function number for PA0 and PA1
		SET_BIT(GPIOA_AFSEL,BIT0+BIT1);
		SET_BIT(GPIOA_PUR,BIT0+BIT1);
		SET_BIT(GPIOA_DEN,BIT0+BIT1);
		BaudRateDivisor = 80000000;                // assuming 80MHz clock 
		BaudRateDivisor = BaudRateDivisor / (16 * BaudRate);
		
		UART0_IBRD = BaudRateDivisor;  

		UART0_LCRH = BIT6+BIT5; // no parity, 8 data bits, 1 stop bit
		
		UART0_CTL = BIT9+BIT0; // enable rx and uart

	// Enable UART0 interrupts in NVIC	
		SYS_EN0 = BIT5;
	// and enable interrupts 
		SET_BIT(UART0_IM,BIT4+BIT5);
		enable_interrupts();
	}
	int eputs(const char *s)
	{
		// only writes to the comms port at the moment
		if (!ComOpen)
			return -1;
		while (*s) 
		{
			// if buffer is full then spin until
			// a gap is available
			while(TXBuffer.getBufCount()==BUF_SIZE);
			WriteCom(1,s++);
		}
		return 0;
	}
	int egets(char *s,int Max)
	{
		// read from the comms port until end of string
		// or newline is encountered.  Buffer is terminated with null
		// returns number of characters read on success
		// returns 0 or -1 if error occurs
		// Warning: This is a blocking call.
		int Len;
		char c;
		if (!ComOpen)
			return -1;
		Len=0;
		c = 0;
		while ( (Len < Max-1) && (c != NEWLINE) )
		{   
			while (!RXBuffer.getBufCount()); // wait for a character
			c = RXBuffer.getBuf();
			s[Len++] = c;
		}
		if (Len>0)
		{
			s[Len]=0;
		}	
		return Len;
	}

	int ReadCom(int Max, char *Buffer)
	{
	// Read up to Max bytes from the communications buffer
	// into Buffer.  Return number of bytes read
		unsigned i;
		if (!ComOpen)
			return (-1);
		i=0;
		while ((i < Max-1) && (RXBuffer.getBufCount()))
			Buffer[i++] = RXBuffer.getBuf();
		if (i>0)
		{
			Buffer[i]=0;
			return(i);
		}
		else {
			return(0);
		}	
	};
	int WriteCom(int Count, const char *Buffer)
	{
	// Writes Count bytes from Buffer into the the communications TX buffer
	// returns -1 if the port is not open (configured)
	// returns -2 if the message is too big to be sent
	// If the transmitter is idle it will initiate interrupts by 
	// writing the first character to the hardware transmit buffer
		unsigned i,BufLen;
		if (!ComOpen)
			return (-1);
		BufLen = TXBuffer.getBufCount();
		if ( (BUF_SIZE - BufLen) < Count )
			return (-2); 
		for(i=0;i<Count;i++)
			TXBuffer.putBuf(Buffer[i]);
		
		if ( (UART0_CTL & BIT8)==0)
		{ // transmitter was idle, turn it on and force out first character
		  SET_BIT(UART0_CTL,BIT8);
		  UART0_DR = TXBuffer.getBuf();		
		} 
		return 0;
	};
	friend void isr_uart(void);
private:
	int ComError,ComOpen;
	cCircularBuffer TXBuffer,RXBuffer;
	void usart_rx (void)
	{
	// Handles serial comms reception
	// simply puts the data into the buffer and sets the ComError flag
	// if the buffer is fullup

		if (RXBuffer.putBuf(UART0_DR & 0xff)) 
			ComError = 1; // if PutBuf returns a non-zero value then there is an error
		UART0_ICR = BIT4; // clear the rx interrupt
	}
	void usart_tx (void)
	{
	// Handles serial comms transmission
	// When the transmitter is idle, this is called and the next byte
	// is sent (if there is one)
		if (TXBuffer.getBufCount())
			UART0_DR=TXBuffer.getBuf();
		else
		{
		  // No more data, disable the transmitter 
		  CLEAR_BIT(UART0_CTL,BIT8);
		}
		UART0_ICR = BIT5; // clear the tx interrupt
	}
};
cConsole console(9600);
void isr_uart(void) 
{
	// check which interrupt happened.
	if (UART0_MIS & BIT5) // is it a TXE interrupt?
		console.usart_tx();
	if (UART0_MIS & BIT4) // is it an RXNE interrupt?
		console.usart_rx();
}
