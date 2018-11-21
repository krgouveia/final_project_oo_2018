/*!
 *  \file       IO.h
 *  \brief      Defini��o da classe de acesso a interface de entrada e s�ida do sistema.
 *  \author     Kleber Gouveia
 */

#ifndef IO_H
#define IO_H

#define M025	0x01    /*!< Moeda de R$0,25*/
#define M050	0x02    /*!< Moeda de R$0,50*/
#define M100	0x04    /*!< Moeda de R$1,00*/
#define MEET	0x08    /*!< Refrigentante MEET*/
#define ETIRPS	0x10    /*!< Refrigerante ETIRPS*/
#define DEV		0x20    /*!< Devolucao*/

class CIO {
protected:
	int flags_input;
	int flags_output;
public:
	CIO();
	~CIO();
	void setInput(int flag);
	void clearInput(int flag);
	bool getInput(int flag);
	void setOutput(int flag);
	void clearOutput(int flag);
	bool getOutput(int flag);
	virtual void readInputs() = 0;
	virtual void writeOutputs() = 0;
	virtual void showCredit(int credit) = 0;
};

#endif