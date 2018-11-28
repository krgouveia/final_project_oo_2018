#ifndef RTC_UC_H
#define RTC_UC_H

#include "DATE_TIME.h"

class CTime: public CDateTime {
public:
	CTime();
	CTime(long int sck);
	~CTime();
	void setSystemClock(long int sck);
	long int getSystemClock();
	string getSystemClockString();
	friend void RTCISR();
protected:
    static CTime* current;
    static CTime* getCurrent();
    static void setCurrent(CTime* rtc);
};

#endif
