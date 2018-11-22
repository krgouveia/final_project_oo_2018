#ifndef GPIO_PC_H
#define GPIO_PC_H

#include "IO.h"

class CGPIO : public CIO {
public:
	CGPIO();
	~CGPIO();
	void readInputs();
	void writeOutputs();
	void showCredit(int credit);
};

#endif