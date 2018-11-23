
#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <string>
using namespace std;

class CDateTime {
protected:
	long int systemClock; //miliseconds elapsed since 00:00 hours, Jan 1, 1970 UTC (i.e., a unix timestamp)
public:
	CDateTime();
	CDateTime(long int sck);
	~CDateTime();
	virtual void setSystemClock(long int sck) = 0;
	virtual long int getSystemClock() = 0;
	virtual string getSystemClockString() = 0;
};

#endif
