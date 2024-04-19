#pragma once
#include "Pch.h"
#include "AstNode.h"
#include "ValueError.h"
#include "MemStore.h"

class AstNode;
class MemStore;

enum class Opcodes {
	None = -1,
	Mov = OPCODES,
	Sub,
	Add,
	Mul,
	Div,
	Inc,
	Dec,
	Or,
	And,
	Xor,
	Not,
	Nop,
	Shl,
	Shr,
	Rol,
	Ror,
	Push,
	Pop,
	Cmp,
	Jnz,
	Jz

};

enum class Operators {
	none = -1,
	mns = OPERATORS,
	pls,
	mul,
	comma,
	space
};

/*
* This class help us to make the Interpreter code more clean and easy to read and write.
*/
class Utilities {
public:	
	static bool isOpcode(string op);
	static bool isOperator(char ch);
	static bool isIgnored(char ch);

	static Opcodes getOpcode(string op);
	static Operators getOperator(char ch);

	static unsigned int StringToDec(string num);
	static unsigned int HexStringToDec(string num);
	static unsigned int BinStringToDec(string num);
	static unsigned int OctStringToDec(string num);
	static void cleanString(string& str);

	static bool validparams(AstNode* opcode, int params);
	static bool validOperators(AstNode* opcode, int operators);
	static string getParam(AstNode* opcode, int param);

	static void toLower(string& str);


	static map<string, Opcodes> OpcodesChars;
	static map<char, Operators> OperatorsChars;
	static map<char, Operators> IgnoredChars;
};