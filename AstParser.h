#pragma once
#include "Pch.h"
#include "Utilities.h"
#include "AstNode.h"
#include "SyntaxError.h"

/*
* This class contains the Parser of the Interpreter, 
* it parse the user line by the interpreter rules and the lexer output and give us the Ast.
*/
class AstParser
{
public:
	AstParser(queue<string> tokens);
	std::vector<AstNode*> getBranches();

private:
	std::vector<AstNode*> _branches;
};

