/**
 * \file CONSOLE_PC.cpp
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 25, 2018
 *
 **************************************************************************
 *
 * Module Name:  CONSOLE_PC.cpp
 *
 * \brief Implements the methods of the CConsole class.
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

#include "CONSOLE_PC.h"
#include <iostream>
#include <conio.h>
#include <windows.h> 

using namespace std;

/**
*   \brief CConsole constructor. This method create a CConsole object instance.
*/
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

/**
*   \brief Class constructor. 
*/
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

/**
 * \brief Class destructor
 */ 
CConsole::~CConsole()
{

}
/**
 * \brief Method to send strings for log information via console.
 * \param str - string to be sent, newLine - if true, send a newLine (\n) 
 * in the end of string. If false, doesn't.
 * \return none
 */
void CConsole::writeLogString(string str, bool newLine)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);

	//is there isn't a systemClock print only the string
	if (systemClockReference == nullptr)
	{
		if (newLine) cout << "[LOG] " << str << endl;
		else cout << str;
	}
	//if there is, print date/time information before the string
	else 
	{
		if (newLine) cout << "[LOG] " << systemClockReference->getSystemClockString() << str << endl;
		else cout << str;
	}
}

/**
 * \brief Method to send integers for log information via console.
 * \param num - number to be sent, newLine - if true, send a newLine (\n) 
 * in the end of string. If false, doesn't.
 * \return none
 */
void CConsole::writeLogInteger(int num, bool newLine)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);

	//is there isn't a systemClock print only the string
	if (systemClockReference == nullptr)
	{
		if (newLine) cout << "[LOG] " << num << endl;
		else cout << num;;
	}
	else
	//if there is, print date/time information before the string
	{
		if (newLine) cout << "[LOG] " << systemClockReference->getSystemClockString() << num << endl;
		else cout << num;
	}
}

/**
 * \briefThis method verifies if there was some valid input from keyboard.
 * If yes, put the input in com.
 * \param com - pointer to char
 * \return Return true if a valid input was received, false if no.
 */
bool CConsole::ReadCommand(char* com)
{
	int aux[2];
	//check if some key was pressed
	if (_kbhit())
	{
		//each key is mapped in two chars, then read them from the buffer
		 aux[0] = _getch();
		 aux[1] = _getch();
		 //check if is a valid key (alphanumeric)
		 if (aux[0] != 0)
		 {
			 *com = aux[0];
			 return true; // Key Was Hit
		 }
		 //if no, the key is a special key (F1, insert, delete home, arrows...)
		 else
		 {
			//then put the chars in de input buffer again.
			 _ungetch(aux[0]);
			 _ungetch(aux[1]);
		 }
	}
	return false; // No keys were pressed
}
