/**
 * \file GPIO_PC.h
 * \version 1.0
 * \author Kleber Gouveia
 * \date Nov 10, 2018
 *
 **************************************************************************
 *
 * Module Name:  GPIO_PC.h
 *
 * \brief Implements the methods of the CGPIO class.
 *
 * \section References
 *
 **************************************************************************
 * \section Revisions
 *
 * Revision: 1.0   10-Nov-2018    Kleber Gouveia
 * * Working baseline.
 *
 ***************************************************************************/

#include "GPIO_PC.h"
#include <iostream>
#include <conio.h>
using namespace std;

/**
*   \brief Class constructor.
*/
CGPIO::CGPIO()
{

}

/**
 * \brief Class destructor
 */ 
CGPIO::~CGPIO()
{

}

/**
 * \brief This method manage the GPIOs input.
 * \param queueP - Pointer to an Cqueue object.
 * \return none
 */
void CGPIO::readInputs(Cqueue<string>* queueP)
{
	int aux[2];
	string auxS;

	//check if some key was pressed
	if (_kbhit())
	{
		//each key is mapped by two chars
		aux[0] = _getch();
		aux[1] = _getch();
		//check if the chars are from a special key (F1, insert, home, arrows...)
		if (aux[0] == 0)
		{
			switch (aux[1])
			{
			case 59: //F1
				setInput(M025);
				auxS = "R$ 0,25 received.";
				queueP->pushBack(auxS);
				break;
			case 60: //F2
				setInput(M050);
				auxS = "R$ 0,50 received.";
				queueP->pushBack(auxS);
				break;
			case 61: //F3
				setInput(M100);
				auxS = "R$ 1,00 received.";
				queueP->pushBack(auxS);
				break;
			case 62: //F4
				setInput(MEET);
				auxS = "MEET requested.";
				queueP->pushBack(auxS);
				break;
			case 63: //F5
				setInput(ETIRPS);
				auxS = "ETIRPS requested.";
				queueP->pushBack(auxS);
				break;
			case 64: //F6
				setInput(DEV);
				auxS = "Money return requested.";
				queueP->pushBack(auxS);
				break;
			default:
				break;
			}
		}
		//else, put the chars in the buffer again
		else
		{
			_ungetch(aux[0]);
			_ungetch(aux[1]);
		}
	}
	else
	{
		aux[1] = 0;
		aux[0] = 0;
	}


}

/**
 * \brief Method responsible to update the outputs.
 * \param queueP - Pointer to an Cqueue object.
 * \return none
 */
void CGPIO::writeOutputs(Cqueue<string>* queueP)
{
	string auxS;

	if (getOutput(M025))
	{
		//cout << "\nR$ 0,25 devolvido!" << endl;
		auxS = "R$0,25 returned.";
		queueP->pushBack(auxS);
		clearOutput(M025);
	}

	if (getOutput(M050))
	{
		//cout << "\nR$ 0,50 devolvido!" << endl;
		auxS = "R$0,50 returned.";
		queueP->pushBack(auxS);
		clearOutput(M050);
	}

	if (getOutput(M100))
	{
		//cout << "\nR$ 1,00 devolvido!" << endl;
		auxS = "R$1,00 returned.";
		queueP->pushBack(auxS);
		clearOutput(M100);
	}

	if (getOutput(MEET))
	{
		//cout << "\nMEET liberado!" << endl;
		auxS = "MEET released.";
		queueP->pushBack(auxS);
		clearOutput(MEET);
	}

	if (getOutput(ETIRPS))
	{
		//cout << "\nETIRPS liberado!" << endl;
		auxS = "ETIRPS released.";
		queueP->pushBack(auxS);
		clearOutput(ETIRPS);
	}
}
