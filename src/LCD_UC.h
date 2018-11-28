#ifndef LCD_UC_H
#define LCD_UC_H

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