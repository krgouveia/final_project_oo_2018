#ifndef CONTROL_H
#define CONTROL_H

#include "queue.hpp"


#ifdef ARM_PLATFORM
#include "LCD_UC.h"
//#include "CONSOLE_UC.h"
#include "RTC_UC.h"
#endif
#ifdef PC_PLATFORM
#include "SCREEN_PC.h"
#include "CONSOLE_PC.h"
#include "TIME_PC.h"
#endif

#define TIME_DURATION_AD_MSG	3000 //duration of advertising messages shown on diaplay is miliseconds
#define TIME_DURATION_DATE_MSG	2000 //duration of data/time information shown on diaplay is miliseconds
#define TIME_DURATION_FSM_MSG	1000 //duration of fsm actions shown on diaplay is miliseconds
#define MSG_LENGHT_MAX			20 //maximum message lenght to be shown in display


class CControl{
protected:
	//display logic variables
	long int last_time;
	long int actual_time;
	int msgCounter;// = 3;
	
	//command logic variables
	int CommandParserState;// = 0;
	string newMessage;
	int countCommmand;
	
	////instantiating the system real timer clock
	CTime systemRTC;
	//instantiating the console
//	CConsole console;
	//instantiating the LCD
	CLCD LCD;
	
	//instantiating the queues
	Cqueue<string>	fila_1; //advertising to be shown in display
	Cqueue<string>	fila_2; //new advertising received
	Cqueue<char>	commandInputBuffer; //input buffer to receive commands from terminal

public:
	//instantiating the queues
	Cqueue<string>	fila_3; //messages received from FSM

	CControl();
	~CControl();
	void messageManager(void);
	void receiveCommand(void);
	void commandsParser(void);
};

#endif
