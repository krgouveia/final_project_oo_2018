// Leds are on PORT F 
// Bit1 = Red
// Bit2 = Blue
// Bit3 = Green

#include "tilm4f120hqr.h"
class cLeds {
public:
	cLeds()
	{
		// Turn on LED port (Port F)
		// and configure pin modes for port
		SET_BIT(SYSCTL_RCGC2,BIT5); 		 // turn on GPIOF
		SET_BIT(SYSCTL_GPIOHBCTL,BIT5);      // turn on AHB access to GPIOF	
		SET_BIT(GPIOF_DEN,(BIT1+BIT2+BIT3)); // digital mode bits 1,2,3 of GPIOF
		SET_BIT(GPIOF_DIR,(BIT1+BIT2+BIT3)); // make bits 1,2,3 outputs on GPIOF
	}
	void setRed(int state)
	{
		if (state)
			SET_BIT(GPIOF_DATA,BIT1);
		else
			CLEAR_BIT(GPIOF_DATA,BIT1);
		
	}
	void setBlue(int state)
	{
		if (state)
			SET_BIT(GPIOF_DATA,BIT2);
		else
			CLEAR_BIT(GPIOF_DATA,BIT2);		
	}
	void setGreen(int state)
	{
		if (state)
			SET_BIT(GPIOF_DATA,BIT3);
		else
			CLEAR_BIT(GPIOF_DATA,BIT3);		
	}
	void allOff()
	{
		setRed(0);
		setGreen(0);
		setBlue(0);
	}
};
