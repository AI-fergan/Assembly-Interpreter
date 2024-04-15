#include "AstNode.h"

/*
* This c'tor used to build every Node of the Ast.
* input:
* data - the value of the Node.
* type - the type of the Node in the Ast: Operator \ Operand \ Token.
*/
AstNode::AstNode(string data, int type) { 
	_Data = data;
	_type = type;
}

/*
* This function return the value of the Node.
* Output: the Node value.
*/
string AstNode::getData() {
	return this->_Data;
}

/*
* This function return all the branches of that Ast Node.
* Output: Vector of pointers to all the branches of the Ast Node.
*/
vector<AstNode*> AstNode::getBranches() {
	return this->_branches;
}

/*
* This function add new node to the Node branches.
* Input:
* node - new node to push into the Node branches.
* output: NULL
*/
void AstNode::add(AstNode* node) {
	this->_branches.push_back(node);
}

/*
* This function return the type of that Node.
* Output: The type of the Node.
*/
int AstNode::getType()
{
	return _type;
}
