#pragma once
#include "Pch.h"
#include <unordered_map>
#include "AstNode.h"

class AstNode;

enum class Opcodes {
	none = -1,
	mov = OPCODES,
	sub,
	add
};

enum class Operators {
	none = -1,
	mns = OPERATORS,
	pls,
	mul,
	comma,
	space
};


static class Utilities {
public:
	static bool isOpcode(string op);
	static bool isOperator(char ch);
	static bool isIgnored(char ch);

	static Opcodes getOpcode(string op);
	static Operators getOperator(char ch);

	static int StringToDec(string num);
	static int HexStringToDec(string num);
	static int binaryStringToDec(string num);

	static void cleanString(string& str);

	bool validparams(AstNode* opcode, int params);
	bool validOperators(AstNode* opcode, int operators);

	static map<string, Opcodes> OpcodesChars;
	static map<char, Operators> OperatorsChars;
	static map<char, Operators> IgnoredChars;
};