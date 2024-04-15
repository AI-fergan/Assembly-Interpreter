#pragma once
#include "Utilities.h"
#include "Pch.h"
#include "AstNode.h"
#include "SyntaxError.h"
#include "MemStore.h"
#include "ValuesHandler.h"

class Opcode
{
public:
	Opcode(AstNode* opcode, MemStore* mem);

private:
	AstNode* _opcode;
	MemStore* _mem;

	void mov();
	void add();
	void sub();
};
