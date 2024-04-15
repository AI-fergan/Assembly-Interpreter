#include "ValuesHandler.h"

ValuesHandler::ValuesHandler(string value, MemStore* mem) {
    this->_value = value;
    this->_mem = mem;
}

int ValuesHandler::handler() {
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

bool ValuesHandler::isHex()
{
    bool syntax = false;

    if (_value[_value.size() - 1] == 'h') {
        _value[_value.size() - 1] = 0;
        syntax = true;
    }

    if (_value.size() > 2 && _value[0] == '0' && _value[1] == 'x'){
        _value[0] = '0';
        _value[1] = '0';
        syntax = true;
    }

    if (syntax) {
        for (int i = 0; _value[i] != 0; i++)
            if (!isxdigit(_value[i]) && !isdigit(_value[i]))
                return false;    

        return true;
    }
       
    return false;
}

bool ValuesHandler::isDec()
{
    for (int i = 0; i < _value.size(); i++)
        if (!isdigit(_value[i]))
            return false;
        
    return true;
}

bool ValuesHandler::isOct()
{
    if (_value[_value.size() - 1] == 'o') {
        _value[_value.size() - 1] = 0;
        for (int i = 0; _value[i] != 0; i++)
            if (!isdigit(_value[i]) || _value[i] > '7')
                return false;
        return true;
    }

    return false;
}

bool ValuesHandler::isBin()
{
    if (_value[_value.size() - 1] == 'b') {
        _value[_value.size() - 1] = 0;
        for (int i = 0; _value[i] != 0; i++)
            if (_value[i] != '0' && _value[i] != '1')
                return false;
        return true;
    }

    return false;
}

bool ValuesHandler::isReg() {
    return _mem->isRegister(_value);
}
