#pragma once
#include "Pch.h"
#include "Exceptions.h"

/*
* This Exception class used for every Value Error.
*/
class ValueError : public Exceptions
{
public:
	ValueError(string error);

	const char* what() override;
};
