#pragma once
#include "Pch.h"
#include "Exceptions.h"

class SyntaxError : public Exceptions
{
public:
	SyntaxError(string error);

private:
	string _error;
};
