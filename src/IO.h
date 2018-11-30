/**
 * \file IO.h
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 10, 2018
 *
 **************************************************************************
 *
 * Module Name:  IO.h
 *
 * \brief Define the class to model the IO interface.
 *
 * \section References
 *
 **************************************************************************
 * \section Revisions
 *
 * Revision: 1.0   10-Nov-2018    Kleber Gouveia
 * * Working baseline.
 *
 ***************************************************************************/

#include <string>
#include "queue.hpp"
using namespace std;

#ifndef IO_H
#define IO_H

//IO masks
#define M025	0x01    /** R$0,25 coin*/
#define M050	0x02    /** R$0,50 coin*/
#define M100	0x04    /** R$1,00 coin*/
#define MEET	0x08    /** Refrigentante MEET Soda*/
#define ETIRPS	0x10    /** Refrigerante ETIRPS Soda*/
#define DEV		0x20    /** Devolution*/

/** \class CIO
*	\brief System's IO class implementation.
*	\details This class implements the virtual methods to access the IOs.
*/
class CIO {
protected:
	int flags_input;
	int flags_output;
public:
	CIO();
	~CIO();
	void setInput(int flag);
	void clearInput(int flag);
	bool getInput(int flag);
	void setOutput(int flag);
	void clearOutput(int flag);
	bool getOutput(int flag);
	virtual void readInputs(Cqueue<string>* queueP) = 0;
	virtual void writeOutputs(Cqueue<string>* queueP) = 0;
};

#endif
