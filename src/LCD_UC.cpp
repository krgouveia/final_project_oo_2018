/**
 * \file LCD_UC.h
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 27, 2018
 *
 **************************************************************************
 *
 * Module Name:  LCD_UC.h
 *
 * \brief Implements the methods of the CLCD class.
 *
 * \section References
 *
 **************************************************************************
 * \section Revisions
 *
 * Revision: 1.0   27-Nov-2018    Kleber Gouveia
 * * Working baseline.
 *
 ***************************************************************************/

#include "LCD_UC.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_memmap.h"
#include "LCD_NHDC12864.h"
#include <string>
using namespace std;

/**
*   \brief Class constructor. 
*/
CLCD::CLCD()
{
	//--GPIO PORTA
    // Enable and wait for the port to be ready for access
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA));
	// Configure the GPIO port for outputs.
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, LCD_D0|LCD_D1|LCD_D2|LCD_D3|LCD_D4|LCD_D5);
    // Configure GPIO driver strength and pull-ups
    GPIOPadConfigSet(GPIO_PORTA_BASE, LCD_D0|LCD_D1|LCD_D2|LCD_D3|LCD_D4|LCD_D5, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
	
	//--GPIO PORTB
    // Enable and wait for the port to be ready for access
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB));
	// Configure the GPIO port for outputs.
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, LCD_A0|LCD_RD|LCD_D6);
    // Configure GPIO driver strength and pull-ups
    GPIOPadConfigSet(GPIO_PORTB_BASE, LCD_A0|LCD_RD|LCD_D6, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);

	//--GPIO PORTE
    // Enable and wait for the port to be ready for access
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE));
	// Configure the GPIO port for outputs.
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, LCD_WR|LCD_D7);
    // Configure GPIO driver strength and pull-ups
    GPIOPadConfigSet(GPIO_PORTE_BASE, LCD_WR|LCD_D7, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);

    LCDInitializeNHDC12864();
    LCDSetPage(0);
    LCDSetColumn(0);
}

/**
*   \brief Class destructor. 
*/
CLCD::~CLCD()
{

}

 /**
 * \brief Method to clear the entire LCD
 * \param none
 * \return none
 */
void CLCD::clearScreen()
{
	LCDClear();
	setPosition(0,0);
}

 /**
 * \brief Method to write a string in the LCD
 * \param str - string to write
 * \return none
 */
void CLCD::writeString(string str)
{
    char* auxP = (char*)str.c_str();

    clearScreen();
	LCDWriteString(times8,auxP);
}

 /**
 * \brief Method to write a number in the LCD
 * \param num - number to write
 * \return none
 */
void CLCD::writeInteger(int num)
{

}

 /**
 * \brief Method to the position to write in LCD
 * \param x - is the column
 * \param y - is the page
 * \return none
 */
void CLCD::setPosition(int x, int y)
{
	LCDSetPage(y);
	LCDSetColumn(x);
}
