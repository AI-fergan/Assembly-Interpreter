#pragma once
#include "Pch.h"
#include <unordered_map>

#define OPCODES 100
#define OPERATORS 200

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

	static map<string, Opcodes> OpcodesChars;
	static map<char, Operators> OperatorsChars;
	static map<char, Operators> IgnoredChars;
};