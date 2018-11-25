
#include "SCREEN_PC.h"
#include <iostream>
#include <windows.h> 
using namespace std;

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

CLCD::~CLCD()
{

}

void CLCD::clearScreen()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);

	system("CLS");
}

void CLCD::writeString(string str)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);

	cout << "[LCD] " << str << endl;
}

void CLCD::writeInteger(int num)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);

	cout << "[LCD] " << num << endl;
}

void CLCD::setPosition(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);
}
