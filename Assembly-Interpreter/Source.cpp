#include "Pch.h"
#include "Lexer.h"
#include "AstParser.h"
#include "Opcode.h"


int main() {
	string input;
	Lexer* lexer = nullptr;
	AstParser* parser = nullptr;

	while (true) {
		cout << ">>>";
		getline(cin, input);

		lexer = new Lexer(input);
		lexer->printLexer();
		parser = new AstParser(lexer->getTokens());
		
		Opcodes id = parser->getBranches()[0]->getBranches()[0]->getID().opcode;
		string data = parser->getBranches()[0]->getBranches()[0]->getData();
		data = parser->getBranches()[0]->getBranches()[0]->getData();
		delete lexer;
		delete parser;
		delete lexer;
	}

	return 0;
}