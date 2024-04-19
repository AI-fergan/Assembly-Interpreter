#include "Opcode.h"

/*
* This c'tor init the opcode settings;
* Input:
* opcode - the opcode Node.
* mem - the memory area to run the opcode.
*/
Opcode::Opcode(AstNode* opcode, MemStore* mem) {
	this->_opcode = opcode;
	this->_mem = mem;
}

/*
* This function checks to which opcode the Node match and run that opcode.
* Output: NULL.
*/
void Opcode::run()
{
	//check to which opcode the Node match
	switch (Utilities::getOpcode(_opcode->getData())) {
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
	case Opcodes::Pop:
		Pop();
		break;
	case Opcodes::Push:
		Push();
		break;
	case Opcodes::Cmp:
		Cmp();
		break;
	case Opcodes::Jnz:
		Jnz();
		break;
	case Opcodes::Jz:
		Jz();
		break;
	}
}

/* MOV opcode */
void Opcode::Mov() {
	//check if the user enter the correct syntax of the opcode
	if(Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);		
		_mem->setRegister(Utilities::getParam(_opcode, 0), value->handler());
	}
	else {
		throw SyntaxError("OpcodeError - opcode syntax not valid.");
	}
}

/* ADD opcode */
void Opcode::Add() {
	unsigned int old_value = 0, num = 0;
	unsigned int size = 0, max = 0;

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		size = _mem->getRegisterSize(Utilities::getParam(_opcode, 0));
		num = value->handler() + old_value;
		max = static_cast<uint64_t>(pow(2, 8 * size)) - 1;
		//check if the value is out of range
		if ((max < num && (value->handler() - 1) < max) || num == 0) {
			num = max & num;
			_mem->_flags.CF = true;
		}
		else {
			_mem->_flags.CF = false;
		}
		_mem->setRegister(Utilities::getParam(_opcode, 0), num);

	}
	else {
		throw SyntaxError("OpcodeError - opcode syntax not valid.");
	}
}

/* SUB opcode */
void Opcode::Sub() {
	unsigned int old_value = 0, num = 0;
	unsigned int size, max;

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		size = _mem->getRegisterSize(Utilities::getParam(_opcode, 0));
		num = old_value - value->handler();
		max = static_cast<uint64_t>(pow(2, 8 * size)) - 1;

		//check if the value is out of range
		if (max < num || num == max) {
			num = max & num;
			_mem->_flags.CF = true;
		}
		else {
			_mem->_flags.CF = false;
		}

		_mem->setRegister(Utilities::getParam(_opcode, 0), num);

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* MUL opcode */
void Opcode::Mul() {
	int old_value = 0;

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1)) {
		old_value = _mem->getRegister(EAX);
		ValuesHandler* value = new ValuesHandler(_opcode->getBranches()[0]->getData(), _mem);
		_mem->setRegister(EAX, old_value * value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* DIV opcode */
void Opcode::Div() {
	int old_value = 0;

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1)) {
		old_value = _mem->getRegister(EAX);
		ValuesHandler* value = new ValuesHandler(_opcode->getBranches()[0]->getData(), _mem);
		if (old_value % value->handler() != 0)
			_mem->setRegister(EDX, old_value % value->handler());
		_mem->setRegister(EAX, old_value / value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* INC opcode */
void Opcode::Inc() {

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1)) {		
		_mem->setRegister(_opcode->getBranches()[0]->getData(), _mem->getRegister(_opcode->getBranches()[0]->getData()) + 1);
	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* DEC opcode */
void Opcode::Dec() {

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1)) {
		_mem->setRegister(_opcode->getBranches()[0]->getData(), _mem->getRegister(_opcode->getBranches()[0]->getData()) - 1);
	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* OR opcode */
void Opcode::Or(){
	int old_value = 0;

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value | value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* AND opcode */
void Opcode::And() {
	int old_value = 0;

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value & value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* XOR opcode */
void Opcode::Xor() {
	int old_value = 0;

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value ^ value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* NOT opcode */
void Opcode::Not() {

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1)) {
		_mem->setRegister(_opcode->getBranches()[0]->getData(), ~_mem->getRegister(_opcode->getBranches()[0]->getData()));
	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* NOP opcode */
void Opcode::Nop() {

	//check if the user enter the correct syntax of the opcode
	if (!Utilities::validOperators(_opcode, 0))
		throw SyntaxError("Opcode Error - opcode syntax not valid.");	
}

/* SHL opcode */
void Opcode::Shl() {
	int old_value = 0;

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value << value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* SHR opcode */
void Opcode::Shr() {
	int old_value = 0;

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value >> value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* ROR opcode */
void Opcode::Rol() {
	int old_value = 0;

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value << value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* ROR opcode */
void Opcode::Ror() {
	int old_value = 0;

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		old_value = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);
		_mem->setRegister(Utilities::getParam(_opcode, 0), old_value >> value->handler());

	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* PUSH opcode */
void Opcode::Push() {

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1)) {
		ValuesHandler* value = new ValuesHandler(_opcode->getBranches()[0]->getData(), _mem);
		_mem->push(value->handler());
	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* POP opcode */
void Opcode::Pop() {

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1)) {
		_mem->setRegister(_opcode->getBranches()[0]->getData(), _mem->pop());
	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* CMP opcode */
void Opcode::Cmp() {
	int value_1 = 0;

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1) && Utilities::validparams(_opcode, 2)) {
		value_1 = _mem->getRegister(Utilities::getParam(_opcode, 0));
		ValuesHandler* value_2 = new ValuesHandler(Utilities::getParam(_opcode, 1), _mem);

		//check if the numbers are equal
		if (value_1 == value_2->handler()) {
			_mem->_flags.ZF = true;
		}
		else{
			_mem->_flags.ZF = false;
		}
	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* JNZ opcode */
void Opcode::Jnz() {

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1)) {
		ValuesHandler* place = new ValuesHandler(_opcode->getBranches()[0]->getData(), _mem);

		//check if the flag ZF is 0
		if (!_mem->_flags.ZF){
			_mem->jmp(place->handler());
		}
	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}

/* JZ opcode */
void Opcode::Jz() {

	//check if the user enter the correct syntax of the opcode
	if (Utilities::validOperators(_opcode, 1)) {
		ValuesHandler* place = new ValuesHandler(_opcode->getBranches()[0]->getData(), _mem);

		//check if the flag ZF is 1
		if (_mem->_flags.ZF) {
			_mem->jmp(place->handler());
		}
	}
	else {
		throw SyntaxError("Opcode Error - opcode syntax not valid.");
	}
}
