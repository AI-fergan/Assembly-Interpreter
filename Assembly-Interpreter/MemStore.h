#pragma once
#include "Pch.h"
#include "Utilities.h"

class MemStore {
public:
	MemStore();
	bool setRegister(string reg, int value);
	int getRegister(string reg);

private:
	map<string, int> _registers;
};
