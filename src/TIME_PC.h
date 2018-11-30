/**
 * \file TIME_PC.h
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 23, 2018
 *
 **************************************************************************
 *
 * Module Name: TIME_PC.h
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

#ifndef TIME_PC_H
#define TIME_PC_H

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
};

#endif