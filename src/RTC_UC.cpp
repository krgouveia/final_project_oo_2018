/**
 * \file RTC_UC.cpp
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 23, 2018
 *
 **************************************************************************
 *
 * Module Name: RTC_UC.cpp
 *
 * \brief Define the class implements the methods to access the Ctime class.
 *
 * \section References
 *
 **************************************************************************
 * \section Revisions
 *
 * Revision: 1.0   23-Nov-2018    Kleber Gouveia
 * * Working baseline.
 *
 ***************************************************************************/

#include "RTC_UC.h"
#include "driverlib\sysctl.h"
#include "driverlib\hibernate.h"

void RTCISR(void);

/**
*   \brief Class constructor. 
*/
CTime::CTime()
{
	systemClock = 0;
	// Enable the Hibernation module.
	SysCtlPeripheralEnable(SYSCTL_PERIPH_HIBERNATE);
	HibernateEnableExpClk(SysCtlClockGet());
	// Wait for the Hibernate module to be ready.
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_HIBERNATE));
//	// Configure the clock source for Hibernation module and enable the RTC feature.
    HibernateClockConfig(HIBERNATE_OSC_HIGHDRIVE);
	// Wait an amount of time for the module to power up.
	SysCtlDelay(1000000);

	// Hib RTC Config
	HibernateRTCSet(0); // load RTC value
	HibernateRTCMatchSet(0,5); // set match value
	HibernateIntEnable(HIBERNATE_INT_RTC_MATCH_0); // En RTC match interrupt
	HibernateRTCTrimSet(0x7FFF);
	HibernateRTCEnable(); // start RTC count

	setCurrent(this);
	HibernateIntRegister(RTCISR);
}

/**
*   \brief Class constructor. 
*/
CTime::CTime(long int sck) : CDateTime(sck)
{

}

/**
*   \brief Class destructor. 
*/
CTime::~CTime()
{

}

/**
 * \brief Method to set the system clock.
 * \param sck - new date/time
 * \return none
 */
void CTime::setSystemClock(long int sck)
{
	systemClock = sck;
}

/**
 * \brief Method to get the system clock.
 * \param none
 * \return actual system time information
 */
long int CTime::getSystemClock()
{
	return systemClock;
}

/**
 * \brief Method to get the system clock as a string. 
 * \param none
 * \return actual system time information
 */
string CTime::getSystemClockString()
{
    string timeS;

    long int time = getSystemClock();
    int s, m, h;
    s = (time / 1000) % 60;
    m = (time / 60000) % 60;
    h = (time / 3600000) % 24;

    timeS = to_string(h) + ":" + to_string(m) + ":" + to_string(s);
    return timeS;
}

/** Pointer used to identy the object instatiated used for ISR purposes*/
CTime* CTime::current = nullptr;

/**
 * \brief Method to obtain the value of the current pointer.
 * \param none
 * \return Ctime class pointer
 */
CTime* CTime::getCurrent()
{
    return CTime::current;
}

/**
 * \brief Method to set the value of the current pointer.
 * \param CTime class pointer
 * \return none
 */
void CTime::setCurrent(CTime* rtc)
{
    CTime::current = rtc;
}
/**
 * \brief friend function that performs the ISR treatment to hibernate module RTC.
 * \param none
 * \return none
 */
void RTCISR(void)
{
	int aux;
	long int rtcValue;
	// Get the interrupt status and clear any pending interrupts.
	aux = HibernateIntStatus(true);
	HibernateIntClear(aux);
	// Process the RTC match 0 interrupt.
	if(aux & HIBERNATE_INT_RTC_MATCH_0)
	{
	    unsigned int RTCMatch;
	    RTCMatch = HibernateRTCGet();
	    HibernateRTCMatchSet(0, RTCMatch + 1);

	    //systemClock++;
	    rtcValue = CTime::getCurrent()->getSystemClock() + 1000;
	    CTime::getCurrent()->setSystemClock(rtcValue);
	}
}
