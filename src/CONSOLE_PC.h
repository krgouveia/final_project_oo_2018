
#ifndef CONSOLE_PC_H
#define CONSOLE_PC_H

#include "TERMINAL.h"
#include "TIME_PC.h"

class CConsole : public CTerminal {
protected:
	CTime* systemClockReference;
public:
	CConsole();
	CConsole(CTime* sysCk);
	~CConsole();
	void writeLogString(string str, bool newLine);
	void writeLogInteger(int num, bool newLine); 
	void ReadCommand(string* str); 
};

#endif