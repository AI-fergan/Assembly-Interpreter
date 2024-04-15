#pragma once
#include "Pch.h"
#include "Exceptions.h"

/*
* This Exception class used for every Error in the Syntax.
*/
class SyntaxError : public Exceptions
{
public:
	SyntaxError(string error);

	const char* what() override;
};
