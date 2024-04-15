#pragma once
#include "Pch.h"
#include "Exceptions.h"

class ValueError : public Exceptions
{
public:
	ValueError(string error);

	const char* what() override;
};
