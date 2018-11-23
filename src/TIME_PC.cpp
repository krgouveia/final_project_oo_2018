
#include "TIME_PC.h"
#include <iostream>
#include <ctime>
using namespace std;

CTime::CTime()
{
	systemClock = 1000 * (static_cast<long int> (time(nullptr)));
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
	//return systemClock;
	return 1000 * (static_cast<long int> (time(nullptr)));
}

string CTime::getSystemClockString()
{
	time_t auxTime;
	char auxS[30];
	int auxI = 0;

	time(&auxTime);
	ctime_s(auxS, 30, &auxTime);
	for (auxI = 0; (auxS[auxI] != '\n') || (auxI >= 30); auxI++);
	auxS[auxI] = ' ';
	
	string str(auxS);
	
	return str;
}

