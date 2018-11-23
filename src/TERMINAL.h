
#ifndef TERMINAL_H
#define TERMINAL_H

#include <string>
using namespace std;

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
