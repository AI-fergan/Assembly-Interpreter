#pragma once
#include "Pch.h"
#include "Exceptions.h"

class SyntaxError : public Exceptions
{
public:
	SyntaxError(string error);

	const char* what() override;
};
