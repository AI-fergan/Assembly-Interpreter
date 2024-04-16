#pragma once
#include "Pch.h"
#include "Exceptions.h"

/*
* This Exception class used for every Error in the Syntax.
*/
class StackError : public Exceptions
{
public:
	StackError(string error);

	const char* what() override;
};
