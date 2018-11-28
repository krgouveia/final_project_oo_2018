
#include "RTC_UC.h"
#include "driverlib\sysctl.h"
#include "driverlib\hibernate.h"

void RTCISR(void);

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

CTime::CTime(long int sck) : CDateTime(sck)
{

}

CTime::~CTime()
{

}

void CTime::setSystemClock(long int sck)
{
	systemClock = sck;
}

long int CTime::getSystemClock()
{
	return systemClock;
}

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

CTime* CTime::current = nullptr;
CTime* CTime::getCurrent()
{
    return CTime::current;
}

void CTime::setCurrent(CTime* rtc)
{
    CTime::current = rtc;
}

// Handler for hibernate interrupts.
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
