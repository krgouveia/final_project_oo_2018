/*!
 *  \file       FSM.cpp
 *  \brief      Implementação dos métodos de controle da máquina de estados que gerencia a vending machine.
 *  \author     Kleber Gouveia
 */

#include "FSM.h"

CFSM::CFSM()
{
	state = S000;
}

CFSM::~CFSM()
{

}

void CFSM::changeState(FSMstate_t newState)
{
	state = newState;
}

FSMstate_t CFSM::getState()
{
	return state;
}

void CFSM::runFSM(Cqueue<string>* queueP)
{
	string auxS;
	
	switch (state)
	{
		case S000:
			if (gpio.getInput(M025))
			{
				changeState(S025);
				auxS = "Balance: R$ 0,25";
				queueP->pushBack(auxS);
				gpio.clearInput(M025);
			}
			if (gpio.getInput(M050))
			{
				changeState(S050);
				auxS = "Balance: R$ 0,50";
				queueP->pushBack(auxS);
				gpio.clearInput(M050);
			}
			if (gpio.getInput(M100))
			{
				changeState(S100);
				auxS = "Balance: R$ 1,00";
				queueP->pushBack(auxS);
				gpio.clearInput(M100);
			}
			if (gpio.getInput(DEV))
			{
				changeState(S000);
				auxS = "Balance: R$ 0,00";
				queueP->pushBack(auxS);
				gpio.clearInput(DEV);
			}
			if (gpio.getInput(MEET))
			{
				gpio.clearInput(MEET);
			}
			if (gpio.getInput(ETIRPS))
			{
				gpio.clearInput(ETIRPS);
			}
			break;

		case S025:
			if (gpio.getInput(M025))
			{
				changeState(S050);
				auxS = "Balance: R$ 0,50";
				queueP->pushBack(auxS);
				gpio.clearInput(M025);
			}
			if (gpio.getInput(M050))
			{
				changeState(S075);
				auxS = "Balance: R$ 0,75";
				queueP->pushBack(auxS);
				gpio.clearInput(M050);
			}
			if (gpio.getInput(M100))
			{
				changeState(S125);
				auxS = "Balance: R$ 1,25";
				queueP->pushBack(auxS);
				gpio.clearInput(M100);
			}
			if (gpio.getInput(DEV))
			{
				changeState(S000);
				auxS = "Balance: R$ 0,00";
				queueP->pushBack(auxS);
				gpio.clearInput(DEV);
				gpio.setOutput(M025);
			}
			if (gpio.getInput(MEET))
			{
				gpio.clearInput(MEET);
			}
			if (gpio.getInput(ETIRPS))
			{
				gpio.clearInput(ETIRPS);
			}
			break;

		case S050:
			if (gpio.getInput(M025))
			{
				changeState(S075);
				auxS = "Balance: R$ 0,75";
				queueP->pushBack(auxS);
				gpio.clearInput(M025);
			}
			if (gpio.getInput(M050))
			{
				changeState(S100);
				auxS = "Balance: R$ 1,00";
				queueP->pushBack(auxS);
				gpio.clearInput(M050);
			}
			if (gpio.getInput(M100))
			{
				changeState(S150);
				auxS = "Balance: R$ 1,50";
				queueP->pushBack(auxS);
				gpio.clearInput(M100);
			}
			if (gpio.getInput(DEV))
			{
				changeState(S000);
				auxS = "Balance: R$ 0,00";
				queueP->pushBack(auxS);
				gpio.clearInput(DEV);
				gpio.setOutput(M050);
			}
			if (gpio.getInput(MEET))
			{
				gpio.clearInput(MEET);
			}
			if (gpio.getInput(ETIRPS))
			{
				gpio.clearInput(ETIRPS);
			}
			break;

		case S075:
			if (gpio.getInput(M025))
			{
				changeState(S100);
				auxS = "Balance: R$ 1,00";
				queueP->pushBack(auxS);
				gpio.clearInput(M025);
			}
			if (gpio.getInput(M050))
			{
				changeState(S125);
				auxS = "Balance: R$ 1,25";
				queueP->pushBack(auxS);
				gpio.clearInput(M050);
			}
			if (gpio.getInput(M100))
			{
				changeState(S150);
				auxS = "Balance: R$ 1,50";
				queueP->pushBack(auxS);
				gpio.clearInput(M100);
				gpio.setOutput(M025);
			}
			if (gpio.getInput(DEV))
			{
				changeState(S000);
				auxS = "Balance: R$ 0,00";
				queueP->pushBack(auxS);
				gpio.clearInput(DEV);
				gpio.setOutput(M025);
				gpio.setOutput(M050);
			}
			if (gpio.getInput(MEET))
			{
				gpio.clearInput(MEET);
			}
			if (gpio.getInput(ETIRPS))
			{
				gpio.clearInput(ETIRPS);
			}
			break;

		case S100:
			if (gpio.getInput(M025))
			{
				changeState(S125);
				auxS = "Balance: R$ 1,25";
				queueP->pushBack(auxS);
				gpio.clearInput(M025);
			}
			if (gpio.getInput(M050))
			{
				changeState(S150);
				auxS = "Balance: R$ 1,50";
				queueP->pushBack(auxS);
				gpio.clearInput(M050);
			}
			if (gpio.getInput(M100))
			{
				changeState(S150);
				auxS = "Balance: R$ 1,50";
				queueP->pushBack(auxS);
				gpio.clearInput(M100);
				gpio.setOutput(M050);
			}
			if (gpio.getInput(DEV))
			{
				changeState(S000);
				auxS = "Balance: R$ 0,00";
				queueP->pushBack(auxS);
				gpio.clearInput(DEV);
				gpio.setOutput(M100);
			}
			if (gpio.getInput(MEET))
			{
				gpio.clearInput(MEET);
			}
			if (gpio.getInput(ETIRPS))
			{
				gpio.clearInput(ETIRPS);
			}
			break;

		case S125:
			if (gpio.getInput(M025))
			{
				changeState(S150);
				auxS = "Balance: R$ 1,50";
				queueP->pushBack(auxS);
				gpio.clearInput(M025);
			}
			if (gpio.getInput(M050))
			{
				changeState(S150);
				auxS = "Balance: R$ 1,50";
				queueP->pushBack(auxS);
				gpio.clearInput(M050);
				gpio.setOutput(M025);
			}
			if (gpio.getInput(M100))
			{
				changeState(S150);
				auxS = "Balance: R$ 1,50";
				queueP->pushBack(auxS);
				gpio.clearInput(M100);
				gpio.setOutput(M025);
				gpio.setOutput(M050);
			}
			if (gpio.getInput(DEV))
			{
				changeState(S000);
				auxS = "Balance: R$ 0,00";
				queueP->pushBack(auxS);
				gpio.clearInput(DEV);
				gpio.setOutput(M025);
				gpio.setOutput(M100);
			}
			if (gpio.getInput(MEET))
			{
				gpio.clearInput(MEET);
			}
			if (gpio.getInput(ETIRPS))
			{
				gpio.clearInput(ETIRPS);
			}
			break;

		case S150:
			if (gpio.getInput(M025))
			{
				gpio.clearInput(M025);
				gpio.setOutput(M025);
			}
			if (gpio.getInput(M050))
			{
				gpio.clearInput(M050);
				gpio.setOutput(M050);
			}
			if (gpio.getInput(M100))
			{
				gpio.clearInput(M100);
				gpio.setOutput(M100);
			}
			if (gpio.getInput(DEV))
			{
				changeState(S000);
				auxS = "Balance: R$ 0,00";
				queueP->pushBack(auxS);
				gpio.clearInput(DEV);
				gpio.setOutput(M050);
				gpio.setOutput(M100);
			}
			if (gpio.getInput(MEET))
			{
				changeState(S000);
				auxS = "Balance: R$ 0,00";
				queueP->pushBack(auxS);
				gpio.clearInput(MEET);
				gpio.setOutput(MEET);
			}
			if (gpio.getInput(ETIRPS))
			{
				changeState(S000);
				auxS = "Balance: R$ 0,00";
				queueP->pushBack(auxS);
				gpio.clearInput(ETIRPS);
				gpio.setOutput(ETIRPS);
			}
			break;
	}
}
