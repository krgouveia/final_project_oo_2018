/**
 * \file GPIO_UC.cpp
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 10, 2018
 *
 **************************************************************************
 *
 * Module Name:  GPIO_UC.cpp
 *
 * \brief Implements the methods of the CGPIO class.
 *
 * \section References
 *
 **************************************************************************
 * \section Revisions
 *
 * Revision: 1.0   10-Nov-2018    Kleber Gouveia
 * * Working baseline.
 *
 ***************************************************************************/

#include "GPIO_UC.h"

#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"

void GPIOISR(void);

/**
*   \brief GPIO constructor. This method create a GPIO object instance.
*/
CGPIO::CGPIO()
{
    //--Clock
    // Setup the system clock to run at 80 Mhz from PLL with crystal reference
    SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

    //--GPIO ports D, E and F
    // Enable and wait for the port to be ready for access
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD));
    // Enable and wait for the port to be ready for access
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE));
    // Enable and wait for the port to be ready for access
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

    //SW2 is a NMI pin and need this procedure to unlock port F to be reconfigured
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= ETIRPS_IN;

    // Configure the GPIOF port for outputs.
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, MEET_OUT|ETIRPS_OUT);
    // Configure the GPIOF port for inputs.
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, MEET_IN|ETIRPS_IN);
    // Configure GPIOF driver strength and pull-ups
    GPIOPadConfigSet(GPIO_PORTF_BASE, MEET_IN|ETIRPS_IN|MEET_OUT|ETIRPS_OUT, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    // Configure the GPIOD port for inputs.
    GPIOPinTypeGPIOInput(GPIO_PORTD_BASE, M025_IN|M050_IN|M100_IN|DEV_IN);
    // Configure GPIOD driver strength and pull-ups
    GPIOPadConfigSet(GPIO_PORTD_BASE, M025_IN|M050_IN|M100_IN|DEV_IN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    // Configure the GPIOE port for outputs.
    GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE, M025_OUT|M050_OUT|M100_OUT);
    // Configure GPIOE driver strength and pull-ups
    GPIOPadConfigSet(GPIO_PORTE_BASE, M025_OUT|M050_OUT|M100_OUT, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);


    /** Configuring GPIO interrupts*/

    // Register the port-level interrupt handler. This handler is the first
    // level interrupt handler for all the pin interrupts.
    setCurrent(this);
    GPIOIntRegister(GPIO_PORTF_BASE, GPIOISR);
    GPIOIntRegister(GPIO_PORTD_BASE, GPIOISR);
    // Set the interrupt type for RISING_EDGE
    GPIOIntTypeSet(GPIO_PORTD_BASE, M025_IN|M050_IN|M100_IN|DEV_IN, GPIO_RISING_EDGE);
    GPIOIntTypeSet(GPIO_PORTF_BASE, MEET_IN|ETIRPS_IN, GPIO_RISING_EDGE);

    // Enabling the GPIOs interrupts
    //GPIOIntEnable(GPIO_PORTF_BASE, M025_IN|M050_IN|M100_IN|MEET_IN|ETIRPS_IN|DEV_IN);
    GPIOIntEnable(GPIO_PORTD_BASE, M025_IN|M050_IN|M100_IN|DEV_IN);
    GPIOIntEnable(GPIO_PORTF_BASE, MEET_IN|ETIRPS_IN);

    //lock port F
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;
}

/**
 * \brief Class destructor
 */ 
CGPIO::~CGPIO()
{

}

/**
 * \brief This method was supposed to manage the GPIOs input, but in
 * ARM platfor this fuction will be done by the ISR.
 * \param queueP - Pointer to an Cqueue object.
 * \return none
 */
void CGPIO::readInputs(Cqueue<string>* queueP)
{

}

/**
 * \brief Method responsible to update the outputs.
 * \param queueP - Pointer to an Cqueue object.
 * \return none
 */
void CGPIO::writeOutputs(Cqueue<string>* queueP)
{
	string auxS;
	
	if (getOutput(M025))
	{
	    GPIOPinWrite(GPIO_PORTE_BASE, M025_OUT, M025_OUT);
	    SysCtlDelay(1000000);
	    GPIOPinWrite(GPIO_PORTE_BASE, M025_OUT, 0);
		auxS = "R$0,25 returned.";
		queueP->pushBack(auxS);
		clearOutput(M025);
	}

	if (getOutput(M050))
	{
	    GPIOPinWrite(GPIO_PORTE_BASE, M050_OUT, M050_OUT);
	    SysCtlDelay(1000000);
	    GPIOPinWrite(GPIO_PORTE_BASE, M050_OUT, 0);
		auxS = "R$0,50 returned.";
		queueP->pushBack(auxS);
	    clearOutput(M050);
	}

	if (getOutput(M100))
	{
	    GPIOPinWrite(GPIO_PORTE_BASE, M100_OUT, M100_OUT);
	    SysCtlDelay(1000000);
	    GPIOPinWrite(GPIO_PORTE_BASE, M100_OUT, 0);
		auxS = "R$1,00 returned.";
		queueP->pushBack(auxS);
	    clearOutput(M100);
	}

	if (getOutput(MEET))
	{
	    GPIOPinWrite(GPIO_PORTF_BASE, MEET_OUT, MEET_OUT);
	    SysCtlDelay(1000000);
	    GPIOPinWrite(GPIO_PORTF_BASE, MEET_OUT, 0);
		auxS = "MEET released.";
		queueP->pushBack(auxS);
	    clearOutput(MEET);
	}

	if (getOutput(ETIRPS))
	{
	    GPIOPinWrite(GPIO_PORTF_BASE, ETIRPS_OUT, ETIRPS_OUT);
	    SysCtlDelay(1000000);
	    GPIOPinWrite(GPIO_PORTF_BASE, ETIRPS_OUT, 0);
		auxS = "ETIRPS released.";
		queueP->pushBack(auxS);
	    clearOutput(ETIRPS);
	}
}

/** Pointer used to identy the object instatiated used for ISR purposes*/
CGPIO* CGPIO::current = nullptr;

/**
 * \brief Method to obtain the value of the current pointer.
 * \param none
 * \return CGPIO class pointer
 */
CGPIO* CGPIO::getCurrent(void)
{
    return CGPIO::current;
}

/**
 * \brief Method to set the value of the current pointer.
 * \param gpio class pointer
 * \return none
 */
void CGPIO::setCurrent(CGPIO* gpio)
{
    CGPIO::current = gpio;
}

/**
 * \brief friend function that performs the ISR treatment to read the inputs.
 * \param none
 * \return none
 */
void GPIOISR(void)
{
    int aux;

    SysCtlDelay(300000);
    aux = GPIOIntStatus(GPIO_PORTD_BASE, true);

    switch (aux)
    {
    case M025_IN:
        CGPIO::getCurrent()->setInput(M025);
        GPIOIntClear(GPIO_PORTD_BASE, M025_IN);
        break;
    case M050_IN:
        CGPIO::getCurrent()->setInput(M050);
        GPIOIntClear(GPIO_PORTD_BASE, M050_IN);
        break;
    case M100_IN:
        CGPIO::getCurrent()->setInput(M100);
        GPIOIntClear(GPIO_PORTD_BASE, M100_IN);
        break;
//  case MEET_IN:
//      CGPIO::getCurrent()->setInput(MEET);
//      GPIOIntClear(GPIO_PORTF_BASE, MEET_IN);
//      break;
//    case ETIRPS_IN:
//        setInput(ETIRPS);
//        break;
    case DEV_IN:
        CGPIO::getCurrent()->setInput(DEV);
        GPIOIntClear(GPIO_PORTD_BASE, DEV_IN);
        break;
    default:
        GPIOIntClear(GPIO_PORTD_BASE, 0xFF);
        break;
    }

    aux = GPIOIntStatus(GPIO_PORTF_BASE, true);

    switch (aux)
    {
//    case M025_IN:
//        setInput(M025);
//        break;
//    case M050_IN:
//      CGPIO::getCurrent()->setInput(M050);
//      GPIOIntClear(GPIO_PORTF_BASE, M050_IN);
//        break;
//    case M100_IN:
//        setInput(M100);
//        break;
    case MEET_IN:
        CGPIO::getCurrent()->setInput(MEET);
        GPIOIntClear(GPIO_PORTF_BASE, MEET_IN);
        break;
    case ETIRPS_IN:
        CGPIO::getCurrent()->setInput(ETIRPS);
        GPIOIntClear(GPIO_PORTF_BASE, ETIRPS_IN);
        break;
//    case DEV_IN:
//        setInput(DEV);
//        break;
    default:
        GPIOIntClear(GPIO_PORTF_BASE, 0xFF);
        break;
    }
}


