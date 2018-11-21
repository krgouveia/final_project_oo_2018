/*!
 *  \file       GPIO_UC.cpp
 *  \brief      Implementa��o dos m�todos de acesso a entradas e sa�das do microcontrolador.
 *  \author     Kleber Gouveia
 */

#include "GPIO_UC.h"
#include <iostream>
using namespace std;

#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"

void GPIOISR(void);
/**
*   \brief GPIO_UC constructor.
*   \param
*   \return
*
*   This method create a GPIO_UC object instance.
*/
GPIO_UC::GPIO_UC()
{
    //--Clock
    // Setup the system clock to run at 80 Mhz from PLL with crystal reference
    SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

    //--GPIO
    // Enable and wait for the port to be ready for access
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

    //MEET_IN is a NMI pin and need this procedure to unlock port F to be reconfigured
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= MEET_IN;

    // Configure the GPIO port for outputs.
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, M025_OUT|M050_OUT|M100_OUT|MEET_OUT|ETIRPS_OUT);
    // Configure the GPIO port for inputs.
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, M025_IN|M050_IN|M100_IN|MEET_IN|ETIRPS_IN|DEV_IN);
    // Configure GPIO driver strength and pull-ups
    GPIOPadConfigSet(GPIO_PORTF_BASE, M025_IN|M050_IN|M100_IN|MEET_IN|ETIRPS_IN|DEV_IN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

    /** Configuring GPIO interrupts*/

    // Register the port-level interrupt handler. This handler is the first
    // level interrupt handler for all the pin interrupts.
    setCurrent(this);
    GPIOIntRegister(GPIO_PORTF_BASE, GPIOISR);

    // Set the interrupt type for RISING_EDGE
    GPIOIntTypeSet(GPIO_PORTF_BASE, M025_IN|M050_IN|M100_IN|MEET_IN|ETIRPS_IN|DEV_IN, GPIO_RISING_EDGE);

    // Enabling the GPIOs interrupts
    //GPIOIntEnable(GPIO_PORTF_BASE, M025_IN|M050_IN|M100_IN|MEET_IN|ETIRPS_IN|DEV_IN);
    GPIOIntEnable(GPIO_PORTF_BASE, M050_IN|MEET_IN);

    //lock port F
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;
}

GPIO_UC::~GPIO_UC()
{

}

void GPIO_UC::readInputs()
{

}

void GPIO_UC::writeOutputs()
{
	if (getOutput(M025))
	{
	    GPIOPinWrite(GPIO_PORTF_BASE, M025_OUT, M025_OUT);
	    SysCtlDelay(1000000);
	    GPIOPinWrite(GPIO_PORTF_BASE, M025_OUT, 0);
		clearOutput(M025);
	}

	if (getOutput(M050))
	{
	    GPIOPinWrite(GPIO_PORTF_BASE, M050_OUT, M050_OUT);
	    SysCtlDelay(1000000);
	    GPIOPinWrite(GPIO_PORTF_BASE, M050_OUT, 0);
	    clearOutput(M050);
	}

	if (getOutput(M100))
	{
	    GPIOPinWrite(GPIO_PORTF_BASE, M100_OUT, M100_OUT);
	    SysCtlDelay(1000000);
	    GPIOPinWrite(GPIO_PORTF_BASE, M100_OUT, 0);
	    clearOutput(M100);
	}

	if (getOutput(MEET))
	{
	    GPIOPinWrite(GPIO_PORTF_BASE, MEET_OUT, MEET_OUT);
	    SysCtlDelay(1000000);
	    GPIOPinWrite(GPIO_PORTF_BASE, MEET_OUT, 0);
	    clearOutput(MEET);
	}

	if (getOutput(ETIRPS))
	{
	    GPIOPinWrite(GPIO_PORTF_BASE, ETIRPS_OUT, ETIRPS_OUT);
	    SysCtlDelay(1000000);
	    GPIOPinWrite(GPIO_PORTF_BASE, ETIRPS_OUT, 0);
	    clearOutput(ETIRPS);
	}
}

void GPIO_UC::showCredit(int credit)
{
	credit *= 25;
//	cout << "\nCredito: R$ " << credit / 100 << "," << credit % 100 << endl;
}

GPIO_UC* GPIO_UC::current = nullptr;
GPIO_UC* GPIO_UC::getCurrent()
{
    return GPIO_UC::current;
}

void GPIO_UC::setCurrent(GPIO_UC* gpio)
{
    GPIO_UC::current = gpio;
}

void GPIOISR(void)
{
    int aux;

    SysCtlDelay(300000);
    aux = GPIOIntStatus(GPIO_PORTF_BASE, true);

    switch (aux)
    {
//    case M025_IN:
//        setInput(M025);
//        break;
    case M050_IN:
        GPIO_UC::getCurrent()->setInput(M050);
        GPIOIntClear(GPIO_PORTF_BASE, M050_IN);
        break;
//    case M100_IN:
//        setInput(M100);
//        break;
    case MEET_IN:
        GPIO_UC::getCurrent()->setInput(MEET);
        GPIOIntClear(GPIO_PORTF_BASE, MEET_IN);
        break;
//    case ETIRPS_IN:
//        setInput(ETIRPS);
//        break;
//    case DEV_IN:
//        setInput(DEV);
//        break;
    default:
        GPIOIntClear(GPIO_PORTF_BASE, 0xFF);
        break;
    }
}

/*
void called_from_interrupt()
{
    this->GPIOISR();
}
*/