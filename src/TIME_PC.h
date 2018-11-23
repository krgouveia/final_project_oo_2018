#ifndef TIME_PC_H
#define TIME_PC_H

#include "DATE_TIME.h"

class CTime: public CDateTime {
public:
	CTime();
	CTime(long int sck);
	~CTime();
	void setSystemClock(long int sck);
	long int getSystemClock();
	string getSystemClockString();
};

#endif