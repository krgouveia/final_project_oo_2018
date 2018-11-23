#ifndef SCREEN_PC_H
#define SCREEN_PC_H

#include "DISPLAY.h"

class CLCD : public CDisplay {
public:
	CLCD();
	~CLCD();
	void clearScreen();
	void writeString(string str);
	void writeInteger(int num);
	void setPosition(int x, int y);
};

#endif