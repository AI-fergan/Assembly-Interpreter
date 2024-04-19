#pragma once
#include "Pch.h"
#include "Utilities.h"
#include "RegisterError.h"
#include "StackError.h"
#include "Opcode.h"

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
	MemStore(string path);
	void setRegister(string reg, unsigned int value);
	unsigned int getRegister(string reg);
	int getRegisterSize(string reg);
	bool isRegister(string reg);
	void push(unsigned int value);
	unsigned int pop();
	void cleanFlags();
	
	void addToHistory(Opcode* opcode);
	Opcode* getFromHistory(unsigned int place);
	void incEIP();
	void printMemory();

	struct Flags _flags;

private:
	map<tuple<string, string, string>, unsigned int> _registers;
	vector<unsigned int> _stack;
	vector<Opcode*> _history;
};
