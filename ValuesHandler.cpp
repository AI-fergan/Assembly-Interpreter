#include "ValuesHandler.h"

/*
* This c'tor init the value handler with the value to handle on, and pointer to the memory.
* Input:
* value - the value to handle.
* mem - pointer to the memory.
*/
ValuesHandler::ValuesHandler(string value, MemStore* mem) {
    this->_value = value;
    this->_mem = mem;
}

/*
* This function check what is the format of the value and return the value in decimal format.
* Output: the value in decimal format.
*/
unsigned int ValuesHandler::handler() {
    if (isHex())
        return Utilities::HexStringToDec(_value);
    else if (isDec())
        return Utilities::StringToDec(_value);
    else if (isOct())
        return Utilities::OctStringToDec(_value);
    else if (isBin())
        return Utilities::BinStringToDec(_value);
    else if (isReg())
        return _mem->getRegister(_value);

    throw ValueError("TypeError - Value type not valid.");

    return 0;
}

/*
* This function check if the value is in Hexdecimal format.
* Output: if the value is in Hexdecimal format.
*/
bool ValuesHandler::isHex()
{
    bool syntax = false;

    //first type of hex format
    if (_value.back() == 'h') {
        _value = "0x" + _value;
        _value.pop_back();
        syntax = true;
    }

    //second type of hex format
    if (_value.size() > 2 && _value.front() == '0' && _value[1] == 'x') {
        syntax = true;
    }

    //check if the format syntax is valid
    if (syntax) {
        istringstream iss(_value);
        unsigned int value;
        iss >> hex >> value;
        return !iss.fail() && iss.eof();
    }
       
    return false;
}

/*
* This function check if the value is in Decimal format.
* Output: if the value is in Decimal format.
*/
bool ValuesHandler::isDec()
{
    //loop over all the numbers
    for (int i = 0; i < _value.size(); i++)
        if (!isdigit(_value[i]))
            return false;
        
    return true;
}

/*
* This function check if the value is in Octal format.
* Output: if the value is in Octal format.
*/
bool ValuesHandler::isOct()
{
    //octal format
    if (_value.back() == 'o') {
        _value.pop_back();
        
        //check if the number is octal
        istringstream iss(_value);
        unsigned int value;
        iss >> oct >> value;

        _value.push_back('o');

        return !iss.fail() && iss.eof();
    }

    return false;
}

/*
* This function check if the value is in Binary format.
* Output: if the value is in Binary format.
*/
bool ValuesHandler::isBin()
{
    //binary format
    if (_value.back() == 'b') {
        _value.pop_back();
        //loop over all the Bits
        for (int i = 0; _value[i] != 0; i++)
            //check if the Bit value is valid
            if (_value[i] != '0' && _value[i] != '1') {
                _value.push_back('b');
                return false;
            }
        _value.push_back('b');
        return true;
    }

    return false;
}

/*
* This function check if the value is name of Register.
* Output: if the value is name of register.
*/
bool ValuesHandler::isReg() {
    return _mem->isRegister(_value);
}
