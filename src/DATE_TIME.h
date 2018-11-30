/**
 * \file DATE_TIME.h
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 23, 2018
 *
 **************************************************************************
 *
 * Module Name:  DATE_TIME.h
 *
 * \brief Define the class to model the system time.
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

#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <string>
using namespace std;

/** \class CDateTime
*	\brief System's CDateTime class implementation.
*	\details This class implements the virtual methods to access the system time.
*/
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
