// Buttons are on PORT F
// Bit4 = SW1
// Bit0 = SW2
#include "tilm4f120hqr.h"
class cButtons
{
public:
	cButtons()
	{
		// Turn on button port (Port F)
		// and configure pin modes for port
		SET_BIT(SYSCTL_RCGC2,BIT5); 		 // turn on GPIOF
		SET_BIT(SYSCTL_GPIOHBCTL,BIT5);      // turn on AHB access to GPIOF	
		// PF0 is a protected bit so need to unlock first
		GPIOF_LOCK = 0x4c4f434b;			 // unlock GPIOF_CR
		SET_BIT(GPIOF_CR,BIT0);				 // enable commit of bit 0 of GPIOF_DEN
		SET_BIT(GPIOF_DEN,(BIT0+BIT4)); 	 // digital mode bits 0,4 of GPIOF
		CLEAR_BIT(GPIOF_DIR,(BIT0+BIT4));    // make bits 0,4 inputs on GPIOF
		SET_BIT(GPIOF_PUR,(BIT0+BIT4));		 // enable pull-up resistors 
		CLEAR_BIT(GPIOF_CR,BIT0);			 // clear commit bit
		GPIOF_LOCK = 1;						 // restore the lock on GPIOF
	}
	int button1()
	{
		return  ((GPIOF_DATA & BIT4)==0);
	}
	int button2()
	{
		return  ((GPIOF_DATA & BIT0)==0);
	}
private:
};

