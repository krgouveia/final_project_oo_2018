/*!
 *  \file       FSM.h
 *  \brief      Defini��o da classe de ccontrole da m�quina de estados que gerencia a vending machine.
 *  \author     Kleber Gouveia
 */

#ifndef FSM_H
#define FSM_H

#include "GPIO_UC.h"

typedef enum FSMstate {S000 = 0, S025, S050, S075, S100, S125, S150} FSMstate_t;


class CFSM {
protected:
	FSMstate_t state;
public:
	GPIO_UC gpio;
public:
	CFSM();
	~CFSM();
	void changeState(FSMstate_t newState);
	FSMstate_t getState();
	void runFSM();
};

#endif