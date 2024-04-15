#include "ValuesHandler.h"

ValuesHandler::ValuesHandler(string value, MemStore* mem){
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

    return 0;
}

bool ValuesHandler::isHex()
{
    if (_value[_value.size() - 1] == 'h' || (_value.size() > 2 && _value[0] == '0' && _value[1] == 'x'))
        return true;
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
    if (_value[_value.size() - 1] == 'o')
        return true;
    return false;
}

bool ValuesHandler::isBin()
{
    if (_value[_value.size() - 1] == 'b')
        return true;
    return false;
}

bool ValuesHandler::isReg() {
    return _mem->isRegister(_value);
}
