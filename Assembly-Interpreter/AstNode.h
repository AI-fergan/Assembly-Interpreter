#pragma once
#include "Pch.h"
#include "Utilities.h"

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
