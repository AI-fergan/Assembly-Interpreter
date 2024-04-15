#pragma once
#include "Pch.h"
#include "Utilities.h"

/*
* This class contains the Lexer of the Interpreter,
* it split the user input into tokens by the interpreter rules and store it in queue of strings.
*/
class Lexer
{
public:
	Lexer(string input);
	queue<string> getTokens();
	void printLexer();

private:
	string _input;
	queue<string> _tokens;
};
