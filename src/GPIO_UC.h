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

#define M025_IN     GPIO_PIN_0 //PD0
#define M050_IN     GPIO_PIN_1 //PD1
#define M100_IN     GPIO_PIN_2 //PD2
#define MEET_IN     GPIO_PIN_4 //PF4 - SW1 onboard
#define ETIRPS_IN   GPIO_PIN_0 //PF0 - SW2 onboard
#define DEV_IN      GPIO_PIN_3 //PD3

#define M025_OUT    GPIO_PIN_1 //PE1
#define M050_OUT    GPIO_PIN_2 //PE2
#define M100_OUT    GPIO_PIN_3 //PE3
#define MEET_OUT    GPIO_PIN_1 //PF1 - LED_red onboard
#define ETIRPS_OUT  GPIO_PIN_2 //PF2 - LED_blue onboard

/** \class CGPIO
*	\brief uC's CGPIO class implementation.
*	\details This class implements the methods to initialize and access the microcontroller's GPIO.
*/

class CGPIO : public CIO {
public:
	CGPIO();
	~CGPIO();
	void readInputs(Cqueue<string>* queueP);
	void writeOutputs(Cqueue<string>* queueP);
	friend void GPIOISR();
protected:
	static CGPIO* current;
	static CGPIO* getCurrent(void);
	static void setCurrent(CGPIO* gpio);
};

#endif
