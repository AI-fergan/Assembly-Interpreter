#include "MemStore.h"

MemStore::MemStore() {
	_registers[EAX] = 0;
	_registers[EBX] = 0;
	_registers[ECX] = 0;
	_registers[EDX] = 0;
}

bool MemStore::setRegister(string reg, int value) {
	Utilities utilities;
	utilities.toLower(reg);

	if (_registers.find(reg) == _registers.end())
		return false;

	_registers[reg] = value;

	return true;
}


int MemStore::getRegister(string reg) {
	return _registers[reg];
}
