/**
 * \file test_messages.cpp
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 21, 2018
 *
 **************************************************************************
 *
 * Module Name:  test_messages.cpp
 *
 * \brief Main program to test the messages according the project's requirements.
 *
 * \section References
 *
 **************************************************************************
 * \section Revisions
 *
 * Revision: 1.0   21-Nov-2018    Kleber Gouveia
 * * Working baseline.
 *
 ***************************************************************************/

#include <string>
#include <conio.h>
#include <cstdlib>

#include "queue.hpp"
#include "SCREEN_PC.h"
#include "CONSOLE_PC.h"
#include "TIME_PC.h"

using namespace std;

#define TIME_BTW_MSGS		2 //time between messages shown on display in seconds
#define TIME_BTW_CK_DATE	1 //duration of data/time information shown on diaplay is seconds

bool getInput(char *c);

// get input from key board
bool getInput(char *c)
{
	if (_kbhit())
	{
		*c = _getch();
		_getch();
		return true; // Key Was Hit
	}
	return false; // No keys were pressed
}

int main(void)
{
	//auxilary variables
	string auxS;
	int auxI;
	char key_pressed;
	int i;
	long int last_time, actual_time;
	int msgCounter = 3;

	//instantiating the queues
	Cqueue<string>	fila_1, //advertising to be shown in display
					fila_2, //new advertising stored
					fila_3;	//advertising sent from the user 

	//instantiating the system real timer clock
	CTime systemRTC;

	//instantiating the console
	CConsole console(&systemRTC);

	//instantiating the LCD
	CLCD LCD;

//lets suppose that the user can send commands containing new messages 
//to be shown in display. These commands feed the display's process
//throgh the queue "fila_2". For simplicity, we don't want to implement
//the "command's parser" module, then we will use the "fila_3" to simulate
//the commands sent from the user to add a message into "fila_2" using 
//the code lines below.

	//filling fila_3
	fila_3.pushBack("MSG 1");
	fila_3.pushBack("MSG 2");
	fila_3.pushBack("MSG 3");
	fila_3.pushBack("MSG 4");
	fila_3.pushBack("MSG 5");
	fila_3.pushBack("MSG 6");
	fila_3.pushBack("MSG 7");
	fila_3.pushBack("MSG 8");
	fila_3.pushBack("MSG 9");
	fila_3.pushBack("MSG 10");

	//get a timestamp;
	last_time = systemRTC.getSystemClock();

	//message manager loop
	while (1)
	{
		//get actual timestamp
		actual_time = systemRTC.getSystemClock();

		//check if it's time to show a new information on display
		if (actual_time >= (last_time + TIME_BTW_MSGS))
		{
			//check if it's time to show date/time information on display
			if (msgCounter <= 0)
			{
				//delays the time to show a new message 
				last_time += TIME_BTW_CK_DATE;

				//defines new random interval to show date/time information again
				msgCounter = rand() % 3 + 3;
				//log action
				console.writeLogString("New msgCounter value defined:", true);
				console.writeLogInteger(msgCounter, true);

				//print date/time
				LCD.writeString(systemRTC.getSystemClockString());
			}
			//then it's time to show a new message
			else
			{
				//get a new timestamp
				last_time = actual_time;

				//decrement de message counter to indicate the moment to show data/time information on display
				msgCounter--;

				//print message on display
				if (fila_1.checkEmpty())
				{
					//there is no messages stored to display
					LCD.writeString("No messages to display");
				}
				else
				{
					//get message from begin of fila_1
					auxS = fila_1.popFront();
					//write message into display
					LCD.writeString(auxS);
					//return message to the end of fila_1
					fila_1.pushBack(auxS);
				}
			}
		}

		//commands logic
		if (getInput(&key_pressed))
		{
			//"insert" new message into fila_2
			if (key_pressed == 'n')
			{
				//log action
				console.writeLogString("New message received", true);				fila_2.pushBack(fila_3.popFront());
			}
			//transfer messages from fila_2 to fila_1
			if ((key_pressed == 't'))
			{
				auxI = fila_2.getSize();
				if (auxI > 0)
				{
					//log action
					console.writeLogString("Transfering messages from queue 2 to queue 1", true);
					for (i = 0; i < auxI; i++)
					{
						fila_1.pushBack(fila_2.popFront());
						//log action
						console.writeLogString("1 message transfered to queue 2", true);
					}
				}	
				else
				{
					//log action
					console.writeLogString("[log] Queue 2 empty", true);
				}
			}

			//remove last message shown on display from fila_1
			if ((key_pressed == 'r'))
			{
				auxI = fila_1.getSize();
				if (auxI > 0)
				{
					for (i = 0; i < auxI - 1; i++)
					{
						fila_1.pushBack(fila_1.popFront());
					}
					fila_1.popFront();
					//log action
					console.writeLogString("Message removed", true);
				}
				else
				{
					//log action
					console.writeLogString("Queue 1 empty", true);
				}
			}
		}
	}
}
