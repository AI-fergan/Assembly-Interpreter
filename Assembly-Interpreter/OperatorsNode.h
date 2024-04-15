#pragma once
#include "AstNode.h"

class OperatorsNode : public AstNode
{
public:
	OperatorsNode(Operators id, string data);
	IDs getID();

private:
	Operators _ID;
};
