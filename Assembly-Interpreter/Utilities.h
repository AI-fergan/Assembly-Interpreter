#pragma once
#include "Pch.h"

#define OPCODES 100
#define OPERATORS 200

enum Opcodes {
	mov = OPCODES,
	sub,
	add
};

enum Operators {
	sub = OPERATORS,
	add,
	mul,
	div,
	dot,
	comma
};

map<Opcodes, string> OpcodesChars = {
	"mov", Opcodes::mov,
	"sub", Opcodes::sub,
	"add", Opcodes::add };
};

map<Operators, char> OperatorsChars = {

};