#pragma once
#include "Pch.h"
#include "Utilities.h"
#include "RegisterError.h"

/*
* This class managed all the Interpreter memory, such as Registers etc...
*/
class MemStore {
public:
	MemStore();
	void setRegister(string reg, int value);
	int getRegister(string reg);
	bool isRegister(string reg);
	void push(int value);
	int pop();

	void printMemory();
private:
	map<tuple<string, string, string>, int> _registers;
	vector<int> _stack;
};
