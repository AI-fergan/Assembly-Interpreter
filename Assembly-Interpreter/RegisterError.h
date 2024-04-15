#pragma once
#include "Pch.h"
#include "Exceptions.h"

class RegisterError : public Exceptions
{
public:
	RegisterError(string error);

	const char* what() override;
};
