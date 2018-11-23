
#include "CONSOLE_PC.h"
#include <iostream>

using namespace std;

CConsole::CConsole()
{
	systemClockReference = nullptr;
	cout << "[LOG] Console running!" << endl;
}

CConsole::CConsole(CTime* sysCk)
{
	systemClockReference = sysCk;
	cout << "[LOG] " << sysCk->getSystemClockString() << "Console running!" << endl;
}

CConsole::~CConsole()
{

}

void CConsole::writeLogString(string str, bool newLine)
{
	if (systemClockReference == nullptr)
	{
		if (newLine) cout << "[LOG] " << str << endl;
		else cout << str;
	}
	else
	{
		if (newLine) cout << "[LOG] " << systemClockReference->getSystemClockString() << str << endl;
		else cout << str;
	}
}

void CConsole::writeLogInteger(int num, bool newLine)
{
	if (systemClockReference == nullptr)
	{
		if (newLine) cout << "[LOG] " << num << endl;
		else cout << num;;
	}
	else
	{
		if (newLine) cout << "[LOG] " << systemClockReference->getSystemClockString() << num << endl;
		else cout << num;
	}
}

void CConsole::ReadCommand(string* str)
{
	cin >> *str;
}
