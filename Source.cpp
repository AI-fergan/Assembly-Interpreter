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
	bool history = false;

	//print open message and clean the screen
	commands->commandsHandler("cls");

	while (true) {
		cout << ">>>";
		cin.clear();
		
		//input code line from the user
		getline(cin, input);
		Utilities::toUpper(input);

		//new line
		if (!input.size())
			continue;

		try {
			//check if the user want to enter command
			if (commands->commandsHandler(input))
				continue;
		} catch (Exceptions& e) {
			//print the command exception
			cout << e.what() << e.getError() << endl;
			continue;			
		}

		//run Lexer the line
		lexer = new Lexer(input);

		//check if there is code line
		if (!lexer->getTokens().size())
			continue;

		try {
			history = false;

			//run Parser after Lexer
			parser = new AstParser(lexer->getTokens());
			
			//run the Opcode
			Opcode* opcode = new Opcode(parser->getBranches()[0], memory);

			//clean parser
			delete parser;
		
			//added the opcode to the opcodes history			
			memory->addToHistory(opcode, input);

			//opcode added to the history
			history = true;

			//run the opcode
			opcode->run();

			//increase the EIP register which count the opcodes
			memory->incEIP();
						
		}
		catch (Exceptions& e) {
			//print the exception
			cout << e.what() << e.getError() << endl;

			//remove opcode from the history
			if(history)
				memory->removeFromHistory();
		}

		//clean lexer
		delete lexer;		
	}

	return 0;
}