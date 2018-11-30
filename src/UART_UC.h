/**
 * \file UART_UC.h
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 28, 2018
 *
 **************************************************************************
 *
 * Module Name:  UART_UC.h
 *
 * \brief Define the class CConsole to send log information and receive commands.
 *
 * \section References
 *
 **************************************************************************
 * \section Revisions
 *
 * Revision: 1.0   28-Nov-2018    Kleber Gouveia
 * * Working baseline.
 *
 ***************************************************************************/

#ifndef UART_UC_H
#define UART_UC_H

#include "TERMINAL.h"
#include "RTC_UC.h"

/** \class CConsole
*	\brief UC's CConsole class implementation.
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
