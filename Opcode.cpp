#include "Opcode.h"

/*
* This c'tor checks to which opcode the Node match and run that opcode.
* Input:
* opcode - the opcode Node.
* mem - the memory area to run the opcode.
*/
Opcode::Opcode(AstNode* opcode, MemStore* mem) {
	this->_opcode = opcode;
	this->_mem = mem;

	//check to which opcode the Node match
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

/* MOV Instruction */
void Opcode::Mov() {
	//check if the user enter the correct syntax of the instruction
	if(Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);		
		_mem->setRegister(Utilities::getParam(_opcode, 0), value->handler());
	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* ADD Instruction */
void Opcode::Add() {
	int old_value = 0;

	//check if the user enter the correct syntax of the instruction
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value + value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* SUB Instruction */
void Opcode::Sub() {
	int old_value = 0;

	//check if the user enter the correct syntax of the instruction
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value - value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* MUL Instruction */
void Opcode::Mul() {
	int old_value = 0;

	//check if the user enter the correct syntax of the instruction
	if (Utilities::validOperators(_opcode, 1)) {
		old_value = _mem->getRegister(EAX);
		ValuesHandler* value = new ValuesHandler(_opcode->getBranches()[0]->getData(), _mem);
		_mem->setRegister(EAX, old_value * value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* DIV Instruction */
void Opcode::Div() {
	int old_value = 0;

	//check if the user enter the correct syntax of the instruction
	if (Utilities::validOperators(_opcode, 1)) {
		old_value = _mem->getRegister(EAX);
		ValuesHandler* value = new ValuesHandler(_opcode->getBranches()[0]->getData(), _mem);
		_mem->setRegister(EAX, old_value / value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* INC Instruction */
void Opcode::Inc() {

	//check if the user enter the correct syntax of the instruction
	if (Utilities::validOperators(_opcode, 1)) {		
		_mem->setRegister(_opcode->getBranches()[0]->getData(), _mem->getRegister(_opcode->getBranches()[0]->getData()) + 1);
	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* DEC Instruction */
void Opcode::Dec() {

	//check if the user enter the correct syntax of the instruction
	if (Utilities::validOperators(_opcode, 1)) {
		_mem->setRegister(_opcode->getBranches()[0]->getData(), _mem->getRegister(_opcode->getBranches()[0]->getData()) - 1);
	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* OR Instruction */
void Opcode::Or(){
	int old_value = 0;

	//check if the user enter the correct syntax of the instruction
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value | value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* AND Instruction */
void Opcode::And() {
	int old_value = 0;

	//check if the user enter the correct syntax of the instruction
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value & value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* XOR Instruction */
void Opcode::Xor() {
	int old_value = 0;

	//check if the user enter the correct syntax of the instruction
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value ^ value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* NOT Instruction */
void Opcode::Not() {

	//check if the user enter the correct syntax of the instruction
	if (Utilities::validOperators(_opcode, 1)) {
		_mem->setRegister(_opcode->getBranches()[0]->getData(), ~_mem->getRegister(_opcode->getBranches()[0]->getData()));
	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* NOP Instruction */
void Opcode::Nop() {

	//check if the user enter the correct syntax of the instruction
	if (!Utilities::validOperators(_opcode, 0))
		throw SyntaxError("Opcode Error - opcode syntax not valid.");	
}

/* SHL Instruction */
void Opcode::Shl() {
	int old_value = 0;

	//check if the user enter the correct syntax of the instruction
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value << value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* SHR Instruction */
void Opcode::Shr() {
	int old_value = 0;

	//check if the user enter the correct syntax of the instruction
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value >> value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* ROR Instruction */
void Opcode::Rol() {
	int old_value = 0;

	//check if the user enter the correct syntax of the instruction
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value << value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* ROR Instruction */
void Opcode::Ror() {
	int old_value = 0;

	//check if the user enter the correct syntax of the instruction
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value >> value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}
