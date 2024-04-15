#include "Utilities.h"

map<string, Opcodes> Utilities::OpcodesChars = {
    {"mov", Opcodes::mov},
    {"sub", Opcodes::sub},
    {"add", Opcodes::add}
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

bool Utilities::isOpcode(string op) {
    for (const auto entry : OpcodesChars) {
        if (entry.first == op) {
            return true;
        }
    }

    return false;
}

bool Utilities::isOperator(char ch) {
    for (const auto entry : OperatorsChars) {
        if (entry.first == ch) {
            return true;
        }
    }
    
    return false;
}

bool Utilities::isIgnored(char ch)
{
    for (const auto entry : IgnoredChars) {
        if (entry.first == ch) {
            return true;
        }
    }

    return false;
}

Opcodes Utilities::getOpcode(string op)
{
    if(isOpcode(op))
        return (*OpcodesChars.find(op)).second;
    return Opcodes::none;
}

Operators Utilities::getOperator(char ch)
{
    if (isOperator(ch))
        return (*OperatorsChars.find(ch)).second;
    return Operators::none;

}

int Utilities::StringToDec(string num)
{
    return stoi(num);
}

int Utilities::HexStringToDec(string num)
{
    return 0;
}

int Utilities::BinStringToDec(string num)
{
    return 0;
}

int Utilities::OctStringToDec(string num)
{
    return 0;
}

void Utilities::cleanString(string& str)
{
    string clean = "";
    for (char ch : str) {
        if (ch != ' ') {
            clean += ch;
        }
    } 

    str = clean;
}

bool Utilities::validparams(AstNode* opcode, int params) {
    if (opcode->getBranches()[0]->getBranches().size() == params)
        return true;    
    return false;
}

bool Utilities::validOperators(AstNode* opcode, int operators) {
    if (opcode->getBranches().size() == operators)
        return true;
    return false;
}

string Utilities::getParam(AstNode* opcode, int param) {
    return opcode->getBranches()[0]->getBranches()[param]->getData();
}

void Utilities::toLower(string& str) {
    string result = "";

    for (char ch : str) {
        result += tolower(ch);
    }

    str = result;
}
