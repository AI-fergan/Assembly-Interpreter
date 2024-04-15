#pragma once
#include "Pch.h"

/*
* This class is the "Main" class of all the other exeptions classes.
*/
class Exceptions : public exception
{
public:
	Exceptions(string error);

	virtual const char* what() = 0;
	string getError();

protected:
	string _error;
};
