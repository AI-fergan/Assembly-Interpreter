#include "Utilities.h"

map<string, Opcodes> Utilities::OpcodesChars = {
    {"MOV", Opcodes::MOV},
    {"SUB", Opcodes::SUB},
    {"ADD", Opcodes::ADD},
    {"MUL", Opcodes::MUL},
    {"DIV", Opcodes::DIV},
    {"INC", Opcodes::INC},
    {"DEC", Opcodes::DEC},
    {"OR", Opcodes::OR},
    {"AND", Opcodes::AND},
    {"XOR", Opcodes::XOR},
    {"NOT", Opcodes::NOT},
    {"NOP", Opcodes::NOP},
    {"SHL", Opcodes::SHL},
    {"SHR", Opcodes::SHR},
    {"ROL", Opcodes::ROL},
    {"ROR", Opcodes::ROR},
    {"POP", Opcodes::POP},
    {"PUSH", Opcodes::PUSH},
    {"CMP", Opcodes::CMP},
    {"JNZ", Opcodes::JNZ},
    {"JZ", Opcodes::JZ},
    {"JNE", Opcodes::JNE},
    {"JE", Opcodes::JE},
    {"JNS", Opcodes::JNS},
    {"JS", Opcodes::JS},
    {"JNO", Opcodes::JNO},
    {"JO", Opcodes::JO},
    {"JNP", Opcodes::JNP},
    {"JP", Opcodes::JP},
    {"JAE", Opcodes::JAE},
    {"JBE", Opcodes::JBE},
    {"LOOP", Opcodes::LOOP},
    {"XCHG", Opcodes::XCHG},
    {"INT", Opcodes::INT}
};

map<char, Operators> Utilities::OperatorsChars = {
    {'-', Operators::pls},
    {'+', Operators::mns},
    {'*', Operators::mul},
    {',', Operators::comma}
};

map<char, Operators> Utilities::IgnoredChars = {
    {' ', Operators::space}
};

/*
* This funtion get string and return if it could be an opcode.
* Input:
* op - the opcode string.
* Output: if its opcode.
*/
bool Utilities::isOpcode(string op) {
    //loop over all the opcodes map
    for (const auto entry : OpcodesChars) {
        if (entry.first == op) {
            return true;
        }
    }

    return false;
}

/*
* This funtion get char and return if it could be an operator.
* Input:
* op - the operator char.
* Output: if its operator.
*/
bool Utilities::isOperator(char ch) {
    //loop over all the operators map
    for (const auto entry : OperatorsChars) {
        if (entry.first == ch) {
            return true;
        }
    }
    
    return false;
}

/*
* This funtion get char and return if it could be an ignored char.
* Input:
* op - the char to check.
* Output: if its could be ignored char.
*/
bool Utilities::isIgnored(char ch) {
    //loop over all the ignored chars map
    for (const auto entry : IgnoredChars) {
        if (entry.first == ch) {
            return true;
        }
    }

    return false;
}

/*
* This function get string and return its opcode.
* Input:
* op - the opcode string.
* Output: the opcode.
*/
Opcodes Utilities::getOpcode(string op) {
    //check if the opcode exists
    if(isOpcode(op))
        return (*OpcodesChars.find(op)).second;
    return Opcodes::NONE;
}

/*
* This function get string and return its operator.
* Input:
* op - the operator string.
* Output: the operator.
*/
Operators Utilities::getOperator(char ch) {
    //check if the operator exists
    if (isOperator(ch))
        return (*OperatorsChars.find(ch)).second;
    return Operators::none;

}

/*
* This function convert from string to decimal value.
* Input:
* num - the number in string foramt.
* Output: the number in decimal format
*/
unsigned int Utilities::StringToDec(string num) {
    return stoul(num);    
}

/*
* This function convert from Hex string to decimal value.
* Input:
* num - the number in Hex string foramt.
* Output: the number in decimal format
*/
unsigned int Utilities::HexStringToDec(string num) {
    return stoul(num, nullptr, 16);
}

/*
* This function convert from Binary string to decimal value.
* Input:
* num - the number in Binary string foramt.
* Output: the number in decimal format
*/
unsigned int Utilities::BinStringToDec(string num) {
    return stoul(num, nullptr, 2);
}

/*
* This function convert from Octal string to decimal value.
* Input:
* num - the number in Octal string foramt.
* Output: the number in decimal format
*/
unsigned int Utilities::OctStringToDec(string num) {
    return stoul(num, nullptr, 8);
}

/*
* This function get string and clean all the space chars from the string.
* Input:
* str - the string to clean from space chars.
* Output: NULL.
*/
void Utilities::cleanString(string& str) {
    string clean = "";
    for (char ch : str) {
        if (ch != ' ') {
            clean += ch;
        }
    } 

    str = clean;
}

/*
* This function check if the number of the params that there is in the opcode branch is valid.
* Input:
* opcode - pointer to the opcode.
* params - the valid number of params to this opcode.
* Output: if the params number is valid or not.
*/
bool Utilities::validparams(AstNode* opcode, int params) {
    //check if the params number is valid
    if (opcode->getBranches()[0]->getBranches().size() == params)
        return true;    
    return false;
}

/*
* This function check if the number of the operators that there is in the opcode branch is valid.
* Input:
* opcode - pointer to the opcode.
* operators - the valid number of operators to this opcode.
* Output: if the operators number is valid or not.
*/
bool Utilities::validOperators(AstNode* opcode, int operators) {
    //check if the operators number is valid
    if (opcode->getBranches().size() == operators)
        return true;
    return false;
}

/*
* This function return param from any place on the opcode params branch.
* Input:
* opcode - pointer to the opcode.
* param - the place of the param on the opcode params branch.
* Output: string of the data that found in the place of the param in the opcode params branch.
*/
string Utilities::getParam(AstNode* opcode, int param) {
    return opcode->getBranches()[0]->getBranches()[param]->getData();
}

/*
* This function get string and set all the letters in the string to lower case format.
* Input:
* str - the string to edit.
* Output: NULL.
*/
void Utilities::toLower(string& str) {
    string result = "";

    //loop over all the string chars
    for (char ch : str) {
        result += tolower(ch);
    }

    str = result;
}

/*
* This function get string and set all the letters in the string to upper case format.
* Input:
* str - the string to edit.
* Output: NULL.
*/
void Utilities::toUpper(string& str) {
    string result = "";

    //loop over all the string chars
    for (char ch : str) {
        result += toupper(ch);
    }

    str = result;
}
