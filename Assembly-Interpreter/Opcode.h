#pragma once
#include "Utilities.h"
#include "Pch.h"
#include "OpcodesNode.h"

class Opcode
{
public:
	Opcode(OpcodesNode* opcode);

private:
	OpcodesNode* _opcode;

	void mov();
	void add();
	void sub();
};
