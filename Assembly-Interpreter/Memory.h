#pragma once
#include "Pch.h"
#include "Utilities.h"

class Memory {
public:
	Memory();
	static bool setRegister(string reg, int value);
	static int getRegister(string reg);

private:
	static map<string, int> _registers;
};
