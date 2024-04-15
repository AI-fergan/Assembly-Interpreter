#pragma once
#include "Pch.h"
#include "Utilities.h"

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
