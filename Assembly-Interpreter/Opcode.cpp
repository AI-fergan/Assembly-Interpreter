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
		cout << "*mov*\n";
		_mem->setRegister(utilities.getParam(_opcode, 0), utilities.StringToDec(utilities.getParam(_opcode, 1)));
	}
	else {
		throw SyntaxError("Opcode Error: opcode syntax not valid.");
	}
}

void Opcode::add() {
	Utilities utilities;

	if (utilities.validOperators(_opcode, 1) && utilities.validparams(_opcode, 2)) {
		cout << "*add*\n";
	}
	else {
		throw SyntaxError("Opcode Error: opcode syntax not valid.");
	}
}

void Opcode::sub() {
	Utilities utilities;

	if (utilities.validOperators(_opcode, 1) && utilities.validparams(_opcode, 2)) {
		cout << "*sub*\n";
	}
	else {
		throw SyntaxError("Opcode Error: opcode syntax not valid.");
	}
}
