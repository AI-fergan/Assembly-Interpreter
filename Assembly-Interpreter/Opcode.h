#pragma once
#include "Utilities.h"
#include "Pch.h"
#include "AstNode.h"
#include "SyntaxError.h"

class Opcode
{
public:
	Opcode(AstNode* opcode);

private:
	AstNode* _opcode;

	void mov();
	void add();
	void sub();
};
