#include "Opcode.h"

Opcode::Opcode(OpcodesNode* opcode) {
	this->_opcode = opcode;
	Opcodes id = opcode->getID().opcode;

	switch (id) {
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
