#include "Pch.h"
#include "Lexer.h"
#include "AstParser.h"
#include "Opcode.h"
#include "MemStore.h"
#include "Commands.h"

int main() {
	string input;
	Lexer* lexer = nullptr;
	AstParser* parser = nullptr;
	MemStore* memory = new MemStore();
	Commands* commands = new Commands(memory);

	cout << " ----------------------------" << endl;
	cout << "|   Noam Afergan |  V2.0.0   |" << endl;
	cout << "|----------------------------|" << endl;
	cout << "|    Assembly-Interpreter    |" << endl;
	cout << " ----------------------------" << endl << endl;
	
	while (true) {
		cout << ">>>";

		//input code line from the user
		getline(cin, input);

		//check if the user want to enter command
		if (commands->commandsHandler(input))
			continue;		

		//exit
		if (input == "exit")
			return 0;

		//run Lexer the line
		lexer = new Lexer(input);

		try {
			//clean the flags register
			memory->cleanFlags();

			//run Parser after Lexer
			parser = new AstParser(lexer->getTokens());
			
			//run the Opcode
			Opcode* opcode = new Opcode(parser->getBranches()[0], memory);
			
			//clean
			delete parser;
			delete opcode;
		}
		catch (Exceptions& e)
		{
			//print the exception
			cout << e.what() << e.getError() << endl;
		}

		delete lexer;		
	}

	return 0;
}