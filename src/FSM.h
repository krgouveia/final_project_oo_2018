/*!
 *  \file       FSM.h
 *  \brief      Definição da classe de ccontrole da máquina de estados que gerencia a vending machine.
 *  \author     Kleber Gouveia
 */

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

typedef enum FSMstate {S000 = 0, S025, S050, S075, S100, S125, S150} FSMstate_t;

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
