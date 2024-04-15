#pragma once
#include "AstNode.h"

class OpcodesNode : public AstNode
{
public:
	OpcodesNode(Opcodes id, string data);
	IDs getID();
private:
	Opcodes _ID;
};
