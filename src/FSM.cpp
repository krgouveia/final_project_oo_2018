/*!
 *  \file       FSM.cpp
 *  \brief      Implementa��o dos m�todos de controle da m�quina de estados que gerencia a vending machine.
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

void CFSM::runFSM()
{
	switch (state)
	{
		case S000:
			if (gpio.getInput(M025))
			{
				changeState(S025);
				gpio.clearInput(M025);
			}
			if (gpio.getInput(M050))
			{
				changeState(S050);
				gpio.clearInput(M050);
			}
			if (gpio.getInput(M100))
			{
				changeState(S100);
				gpio.clearInput(M100);
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
				gpio.clearInput(M025);
			}
			if (gpio.getInput(M050))
			{
				changeState(S075);
				gpio.clearInput(M050);
			}
			if (gpio.getInput(M100))
			{
				changeState(S125);
				gpio.clearInput(M100);
			}
			if (gpio.getInput(DEV))
			{
				changeState(S000);
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
				gpio.clearInput(M025);
			}
			if (gpio.getInput(M050))
			{
				changeState(S100);
				gpio.clearInput(M050);
			}
			if (gpio.getInput(M100))
			{
				changeState(S150);
				gpio.clearInput(M100);
			}
			if (gpio.getInput(DEV))
			{
				changeState(S000);
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
				gpio.clearInput(M025);
			}
			if (gpio.getInput(M050))
			{
				changeState(S125);
				gpio.clearInput(M050);
			}
			if (gpio.getInput(M100))
			{
				changeState(S150);
				gpio.clearInput(M100);
				gpio.setOutput(M025);
			}
			if (gpio.getInput(DEV))
			{
				changeState(S000);
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
				gpio.clearInput(M025);
			}
			if (gpio.getInput(M050))
			{
				changeState(S150);
				gpio.clearInput(M050);
			}
			if (gpio.getInput(M100))
			{
				changeState(S150);
				gpio.clearInput(M100);
				gpio.setOutput(M050);
			}
			if (gpio.getInput(DEV))
			{
				changeState(S000);
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
				gpio.clearInput(M025);
			}
			if (gpio.getInput(M050))
			{
				changeState(S150);
				gpio.clearInput(M050);
				gpio.setOutput(M025);
			}
			if (gpio.getInput(M100))
			{
				changeState(S150);
				gpio.clearInput(M100);
				gpio.setOutput(M025);
				gpio.setOutput(M050);
			}
			if (gpio.getInput(DEV))
			{
				changeState(S000);
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
				gpio.clearInput(DEV);
				gpio.setOutput(M050);
				gpio.setOutput(M100);
			}
			if (gpio.getInput(MEET))
			{
				changeState(S000);
				gpio.clearInput(MEET);
				gpio.setOutput(MEET);
			}
			if (gpio.getInput(ETIRPS))
			{
				changeState(S000);
				gpio.clearInput(ETIRPS);
				gpio.setOutput(ETIRPS);
			}
			break;
	}
}