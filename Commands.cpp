#include "Commands.h"

/*
* This c'tor init the memory to the command env.
* Input:
* mem - the mem to work on.
*/
Commands::Commands(MemStore* mem) {
	this->_mem = mem;
}

/*
* This function Handle the user input and check which command is appropriate to that input.
* Input:
* command - the user input for handle.
* Output: if the command is exists.
*/
bool Commands::commandsHandler(string command) {
	//Help command
	if (command == "help") {
		CommandsHelp();
		return true;
	}
	//Help with exists opcodes
	else if (command == "inst" || command == "opcodes") {
		opcodesHelp();
		return true;
	}
	//Print the memory data
	else if (command == "mem") {
		printMemory();
		return true;
	}

	return false;
		
}

/*
* This function print the memory data.
* Output: NULL.
*/
void Commands::printMemory() {
	_mem->printMemory();
}

/*
* This function print all the exists commands.
* Output: NULL.
*/
void Commands::CommandsHelp() {
	cout << "Commands:" << endl;
	cout << "help, inst (opcodes), mem, exit" << endl;
}

/*
* This function print all the exists 



s in the Interpreter.
* Output: NULL.
*/
void Commands::opcodesHelp() {
	cout << "MOV, SUB, MUL, DIV, INC, DEC, OR, AND," << endl;
	cout << "XOR, NOT, NOP, SHL, SHR, ROL, ROR" << endl;
}

