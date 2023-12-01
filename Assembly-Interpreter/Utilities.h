#pragma once
#include "Pch.h"
#include <unordered_map>

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
	comma
};

map<Opcodes, string> OpcodesChars = {
	{Opcodes::mov, "mov"},
	{Opcodes::sub, "sub"},
	{Opcodes::add, "add"}
};

map<Operators, char> OperatorsChars = {
	{Operators::sub, '-'},
	{Operators::add, '+'},
	{Operators::mul, '*'},
	{Operators::comma, ','}
};
