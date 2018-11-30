/**
 * \file DISPLAY.h
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 22, 2018
 *
 **************************************************************************
 *
 * Module Name:  DISPLAY.h
 *
 * \brief Define the class to model the display interface.
 *
 * \section References
 *
 **************************************************************************
 * \section Revisions
 *
 * Revision: 1.0   22-Nov-2018    Kleber Gouveia
 * * Working baseline.
 *
 ***************************************************************************/

#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
using namespace std;

/** \class CDisplay
*	\brief System's Display class implementation.
*	\details This class implements the virtual methods to access the display.
*/
class CDisplay {
protected:

public:
	CDisplay();
	~CDisplay();
	virtual void clearScreen() = 0;
	virtual void writeString(string str) = 0;
	virtual void writeInteger(int num) = 0;
	virtual void setPosition(int x, int y) = 0;
};

#endif
