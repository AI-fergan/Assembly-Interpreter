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
	if (_opcode->getBranches().size() == 1) {
		if (_opcode->getBranches()[0]->getBranches().size() == 2) {
			cout << "*mov*\n";
		}
	}
}

void Opcode::add() {
	if (_opcode->getBranches().size() == 1) {
		if (_opcode->getBranches()[0]->getBranches().size() == 2) {
			cout << "*add*\n";
		}
	}
}

void Opcode::sub() {
	if (_opcode->getBranches().size() == 1) {
		if (_opcode->getBranches()[0]->getBranches().size() == 2) {
			cout << "*sub*\n";
		}
	}
}
