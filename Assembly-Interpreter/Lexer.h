#pragma once
#include "Pch.h"

class Lexer
{
public:
	Lexer(string input);
	

private:
	string _input;
	queue<string> tokens;
};
