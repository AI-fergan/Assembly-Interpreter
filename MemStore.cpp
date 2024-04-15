#include "MemStore.h"

/*
* This c'tor init all the memory configs.
*/
MemStore::MemStore() {
	//create the registers memory spaces
	_registers[EAX] = 0;
	_registers[EBX] = 0;
	_registers[ECX] = 0;
	_registers[EDX] = 0;
}

/*
* This function set value into register.
* Input:
* reg - the register name.
* value - the value to set into the register.
* Output: NULL.
*/
void MemStore::setRegister(string reg, int value) {
	Utilities::toLower(reg);

	//check if the register exists
	if (_registers.find(reg) == _registers.end())
		throw RegisterError("MemoryError - Register not exists");

	_registers[reg] = value;
}

/*
* This function get value of register.
* Input:
* reg - the register name.
* Output: the register value.
*/
int MemStore::getRegister(string reg) {
	Utilities::toLower(reg);

	//check if the register exists
	if (_registers.find(reg) == _registers.end())
		throw RegisterError("MemoryError - Register not exists");

	return _registers[reg];
}

/*
*This function check if the register name exists.
* Input:
* reg - the register name.
* output: if the register name exists.
*/
bool MemStore::isRegister(string reg)
{
	Utilities::toLower(reg);

	//check if the register exists
	if (_registers.find(reg) == _registers.end())
		return false;

	return true;
}

/*
* This function print the memory to the screen.
* Output: NULL.
*/
void MemStore::printMemory(){
	//loop over all the registers
	for (const auto entry : _registers) {
		cout << entry.first << ": " << entry.second << endl;
	}
}
