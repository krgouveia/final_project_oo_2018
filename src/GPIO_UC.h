/**
 * \file GPIO_UC.h
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 10, 2018
 *
 **************************************************************************
 *
 * Module Name:  GPIO_UC.h
 *
 * \brief Define the class for access the microncontroller's IOs.
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

#ifndef GPIO_UC_H
#define GPIO_UC_H

#include "IO.h"

#define M025_IN     0
#define M050_IN     GPIO_PIN_4 //SW1
#define M100_IN     0
#define MEET_IN     GPIO_PIN_0 //SW2
#define ETIRPS_IN   0
#define DEV_IN      0

#define M025_OUT    GPIO_PIN_3 //LED_green
#define M050_OUT    GPIO_PIN_3 //LED_green
#define M100_OUT    GPIO_PIN_3 //LED_green
#define MEET_OUT    GPIO_PIN_1 //LED_red
#define ETIRPS_OUT  GPIO_PIN_2 //LED_blue

/** \class GPIO_UC
*	\brief uC's GPIO class implementation.
*	\details This class implements the methods to initialize and access the microcontroller's GPIO.
*/

class GPIO_UC : public CIO {
public:
	GPIO_UC();
	~GPIO_UC();
	void readInputs();
	void writeOutputs();
	void showCredit(int credit);
	friend void GPIOISR();
protected:
	static GPIO_UC* current;
	static GPIO_UC* getCurrent();
	static void setCurrent(GPIO_UC* gpio);
};
//extern "C" void called_from_interrupt();
#endif
