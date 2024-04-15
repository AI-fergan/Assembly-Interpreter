#include "MemStore.h"

MemStore::MemStore() {
	_registers[EAX] = 0;
	_registers[EBX] = 0;
	_registers[ECX] = 0;
	_registers[EDX] = 0;
}

void MemStore::setRegister(string reg, int value) {
	Utilities utilities;
	utilities.toLower(reg);

	if (_registers.find(reg) == _registers.end())
		throw RegisterError("MemoryError: Register not exists");

	_registers[reg] = value;
}


int MemStore::getRegister(string reg) {
	Utilities::toLower(reg);

	if (_registers.find(reg) == _registers.end())
		throw RegisterError("MemoryError: Register not exists");

	return _registers[reg];
}

bool MemStore::isRegister(string reg)
{
	Utilities::toLower(reg);

	if (_registers.find(reg) == _registers.end())
		return false;

	return true;
}

void MemStore::printMemory(){
	for (const auto entry : _registers) {
		cout << entry.first << ": " << entry.second << endl;
	}
}
