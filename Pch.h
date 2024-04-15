#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <tuple>
#include <string>
#include <algorithm>

using std::string;
using std::cin;
using std::vector;
using std::queue;
using std::exception;
using std::map;
using std::tuple;
using std::cout;
using std::replace;
using std::cerr;
using std::endl;
using std::stoi;

#define OPCODES 100
#define OPERATORS 200

#define END_OF_LINE ';'

#define TOKEN 0
#define OPCODE 1
#define OPERATOR 2

#define EAX "eax"
#define EBX "ebx" 
#define ECX "ecx"
#define EDX "edx"