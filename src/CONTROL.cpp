#include"CONTROL.h"
#include <string>
using namespace std;

CControl::CControl()// : console(&systemRTC)
{
	//console(&systemRTC);
	msgCounter = 3;
	CommandParserState = 0;
	last_time = systemRTC.getSystemClock();
}

CControl::~CControl()
{

}

void CControl::messageManager(void)
{
	string auxS;

	//get actual timestamp
	actual_time = systemRTC.getSystemClock();

	//check if there is some FSM's action reported
	if (!fila_3.checkEmpty())
	{
		//delays the time to show a new message 
		last_time += TIME_DURATION_FSM_MSG;

		//get message from begin of fila_3
		auxS = fila_3.popFront();
		//write message into display
		LCD.writeString(auxS);
	}
	else //check other information to display
	{
		//check if it's time to show a new information on display
		if (actual_time >= (last_time + TIME_DURATION_AD_MSG))
		{
			//check if it's time to show date/time information on display
			if (msgCounter <= 0)
			{
				//delays the time to show a new message 
				last_time += TIME_DURATION_DATE_MSG;

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
	}
}

void CControl::receiveCommand(void)
{
	char auxC;
	//enqueue commands received to be parsed
	if (console.ReadCommand(&auxC))
	{
		commandInputBuffer.pushBack(auxC);
	}
}

void CControl::commandsParser(void)
{
	char auxC;
	int auxI, i;

	//commands parser logic
		switch (CommandParserState)
		{
		case 0: //wait command
			if (commandInputBuffer.getSize() >= 2)
			{
				if (commandInputBuffer.popFront() == '=')
				{
					CommandParserState = 1;
				}
			}
			break;
		case 1: //popQueue and select the command
			switch (commandInputBuffer.popFront())
			{
			case 't': //transfer messages from fila_2 to fila_1
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
				CommandParserState = 0;
				break;

			case 'r': //remove last message shown on display from fila_1
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
				CommandParserState = 0;
				break;

			case 'h': //show commands list
				console.writeLogString("*********** Commands list ***********", true);
				console.writeLogString("=h - to show commands list.", true);
				console.writeLogString("=n<string>; - to insert new messages. <string> is the message to be inserted.", true);
				console.writeLogString("=t - to enable new messages to be shown.", true);
				console.writeLogString("=r - to remove last message shown.", true);
				console.writeLogString("*************************************", true);
				CommandParserState = 0;
				break;

			case'n': //"insert" new message into fila_2
				newMessage = "";
				countCommmand = 0;
				CommandParserState = 2;
				break;

			default:
				CommandParserState = 0;
				break;

			}
			break;
		case 2: //receive new message
			if (commandInputBuffer.getSize() >= 1)
			{	
				if (countCommmand >= MSG_LENGHT_MAX) CommandParserState = 0;
				else
				{
					auxC = commandInputBuffer.popFront();
					if (auxC == ';')
					{
						fila_2.pushBack(newMessage);
						//log action
						console.writeLogString("New message received", true);
						CommandParserState = 0;
					}
					else
					{
						newMessage += auxC;
						countCommmand++;
					}
				}
			}
			break;

		default:
			break;
		}
	}
