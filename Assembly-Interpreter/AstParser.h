#pragma once
#include "Pch.h"
#include "Utilities.h"
#include "AstNode.h"
#include "SyntaxError.h"

class AstParser
{
public:
	AstParser(queue<string> tokens);
	std::vector<AstNode*> getBranches();
	void printTree();

private:
	std::vector<AstNode*> _branches;
};

