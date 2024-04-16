#include "MemStore.h"

/*
* This c'tor init all the memory configs.
*/
MemStore::MemStore() {
	//create the registers memory spaces
	_registers[std::make_tuple(EAX, AX, AL)] = 0;
	_registers[std::make_tuple(EBX, BX, BL)] = 0;
	_registers[std::make_tuple(ECX, CX, CL)] = 0;
	_registers[std::make_tuple(EDX, DX, DL)] = 0;

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
	for (auto start = _registers.begin(); start != _registers.end(); ++start) {
		if (reg == std::get<0>(start->first)){
			//32 bit register
			_registers[start->first] = value;
			return;
		}
		//32 bit register
		else if (reg == std::get<1>(start->first)) {
			_registers[start->first] = (_registers[start->first] ^ (_registers[start->first] & 0xFF)) + (0xFF & value);
			return;
		}
		//16 bit register
		else if (reg == std::get<2>(start->first)) {
			_registers[start->first] = (_registers[start->first] ^ (_registers[start->first] & 0xF)) + (0xF & value);
			return;
		}
	}

	throw RegisterError("MemoryError - Register not found");	
}

/*
* This function get value of register.
* Input:
* reg - the register name.
* Output: the register value.
*/
int MemStore::getRegister(string reg) {
	Utilities::toLower(reg);

	//get the value of the registers by loop over on the registers map
	for (auto start = _registers.begin(); start != _registers.end(); ++start) {
		//32 bit register
		if (reg == std::get<0>(start->first)) {
			return  _registers[start->first];			
		}
		//16 bit register
		else if (reg == std::get<1>(start->first)) {
			return _registers[start->first] & 0xFF;		
		}
		//8 bit register
		else if (reg == std::get<2>(start->first)) {
			return _registers[start->first] & 0xF;			
		}
	}

	throw RegisterError("MemoryError - Register not found");

	return 0;
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
	for (auto start = _registers.begin(); start != _registers.end(); ++start) {
		//32 bit register
		if (reg == std::get<0>(start->first)) {
			return  true;
		}
		//16 bit register
		else if (reg == std::get<1>(start->first)) {
			return true;
		}
		//8 bit register
		else if (reg == std::get<2>(start->first)) {
			return true;
		}
	}

	return false;
}

/*
* This function print the memory to the screen.
* Output: NULL.
*/
void MemStore::printMemory(){
	//loop over all the registers
	for (auto start = _registers.begin(); start != _registers.end(); ++start) {
		cout << std::get<0>(start->first) << ": " << _registers[start->first] << ", ";
		cout << std::get<1>(start->first) << ": " << _registers[start->first] << ", ";
		cout << std::get<2>(start->first) << ": " << _registers[start->first] << endl;
	}
}
