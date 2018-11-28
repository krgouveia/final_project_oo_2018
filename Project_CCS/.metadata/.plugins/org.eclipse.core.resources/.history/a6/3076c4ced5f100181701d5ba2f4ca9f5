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

#include "CONTROL.h"
#include "FSM.h"

int main(void)
{
	CControl myControl;
	CFSM myFSM;
	
	while (1)
	{
		myFSM.gpio.readInputs(&myControl.fila_3);
		myFSM.runFSM(&myControl.fila_3);
//		myFSM.gpio.showCredit((int) myFSM.getState());
		myFSM.gpio.writeOutputs(&myControl.fila_3);

		myControl.messageManager();
		myControl.receiveCommand();
		myControl.commandsParser();
	}

	return 0;
}
