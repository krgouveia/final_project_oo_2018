/**
 * \file DATE_TIME.cpp
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 23, 2018
 *
 **************************************************************************
 *
 * Module Name:  DATE_TIME.cpp
 *
 * \brief Implements the methods of the CDateTime class.
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

#include "DATE_TIME.h"
/**
*   \brief Class constructor. 
*/
CDateTime::CDateTime()
{

}

/**
*   \brief Class constructor. 
*/
CDateTime::CDateTime(long int sck)
{
	systemClock = sck;
}

/**
 * \brief Class destructor
 */ 
CDateTime::~CDateTime()
{

}
