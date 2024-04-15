#include "Opcode.h"

Opcode::Opcode(AstNode* opcode, MemStore* mem) {
	this->_opcode = opcode;
	this->_mem = mem;

	switch (Utilities::getOpcode(opcode->getData())) {
	case Opcodes::mov:
		mov();
		break;
	case Opcodes::sub:
		sub();
		break;
	case Opcodes::add:
		add();
		break;
	default:
		cerr << "ERROR";
		break;
	}
}

void Opcode::mov() {
	Utilities utilities;

	if(utilities.validOperators(_opcode, 1) && utilities.validparams(_opcode, 2)) {
		ValuesHandler* value = new ValuesHandler(utilities.getParam(_opcode, 1), _mem);		
		_mem->setRegister(utilities.getParam(_opcode, 0), value->handler());
	}
	else {
		throw SyntaxError("Opcode Error: opcode syntax not valid.");
	}
}

void Opcode::add() {
	Utilities utilities;
	int old_value = 0;

	if (utilities.validOperators(_opcode, 1) && utilities.validparams(_opcode, 2)) {
		old_value = _mem->getRegister(utilities.getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(utilities.getParam(_opcode, 1), _mem);
		_mem->setRegister(utilities.getParam(_opcode, 0), old_value + value->handler());

	}
	else {
		throw SyntaxError("Opcode Error: opcode syntax not valid.");
	}
}

void Opcode::sub() {
	Utilities utilities;
	int old_value = 0;

	if (utilities.validOperators(_opcode, 1) && utilities.validparams(_opcode, 2)) {
		old_value = _mem->getRegister(utilities.getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(utilities.getParam(_opcode, 1), _mem);
		_mem->setRegister(utilities.getParam(_opcode, 0), old_value - value->handler());

	}
	else {
		throw SyntaxError("Opcode Error: opcode syntax not valid.");
	}
}
