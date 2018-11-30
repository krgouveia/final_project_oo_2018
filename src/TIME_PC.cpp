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
 * \brief Implements the methods to access the Ctime class.
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

#include "TIME_PC.h"
#include <iostream>
#include <ctime>
using namespace std;

/**
*   \brief Class constructor. 
*/
CTime::CTime()
{
	systemClock = 1000 * (static_cast<long int> (time(nullptr)));
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
	//return systemClock;
	return 1000 * (static_cast<long int> (time(nullptr)));
}

/**
 * \brief Method to get the system clock as a string. 
 * \param none
 * \return actual system time information
 */
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

