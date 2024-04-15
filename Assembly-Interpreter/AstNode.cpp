#include "AstNode.h"

AstNode::AstNode(string data) { 
	_Data = data;
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