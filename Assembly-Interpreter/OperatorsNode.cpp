#include "OperatorsNode.h"

OperatorsNode::OperatorsNode(Operators id, string data) : AstNode(data) {
	this -> _ID = id;
}

IDs OperatorsNode::getID() {
	IDs id;
	id.oper = this->_ID;
	return id;
}
