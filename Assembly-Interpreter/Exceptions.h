#pragma once
#include "Pch.h"

class Exceptions : public exception
{
public:
	Exceptions(string error);

	virtual const char* what() = 0;
	string getError();

protected:
	string _error;
};
