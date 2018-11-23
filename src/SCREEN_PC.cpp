
#include "SCREEN_PC.h"
#include <iostream>
using namespace std;

CLCD::CLCD()
{
	cout << "[LCD] Display running!" << endl;
}

CLCD::~CLCD()
{

}

void CLCD::clearScreen()
{
	system("CLS");
}

void CLCD::writeString(string str)
{
	cout << "[LCD] " << str << endl;
}

void CLCD::writeInteger(int num)
{
	cout << "[LCD] " << num << endl;
}

void CLCD::setPosition(int x, int y)
{
	
}
