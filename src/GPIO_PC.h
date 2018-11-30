/**
 * \file GPIO_PC.h
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 10, 2018
 *
 **************************************************************************
 *
 * Module Name:  GPIO_PC.h
 *
 * \brief Define the class for access the PC's IOs.
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

#ifndef GPIO_PC_H
#define GPIO_PC_H

#include "IO.h"

/** \class CGPIO
*	\brief PC's CGPIO class implementation.
*	\details This class implements the methods to initialize and access the PC's GPIO.
*/
class CGPIO : public CIO {
public:
	CGPIO();
	~CGPIO();
	void readInputs(Cqueue<string>* queueP);
	void writeOutputs(Cqueue<string>* queueP);
};

#endif
