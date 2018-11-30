/**
 * \file SCREEN_PC.h
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 25, 2018
 *
 **************************************************************************
 *
 * Module Name:  SCREEN_PC.h
 *
 * \brief Implements the class to access the LCD using the uC.
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

#ifndef SCREEN_PC_H
#define SCREEN_PC_H

#include "DISPLAY.h"

/** \class CLCD
*	\brief CLCD class implementation.
*	\details This class implements the methods to initialize and access the LCD from the PC's.
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
