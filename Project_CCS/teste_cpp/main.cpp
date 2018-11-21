#include "tilm4f120hqr.h"
#include "leds.h"
#include "console.h"
#include "buttons.h"
cButtons buttons;
cLeds Leds; 
int main()
{
	console.print("Hello World");
	while(1)
	{
		Leds.allOff();
		if (buttons.button1())
			Leds.setRed(1);
		if (buttons.button2())
			Leds.setBlue(1);
		if (buttons.button1() && buttons.button2())
			Leds.setGreen(1);		
		console.print("GPIOF: ");
		console.println((int)GPIOF_DATA);
	}
	return 0; // should never get here
}

