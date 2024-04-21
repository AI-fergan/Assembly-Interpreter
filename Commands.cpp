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
	else if (command == "mem" || command == "memory") {
		printMemory();
		return true;
	}
	//Print the opcodes history
	else if (command == "history" || command == "h") {
		printHistory();
		return true;
	}
	//Jump to opcode from the history
	else if (command == "jmp") {
		JMP();
		return true;
	}
	//Clean screen
	else if (command == "cls") {
		cls();
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
	cout << "help, opc / opcodes, mem / memory, h / history, JMP, cls, exit" << endl;
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

/*
* This function jump to given place from the opcodes history.
* Output: NULL.
*/
void Commands::JMP() {
	string place;

	//get place
	cout << "Where: ";
	getline(cin, place);

	ValuesHandler* value = new ValuesHandler(place, _mem);

	//runall the opcodes from this place
	_mem->jmp(value->handler(true));
}

/*
* This function clean the screen and print the open message.
*/
void Commands::cls() {
	system("cls");
	cout << " ----------------------------" << endl;
	cout << "|   Noam Afergan |  V5.0.0   |" << endl;
	cout << "|----------------------------|" << endl;
	cout << "|    Assembly-Interpreter    |" << endl;
	cout << " ----------------------------" << endl << endl;
}

