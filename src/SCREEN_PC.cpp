/**
 * \file SCREEN_PC.cpp
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 25, 2018
 *
 **************************************************************************
 *
 * Module Name:  SCREEN_PC.cpp
 *
 * \brief Implements the methods of the CLCD class.
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

#include "SCREEN_PC.h"
#include <iostream>
#include <windows.h> 
using namespace std;

/**
*   \brief Class constructor. 
*/
CLCD::CLCD()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);

	cout << "[LCD] Display running!" << endl;
	cout << endl;
	cout << "************ Instructions ***********" << endl;
	cout << "F1 - Insert R$0,25." << endl;
	cout << "F2 - Insert R$0,50." << endl;
	cout << "F3 - Insert R$1,00." << endl;
	cout << "F4 - Select MEET." << endl;
	cout << "F5 - Select ETIRPS." << endl;
	cout << "F6 - Return money." << endl;
	cout << "*************************************" << endl << endl;
}

/**
*   \brief Class destructor. 
*/
CLCD::~CLCD()
{

}

 /**
 * \brief Method to clear the entire LCD
 * \param none
 * \return none
 */
void CLCD::clearScreen()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);

	system("CLS");
}

 /**
 * \brief Method to write a string in the LCD
 * \param str - string to write
 * \return none
 */
void CLCD::writeString(string str)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);

	cout << "[LCD] " << str << endl;
}

 /**
 * \brief Method to write a number in the LCD
 * \param num - number to write
 * \return none
 */
void CLCD::writeInteger(int num)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);

	cout << "[LCD] " << num << endl;
}

 /**
 * \brief Method to the position to write in LCD
 * \param x - is the column
 * \param y - is the page
 * \return none
 */
void CLCD::setPosition(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);
}
