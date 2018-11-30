/**
 * \file RTC_UC.h
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 23, 2018
 *
 **************************************************************************
 *
 * Module Name: RTC_UC.h
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

#ifndef RTC_UC_H
#define RTC_UC_H

#include "DATE_TIME.h"

/** \class Ctime
*	\brief UC's Ctime class implementation.
*	\details This class implements the methods to initialize and access a system clock.
*/
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
