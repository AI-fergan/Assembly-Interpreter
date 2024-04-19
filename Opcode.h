#pragma once
#include "Utilities.h"
#include "Pch.h"
#include "AstNode.h"
#include "SyntaxError.h"
#include "MemStore.h"
#include "ValuesHandler.h"

class MemStore;
class AstNode;
/*
* This class used to run opcde by given Ast Node.
*/
class Opcode
{
public:
	Opcode(AstNode* opcode, MemStore* mem);
	void run();

private:
	AstNode* _opcode;
	MemStore* _mem;

	void MOV();
	void ADD();
	void SUB();
	void MUL();
	void DIV();
	void INC();
	void DEC();
	void OR();
	void AND();
	void XOR();
	void NOT();
	void NOP();
	void SHL();
	void SHR();
	void ROL();
	void ROR();
	void PUSH();
	void POP();
	void CMP();
	void JNZ();
	void JZ();
	void JE();
	void JNE();
	void JS();
	void JNS();
<<<<<<< HEAD
=======
	void JO();
	void JNO();

<<<<<<< HEAD
>>>>>>> c6cdae8 (Added jump = JMP command)
=======
>>>>>>> c6cdae8 (Added jump = JMP command)
};
