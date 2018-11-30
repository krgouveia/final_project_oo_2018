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
 * \brief Provides main function
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
	//Creates the object Control
	CControl myControl;
	//Creates the object FSM
	CFSM myFSM;
	
	//Main loop
	while (1)
	{
		//Performs the input read
		myFSM.gpio.readInputs(&myControl.fila_3);
		//Executes the FSM algorithm
		myFSM.runFSM(&myControl.fila_3);
		//Refresh the outputs
		myFSM.gpio.writeOutputs(&myControl.fila_3);

		//Executes the logic to show messages in the display
		myControl.messageManager();
		//Puts in the commands queue the commands received via terminal
		myControl.receiveCommand();
		//Consumes the commands from commands queue an executes the actions
		myControl.commandsParser();
	}

	return 0;
}
