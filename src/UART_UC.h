
#ifndef UART_UC_H
#define UART_UC_H

#include "TERMINAL.h"
#include "RTC_UC.h"

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
