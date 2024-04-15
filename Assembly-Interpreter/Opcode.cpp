#include "Opcode.h"

Opcode::Opcode(AstNode* opcode) {
	this->_opcode = opcode;

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
	cout << "*mov*\n";
}

void Opcode::add() {
	cout << "*add*\n";
}

void Opcode::sub() {
	cout << "*sub*\n";
}
