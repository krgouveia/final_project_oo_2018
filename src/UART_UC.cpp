
#include "UART_UC.h"
#include "driverlib/uart.h"
#include "uartstdio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
//#include "inc/hw_gpio.h"
#include "driverlib/pin_map.h"
using namespace std;

CConsole::CConsole()
{
	// Enable the GPIO Peripheral used by the UART.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    // Enable UART0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    // Configure GPIO Pins for UART mode.
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    // Use the internal 16MHz oscillator as the UART clock source.
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);

    //Register the UART interrupt handler.
    UARTIntRegister(UART0_BASE, UARTStdioIntHandler);

    // Initialize the UART for console I/O.
    UARTStdioConfig(0, 115200, 16000000);

	systemClockReference = nullptr;

	 UARTprintf("[LOG] Console running!\n\n");
	 UARTprintf("*********** Commands list ***********\n");
	 UARTprintf("=h - to show commands list.\n");
	 UARTprintf("=n<string>; - to insert new messages. <string> is the message to be inserted.\n");
	 UARTprintf("=t - to enable new messages to be shown.\n");
	 UARTprintf("=r - to remove last message shown.\n");
	 UARTprintf("*************************************\n\n");
}

CConsole::CConsole(CTime* sysCk)
{
	// Enable the GPIO Peripheral used by the UART.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    // Enable UART0
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    // Configure GPIO Pins for UART mode.
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    // Use the internal 16MHz oscillator as the UART clock source.
    UARTClockSourceSet(UART0_BASE, UART_CLOCK_PIOSC);

    // Initialize the UART for console I/O.
    UARTStdioConfig(0, 115200, 16000000);

	systemClockReference = sysCk;
	
	UARTprintf("[LOG] Console running!\n\n");
	UARTprintf("*********** Commands list ***********\n");
	UARTprintf("=h - to show commands list.\n");
	UARTprintf("=n<string>; - to insert new messages. <string> is the message to be inserted.\n");
	UARTprintf("=t - to enable new messages to be shown.\n");
	UARTprintf("=r - to remove last message shown.\n");
	UARTprintf("*************************************\n\n");
}

CConsole::~CConsole()
{

}

void CConsole::writeLogString(string str, bool newLine)
{
	if (systemClockReference == nullptr)
	{
		if (newLine) UARTprintf("[LOG] %s\n", str.c_str());
		else UARTprintf("%s", str.c_str());
	}
	else
	{
		if (newLine) UARTprintf("[LOG] %s %s\n", systemClockReference->getSystemClockString().c_str(), str.c_str());
		else UARTprintf("%s", str.c_str());
	}
}

void CConsole::writeLogInteger(int num, bool newLine)
{
	if (systemClockReference == nullptr)
	{
		if (newLine) UARTprintf("[LOG] %u\n", num);
		else UARTprintf("%u", num);
	}
	else
	{
		if (newLine) UARTprintf("[LOG] %s %u\n", systemClockReference->getSystemClockString().c_str(), num);
		else UARTprintf("%u", num);
	}
}

bool CConsole::ReadCommand(char* com)
{
    if (UARTRxBytesAvail() > 0)
    {
        *com = UARTgetc();
        return true;
    }

	return false; // No keys were pressed
}
