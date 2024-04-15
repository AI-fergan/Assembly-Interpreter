#include "AstNode.h"

AstNode::AstNode(string data, int type) { 
	_Data = data;
	_type = type;
}

string AstNode::getData() {
	return this->_Data;
}

vector<AstNode*> AstNode::getBranches() {
	return this->_branches;
}

void AstNode::add(AstNode* node) {
	this->_branches.push_back(node);
}

int AstNode::getType()
{
	return _type;
}
