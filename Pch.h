#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <tuple>
#include <string>
#include <algorithm>
#include<tuple>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <iomanip>

using std::oct;
using std::istringstream;
using std::reverse;
using std::stoul;
using std::setw;
using std::setfill;
using std::hex;
using std::make_tuple;
using std::stringstream;
using std::tuple;
using std::string;
using std::cin;
using std::vector;
using std::queue;
using std::exception;
using std::unordered_map;
using std::map;
using std::tuple;
using std::cout;
using std::replace;
using std::cerr;
using std::endl;
using std::stoi;
using std::get;

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

#define AX "ax"
#define BX "bx"
#define CX "cx"
#define DX "dx"

#define AL "al"
#define BL "bl"
#define CL "cl"
#define DL "dl"

#define ESP "esp"
#define EBP "ebp"
