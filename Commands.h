#pragma once
#include "Pch.h"
#include "MemStore.h"

/*
* This class used to help the user controling the Interpreter.
*/
class Commands {
public:
	Commands(MemStore* mem);
	bool commandsHandler(string command);

	void printMemory();
	void CommandsHelp();
	void opcodesHelp();
	void printHistory();
	void JMP();
	void cls();

private:
	MemStore* _mem;

};