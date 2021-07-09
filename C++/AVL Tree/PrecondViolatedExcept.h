#pragma once
#include <iostream>


#ifndef PRECONDVIOLATEDEXCEPT_HEADER
#define PRECONDVIOLATEDEXCEPT_HEADER

class PrecondViolatedExcept
{
public:
	PrecondViolatedExcept(const std::string errorMsg);

	std::string GetMsg() const;
	void SetMsg(const std::string errorMsg);

private:
	std::string m_errorMsg;
};

#endif
