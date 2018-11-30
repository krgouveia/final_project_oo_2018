/**
 * \file CONSOLE_PC.h
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 25, 2018
 *
 **************************************************************************
 *
 * Module Name:  CONSOLE_PC.h
 *
 * \brief Define the class CConsole to send log information and receive commands.
 *
 * \section References
 *
 **************************************************************************
 * \section Revisions
 *
 * Revision: 1.0   25-Nov-2018    Kleber Gouveia
 * * Working baseline.
 *
 ***************************************************************************/

#ifndef CONSOLE_PC_H
#define CONSOLE_PC_H

#include "TERMINAL.h"
#include "TIME_PC.h"

/** \class CConsole
*	\brief PC's CConsole class implementation.
*	\details This class implements the methods to initialize and access a command line interface.
*/

class CConsole : public CTerminal {
protected:
	CTime* systemClockReference;
public:
	CConsole();
	CConsole(CTime* sysCk);
	~CConsole();
	void writeLogString(string str, bool newLine);
	void writeLogInteger(int num, bool newLine); 
	bool ReadCommand(char* com); 
};

#endif
