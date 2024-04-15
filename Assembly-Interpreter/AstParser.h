#pragma once
#include "Pch.h"
#include "Utilities.h"
#include "AstNode.h"
#include "OpcodesNode.h"
#include "OperatorsNode.h"

class AstParser
{
public:
	AstParser(queue<string> tokens);
	std::vector<AstNode*> getBranches();

private:
	std::vector<AstNode*> _branches;
};

