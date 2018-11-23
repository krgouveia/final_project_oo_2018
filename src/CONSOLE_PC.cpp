
#include "CONSOLE_PC.h"
#include <iostream>
#include <conio.h>


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

bool CConsole::ReadCommand(char* com)
{
	if (_kbhit())
	{
		*com = _getch();
		_getch();
		return true; // Key Was Hit
	}
	return false; // No keys were pressed
}
