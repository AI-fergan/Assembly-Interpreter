#pragma once
#include "Pch.h"
#include "Exceptions.h"

/*
* This Exception class used for every Error in the registers.
*/
class RegisterError : public Exceptions
{
public:
	RegisterError(string error);

	const char* what() override;
};
