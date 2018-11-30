/**
 * \file IO.cpp
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 10, 2018
 *
 **************************************************************************
 *
 * Module Name:  IO.cpp
 *
 * \brief Define the class to model the IO interface.
 *
 * \section References
 *
 **************************************************************************
 * \section Revisions
 *
 * Revision: 1.0   10-Nov-2018    Kleber Gouveia
 * * Working baseline.
 *
 ***************************************************************************/


#include "IO.h"

/**
*   \brief Class constructor. 
*/
CIO::CIO()
{
	flags_input = 0;
	flags_output = 0;
}

/**
*   \brief Class destructor. 
*/
CIO::~CIO()
{

}

/**
 * \brief Method to set an input flag.
 * \param flag - Input to be set.
 * \return none
 */
void CIO::setInput(int flag)
{
	flags_input |= flag;
}

/**
 * \brief Method to clear an input flag.
 * \param flag - Input to be cleared.
 * \return none
 */
void CIO::clearInput(int flag)
{
	flags_input &= ~flag;
}

/**
 * \brief Method to get an input flag.
 * \param flag - Input to be got.
 * \return none
 */
bool CIO::getInput(int flag)
{
	return (((flags_input & flag) != 0) ? 1 : 0);
}

/**
 * \brief Method to set an output flag.
 * \param flag - Output to be set.
 * \return none
 */
void CIO::setOutput(int flag)
{
	flags_output |= flag;
}

/**
 * \brief Method to clear an output flag.
 * \param flag - Output to be clared.
 * \return none
 */
void CIO::clearOutput(int flag)
{
	flags_output &= ~flag;
}

/**
 * \brief Method to get an output flag.
 * \param flag - Output to be got.
 * \return none
 */
bool CIO::getOutput(int flag)
{
	return (((flags_output & flag) != 0) ? 1 : 0);
}
