/**
 * \file LCD_UC.h
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 27, 2018
 *
 **************************************************************************
 *
 * Module Name:  LCD_UC.h
 *
 * \brief Implements the class to access the LCD using the uC.
 *
 * \section References
 *
 **************************************************************************
 * \section Revisions
 *
 * Revision: 1.0   27-Nov-2018    Kleber Gouveia
 * * Working baseline.
 *
 ***************************************************************************/

#ifndef LCD_UC_H
#define LCD_UC_H

#include "DISPLAY.h"

/** \class CLCD
*	\brief CLCD class implementation.
*	\details This class implements the methods to initialize and access the LCD from the microcontroller's GPIO.
*/
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
