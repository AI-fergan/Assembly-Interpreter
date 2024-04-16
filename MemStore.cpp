#include "MemStore.h"

/*
* This c'tor init all the memory configs.
*/
MemStore::MemStore() {
	//create the registers memory spaces
	_registers[make_tuple(EAX, AX, AL)] = 0;
	_registers[make_tuple(EBX, BX, BL)] = 0;
	_registers[make_tuple(ECX, CX, CL)] = 0;
	_registers[make_tuple(EDX, DX, DL)] = 0;
	_registers[make_tuple(ESP, ESP, ESP)] = 0xFFFFFFFF;
	_registers[make_tuple(EBP, EBP, EBP)] = 0;

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


	if (reg == ESP) {
		push(value);
		throw RegisterError("MemoryError - Cannot access that register");
	}

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
bool MemStore::isRegister(string reg) {
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
* This function used to push values into the stack.
* Input:
* value - the value to push.
* Output: NULL.
*/
void MemStore::push(int value) {
	_stack.push_back(value);
	_registers[make_tuple(ESP, ESP, ESP)] = getRegister(ESP) - sizeof(char[2]);
}

/*
* This function used to pop values from the stack.
* Output: the last value that push into the stack.
*/
int MemStore::pop() {

	//check if the stack has values to pop
	if (!_stack.empty()) {
		int value = _stack.back();
		_stack.pop_back();
		_registers[make_tuple(ESP, ESP, ESP)] = getRegister(ESP) + sizeof(char[2]);

		return value;
	}
	//error when the stack is empty
	else {
		throw StackError("MemoryError - Stack underflow");
	}
}

/*
* This function print the memory to the screen.
* Output: NULL.
*/
void MemStore::printMemory(){
	stringstream reg_1, reg_2;

	reg_1 << hex;
	reg_2 << hex;

	//loop over all the registers
	int i = 0xffff;
	for (auto start = _registers.begin(); start != _registers.end(); ++start) {
		//check if there is more registers access part
		if (std::get<0>(start->first) != std::get<1>(start->first)) {
			reg_1 << std::get<0>(start->first) << ": 0x" << setw(8) << setfill('0') << _registers[start->first];
			reg_1 << " | " << std::get<1>(start->first) << ": 0x" << setw(8) << setfill('0') << _registers[start->first];
			reg_1 << " | " << std::get<2>(start->first) << ": 0x" << setw(8) << setfill('0') << _registers[start->first] << endl;
		}
		else {
			reg_2 << std::get<0>(start->first) << ": 0x" << setw(8) << setfill('0') << _registers[start->first] << endl;
		}
	}

	//print the registers names and values to the screen
	cout << reg_1.str() << reg_2.str();

	//print the stack frame
	if (!_stack.empty()) {
		cout << endl << "Stack frame:" << endl << " ----------" << endl;
		//loop over all the stack elements
		for (int element : _stack) {
			printf("|0x%08x| -> 0x%04x\n", element, i);
			cout << " ----------" << endl;
			i -= sizeof(char[2]);
		}
	}
	
}
