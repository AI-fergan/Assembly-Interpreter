#pragma once
#include "Pch.h"
#include "Utilities.h"

union IDs {
	Opcodes opcode;
	Operators oper;
};

class AstNode {
public:
	AstNode(string data);
	string getData();
	vector<AstNode*> getBranches();
	void add(AstNode* node);
	virtual IDs getID() = 0;

private:
	vector<AstNode*> _branches;
	string _Data;
};
