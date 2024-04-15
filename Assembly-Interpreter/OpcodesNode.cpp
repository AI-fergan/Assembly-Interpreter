#include "OpcodesNode.h"

OpcodesNode::OpcodesNode(Opcodes id, string data) : AstNode(data) {
	this->_ID = id;
}

IDs OpcodesNode::getID()
{
	IDs id;
	id.opcode = this->_ID;
	return id;
}
