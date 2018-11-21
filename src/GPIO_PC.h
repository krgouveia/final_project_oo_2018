#ifndef GPIO_PC_H
#define GPIO_PC_H

#include "IO.h"

class GPIO_PC : public CIO {
public:
	GPIO_PC();
	~GPIO_PC();
	void readInputs();
	void writeOutputs();
	void showCredit(int credit);
};

#endif