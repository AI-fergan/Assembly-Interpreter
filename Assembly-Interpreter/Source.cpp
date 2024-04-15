#include "Pch.h"
#include "Lexer.h"
#include "AstParser.h"
#include "Opcode.h"
#include "MemStore.h"

int main() {
	string input;
	Lexer* lexer = nullptr;
	AstParser* parser = nullptr;
	MemStore* memory = new MemStore();

	while (true) {
		cout << ">>>";
		getline(cin, input);

		lexer = new Lexer(input);

		try {
			parser = new AstParser(lexer->getTokens());
			Opcode* opcode = new Opcode(parser->getBranches()[0], memory);
			delete parser;
			delete opcode;
		}
		catch (Exceptions& e)
		{
			cout << e.what() << e.getError() << endl;
		}
		memory->printMemory();
		delete lexer;		
	}

	return 0;
}