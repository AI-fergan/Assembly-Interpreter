#include "Opcode.h"

Opcode::Opcode(AstNode* opcode, MemStore* mem) {
	this->_opcode = opcode;
	this->_mem = mem;

	switch (Utilities::getOpcode(opcode->getData())) {
	case Opcodes::Mov:
		Mov();
		break;
	case Opcodes::Sub:
		Sub();
		break;
	case Opcodes::Add:
		Add();
		break;
	case Opcodes::Mul:
		Mul();
		break;
	case Opcodes::Div:
		Div();
		break;
	case Opcodes::Inc:
		Inc();
		break;
	case Opcodes::Dec:
		Dec();
		break;
	case Opcodes::Or:
		Or();
		break;
	case Opcodes::And:
		And();
		break;
	case Opcodes::Xor:
		Xor();
		break;
	case Opcodes::Not:
		Not();
		break;
	case Opcodes::Nop:
		Nop();
		break;
	case Opcodes::Shl:
		Shl();
		break;
	case Opcodes::Shr:
		Shr();
		break;
	case Opcodes::Rol:
		Rol();
		break;
	case Opcodes::Ror:
		Ror();
		break;

	default:
		cerr << "ERROR";
		break;
	}
}

void Opcode::Mov() {
	if(Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);		
		_mem->setRegister(Utilities::getParam(_opcode, 0), value->handler());
	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

void Opcode::Add() {
	int old_value = 0;

	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value + value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

void Opcode::Sub() {
	int old_value = 0;

	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value - value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

void Opcode::Mul() {
	int old_value = 0;

	if (Utilities::validOperators(_opcode, 1)) {
		old_value = _mem->getRegister(EAX);
		ValuesHandler* value = new ValuesHandler(_opcode->getBranches()[0]->getData(), _mem);
		_mem->setRegister(EAX, old_value * value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

void Opcode::Div() {
	int old_value = 0;

	if (Utilities::validOperators(_opcode, 1)) {
		old_value = _mem->getRegister(EAX);
		ValuesHandler* value = new ValuesHandler(_opcode->getBranches()[0]->getData(), _mem);
		_mem->setRegister(EAX, old_value / value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

void Opcode::Inc()
{
}

void Opcode::Dec()
{
}

void Opcode::Or()
{
}

void Opcode::And()
{
}

void Opcode::Xor()
{
}

void Opcode::Not()
{
}

void Opcode::Nop()
{
}

void Opcode::Shl()
{
}

void Opcode::Shr()
{
}

void Opcode::Rol()
{
}

void Opcode::Ror()
{
}
