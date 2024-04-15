#pragma once
#include "Pch.h"
#include "Utilities.h"

/* This class used fot the nodes of the AST */
class AstNode {
public:
	AstNode(string data, int type);
	string getData();
	vector<AstNode*> getBranches();
	void add(AstNode* node);
	int getType();

private:
	vector<AstNode*> _branches;
	string _Data;
	int _type;
};
