#pragma once
#include "Pch.h"
#include "Utilities.h"
#include "RegisterError.h"
#include "StackError.h"

//Flags register settings
struct Flags {
	bool CF;
	bool ZF;
	bool SF;
	bool OF;
	bool PF;
	bool AF;
	bool IF;
	bool DF;
};

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
	void cleanFlags();

	void printMemory();

	struct Flags _flags;

private:
	map<tuple<string, string, string>, int> _registers;
	vector<int> _stack;
	
};
