#include "GPIO_PC.h"
#include <iostream>
using namespace std;

CGPIO::CGPIO()
{

}

CGPIO::~CGPIO()
{

}

void CGPIO::readInputs()
{
	int aux;

	cout << endl;
	cout << "1 - M025" << endl;
	cout << "2 - M050" << endl;
	cout << "3 - M100" << endl;
	cout << "4 - MEET" << endl;
	cout << "5 - ETIRPS" << endl;
	cout << "6 - DEV" << endl;
	cout << "Aguardando entrada: ";
	cin >> aux;
		
	switch (aux)
	{
		case 1:
			setInput(M025);
			break;
		case 2:
			setInput(M050);
			break;
		case 3:
			setInput(M100);
			break;
		case 4:
			setInput(MEET);
			break;
		case 5:
			setInput(ETIRPS);
			break;
		case 6:
			setInput(DEV);
			break;
		default:
			break;
	}
}

void CGPIO::writeOutputs()
{
	if (getOutput(M025))
	{
		cout << "\nR$ 0,25 devolvido!" << endl;
		clearOutput(M025);
	}

	if (getOutput(M050))
	{
		cout << "\nR$ 0,50 devolvido!" << endl;
		clearOutput(M050);
	}

	if (getOutput(M100))
	{
		cout << "\nR$ 1,00 devolvido!" << endl;
		clearOutput(M100);
	}

	if (getOutput(MEET))
	{
		cout << "\nMEET liberado!" << endl;
		clearOutput(MEET);
	}

	if (getOutput(ETIRPS))
	{
		cout << "\nETIRPS liberado!" << endl;
		clearOutput(ETIRPS);
	}
}

void CGPIO::showCredit(int credit)
{
	credit *= 25;
	cout << "\nCredito: R$ " << credit / 100 << "," << credit % 100 << endl;
}