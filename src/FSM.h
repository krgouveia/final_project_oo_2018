/**
 * \file FSM.h
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 10, 2018
 *
 **************************************************************************
 *
 * Module Name:  FSM.h
 *
 * \brief Define the class to control the finite machine state of the vending machine.
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

 #ifndef FSM_H
#define FSM_H

#ifdef ARM_PLATFORM
#include "GPIO_UC.h"
#endif
#ifdef PC_PLATFORM
#include "GPIO_PC.h"
#endif

#include <string>
using namespace std;

/**Data type of the machine states*/
typedef enum FSMstate {S000 = 0, S025, S050, S075, S100, S125, S150} FSMstate_t;

/** \class CFSM
*	\brief System's CFSM class implementation.
*	\details This class implements the methods to run the FSM.
*/
class CFSM {
protected:
	FSMstate_t state;
public:
	CGPIO gpio;
public:
	CFSM();
	~CFSM();
	void changeState(FSMstate_t newState);
	FSMstate_t getState();
	void runFSM(Cqueue<string>* queueP);
};

#endif
