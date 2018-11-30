/**
 * \file TERMINAL.h
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 22, 2018
 *
 **************************************************************************
 *
 * Module Name:  TERMINAL.h
 *
 * \brief Define the class to model the IO interface.
 *
 * \section References
 *
 **************************************************************************
 * \section Revisions
 *
 * Revision: 1.0   22-Nov-2018    Kleber Gouveia
 * * Working baseline.
 *
 ***************************************************************************/

#ifndef TERMINAL_H
#define TERMINAL_H

#include <string>
using namespace std;

/** \class CTerminal
*	\brief System's Terminal class implementation.
*	\details This class implements the virtual methods to access the terminal.
*/
class CTerminal {
protected:

public:
	CTerminal();
	~CTerminal();
	virtual void writeLogString(string str, bool newLine) = 0;
	virtual void writeLogInteger(int num, bool newLine) = 0;
	virtual bool ReadCommand(char* com) = 0;
};

#endif
