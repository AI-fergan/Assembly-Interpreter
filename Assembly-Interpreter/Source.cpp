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
		try {
			parser = new AstParser(lexer->getTokens());
			Opcode* opcode = new Opcode(parser->getBranches()[0]);
			delete parser;
			delete opcode;
		}
		catch(string error) {
			cout << error << endl;
		}
		
		delete lexer;
		
	}

	return 0;
}