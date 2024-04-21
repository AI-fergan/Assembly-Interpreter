#pragma once
#include "Pch.h"
#include "Exceptions.h"

/*
* This Exception class used for every Value Error.
*/
class Error : public Exceptions
{
public:
	Error(string error);

	const char* what() override;
};
