/**
 * \file UART_UC.cpp
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 28, 2018
 *
 **************************************************************************
 *
 * Module Name:  UART_UC.cpp
 *
 * \brief Define the class implements the methods to acess the CConsole class.
 *
 * \section References
 *
 **************************************************************************
 * \section Revisions
 *
 * Revision: 1.0   28-Nov-2018    Kleber Gouveia
 * * Working baseline.
 *
 ***************************************************************************/

#include "UART_UC.h"
#include "driverlib/uart.h"
#include "uartstdio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
//#include "inc/hw_gpio.h"
#include "driverlib/pin_map.h"
using namespace std;

/**
*   \brief Class constructor. 
*/
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

    //Disable UART echo.
    UARTEchoSet(false);

	systemClockReference = nullptr;

	 UARTprintf("[LOG] Console running!\n\n");
	 UARTprintf("*********** Commands list ***********\n");
	 UARTprintf("=h - to show commands list.\n");
	 UARTprintf("=n<string>; - to insert new messages. <string> is the message to be inserted.\n");
	 UARTprintf("=t - to enable new messages to be shown.\n");
	 UARTprintf("=r - to remove last message shown.\n");
	 UARTprintf("*************************************\n\n");
}

/**
*   \brief Class constructor. 
*/
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

    //Register the UART interrupt handler.
    UARTIntRegister(UART0_BASE, UARTStdioIntHandler);

    // Initialize the UART for console I/O.
    UARTStdioConfig(0, 115200, 16000000);

    //Disable UART echo.
    UARTEchoSet(false);

	systemClockReference = sysCk;
	
	UARTprintf("[LOG] Console running!\n\n");
	UARTprintf("*********** Commands list ***********\n");
	UARTprintf("=h - to show commands list.\n");
	UARTprintf("=n<string>; - to insert new messages. <string> is the message to be inserted.\n");
	UARTprintf("=t - to enable new messages to be shown.\n");
	UARTprintf("=r - to remove last message shown.\n");
	UARTprintf("*************************************\n\n");
}

/**
*   \brief Class destructor. 
*/
CConsole::~CConsole()
{

}

/**
 * \brief Method to send strings for log information via console.
 * \param str - string to be sent, newLine - if true, send a newLine (\n) 
 * in the end of string. If false, doesn't.
 * \return none
 */
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

/**
 * \brief Method to send integers for log information via console.
 * \param num - number to be sent, newLine - if true, send a newLine (\n) 
 * in the end of string. If false, doesn't.
 * \return none
 */
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

/**
 * \briefThis method verifies if there was some valid input from keyboard.
 * If yes, put the input in com.
 * \param com - pointer to char
 * \return Return true if a valid input was received, false if no.
 */
bool CConsole::ReadCommand(char* com)
{
    if (UARTRxBytesAvail() > 0)
    {
        *com = UARTgetc();
        return true;
    }

	return false; // No keys were pressed
}
