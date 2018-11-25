
#include "CONSOLE_PC.h"
#include <iostream>
#include <conio.h>
#include <windows.h> 

using namespace std;

CConsole::CConsole()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);

	systemClockReference = nullptr;

	cout << "[LOG] Console running!" << endl;
	cout << endl;
	cout << "*********** Commands list ***********" << endl;
	cout << "=h - to show commands list." << endl;
	cout << "=n";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "<string>";
	SetConsoleTextAttribute(hConsole, 12);
	cout << "; - to insert new messages. <string> is the message to be inserted." << endl;
	cout << "=t - to enable new messages to be shown." << endl;
	cout << "=r - to remove last message shown." << endl;
	cout << "*************************************" << endl << endl;
}

CConsole::CConsole(CTime* sysCk)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);

	systemClockReference = sysCk;

	cout << "[LOG] " << sysCk->getSystemClockString() << "Console running!" << endl;
	cout << "[LOG] Console running!" << endl;
	cout << endl;
	cout << "*********** Commands list ***********" << endl;
	cout << "=h - to show commands list." << endl;
	cout << "=n";
	SetConsoleTextAttribute(hConsole, 15);
	cout << "<string>";
	SetConsoleTextAttribute(hConsole, 12);
	cout << "; - to insert new messages. <string> is the message to be inserted." << endl;
	cout << "=t - to enable new messages to be shown." << endl;
	cout << "=r - to remove last message shown." << endl;
	cout << "*************************************" << endl << endl;
}

CConsole::~CConsole()
{

}

void CConsole::writeLogString(string str, bool newLine)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);

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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);

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
	int aux[2];

	if (_kbhit())
	{
		 aux[0] = _getch();
		 aux[1] = _getch();
		 if (aux[0] != 0)
		 {
			 *com = aux[0];
			 return true; // Key Was Hit
		 }
		 else
		 {
			 _ungetch(aux[0]);
			 _ungetch(aux[1]);
		 }
	}
	return false; // No keys were pressed
}
