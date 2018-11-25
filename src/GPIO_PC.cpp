#include "GPIO_PC.h"
#include <iostream>
#include <conio.h>
using namespace std;

CGPIO::CGPIO()
{

}

CGPIO::~CGPIO()
{

}

void CGPIO::readInputs(Cqueue<string>* queueP)
{
	int aux[2];
	string auxS;

	if (_kbhit())
	{
		aux[0] = _getch();
		aux[1] = _getch();

		if (aux[0] == 0)
		{
			switch (aux[1])
			{
			case 59: //F1
				setInput(M025);
				auxS = "R$ 0,25 recebido.";
				queueP->pushBack(auxS);
				break;
			case 60: //F2
				setInput(M050);
				auxS = "R$ 0,50 recebido.";
				queueP->pushBack(auxS);
				break;
			case 61: //F3
				setInput(M100);
				auxS = "R$ 1,00 recebido.";
				queueP->pushBack(auxS);
				break;
			case 62: //F4
				setInput(MEET);
				auxS = "MEET solicitado.";
				queueP->pushBack(auxS);
				break;
			case 63: //F5
				setInput(ETIRPS);
				auxS = "ETIRPS solicitado.";
				queueP->pushBack(auxS);
				break;
			case 64: //F6
				setInput(DEV);
				auxS = "Devolucao do dinheiro solicitado.";
				queueP->pushBack(auxS);
				break;
			default:
				break;
			}
		}
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

void CGPIO::writeOutputs(Cqueue<string>* queueP)
{
	string auxS;

	if (getOutput(M025))
	{
		//cout << "\nR$ 0,25 devolvido!" << endl;
		auxS = "R$0,25 devolvido.";
		queueP->pushBack(auxS);
		clearOutput(M025);
	}

	if (getOutput(M050))
	{
		//cout << "\nR$ 0,50 devolvido!" << endl;
		auxS = "R$0,50 devolvido.";
		queueP->pushBack(auxS);
		clearOutput(M050);
	}

	if (getOutput(M100))
	{
		//cout << "\nR$ 1,00 devolvido!" << endl;
		auxS = "R$1,00 devolvido.";
		queueP->pushBack(auxS);
		clearOutput(M100);
	}

	if (getOutput(MEET))
	{
		//cout << "\nMEET liberado!" << endl;
		auxS = "MEET liberado.";
		queueP->pushBack(auxS);
		clearOutput(MEET);
	}

	if (getOutput(ETIRPS))
	{
		//cout << "\nETIRPS liberado!" << endl;
		auxS = "ETIRPS liberado.";
		queueP->pushBack(auxS);
		clearOutput(ETIRPS);
	}
}

void CGPIO::showCredit(int credit)
{
	credit *= 25;
	cout << "\nCredito: R$ " << credit / 100 << "," << credit % 100 << endl;
}