/**
 * \file main.cpp
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 10, 2018
 *
 **************************************************************************
 *
 * Module Name:  main.c
 *
 * \brief: Provides main function
 *
 * \section References
 *
 **************************************************************************
 * \section Rev
 *
 * Revision: 1.0   10-Nov-2018    Kleber Gouveia
 * * Working baseline.
 *
 ***************************************************************************/

#include "FSM.h"

int main(void)
{
	CFSM myFSM;
	
	while (1)
	{
		myFSM.gpio.readInputs();
		myFSM.runFSM();
		myFSM.gpio.showCredit((int) myFSM.getState());
		myFSM.gpio.writeOutputs();
	}

	return 0;
}
