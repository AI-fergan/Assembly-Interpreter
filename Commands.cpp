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
	Utilities::toLower(command);

	//Help command
	if (command == "help") {
		CommandsHelp();
		return true;
	}
	//Help with exists opcodes
	else if (command == "opc" || command == "opcodes") {
		opcodesHelp();
		return true;
	}
	//Print the memory data
	else if (command == "mem") {
		printMemory();
		return true;
	}
	else if (command == "history") {
		printHistory();
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
	cout << "help, opc \ opcodes, mem, exit" << endl;
}

/*
* This function print all the exists opcodes in the Interpreter.
* Output: NULL.
*/
void Commands::opcodesHelp() {
	int i = 1;
	for (const auto opcode : Utilities::OpcodesChars) {
		cout << opcode.first << " ";
		if (i % 7 == 0) {
			cout << endl;
		}
		i++;
	}
	cout << endl;
}

/*
* This function print the opcodes history.
* Output: NULL.
*/
void Commands::printHistory() {
	_mem->printHistory();
}

