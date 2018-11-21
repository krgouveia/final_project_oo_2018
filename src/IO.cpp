/*!
 *  \file       IO.cpp
 *  \brief      Implementação dos métodos de acesso a interface de entrada e sáida do sistema.
 *  \author     Kleber Gouveia
 */

#include "IO.h"

CIO::CIO()
{
	flags_input = 0;
	flags_output = 0;
}

CIO::~CIO()
{

}

void CIO::setInput(int flag)
{
	flags_input |= flag;
}

void CIO::clearInput(int flag)
{
	flags_input &= ~flag;
}

bool CIO::getInput(int flag)
{
	return (((flags_input & flag) != 0) ? 1 : 0);
}

void CIO::setOutput(int flag)
{
	flags_output |= flag;
}

void CIO::clearOutput(int flag)
{
	flags_output &= ~flag;
}

bool CIO::getOutput(int flag)
{
	return (((flags_output & flag) != 0) ? 1 : 0);
}
