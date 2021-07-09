#include <iostream>
#include "PrecondViolatedExcept.h"

PrecondViolatedExcept::PrecondViolatedExcept(std::string errorMsg)
{
	m_errorMsg = errorMsg;
}

std::string PrecondViolatedExcept::GetMsg() const
{
	return m_errorMsg;
}

void PrecondViolatedExcept::SetMsg(std::string errorMsg)
{
	m_errorMsg = errorMsg;
}
