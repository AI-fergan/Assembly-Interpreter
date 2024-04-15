#pragma once
#include "Pch.h"
#include "Utilities.h"
#include "RegisterError.h"

class MemStore {
public:
	MemStore();
	void setRegister(string reg, int value);
	int getRegister(string reg);
	
	void printMemory();
private:
	map<string, int> _registers;
};
