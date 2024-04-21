#include "MemStore.h"

/*
* This c'tor init all the memory configs.
*/
MemStore::MemStore() {
	//create the registers memory spaces
	_registers[make_tuple(EAX, AX, AH, AL)] = 0;
	_registers[make_tuple(EBX, BX, BH, BL)] = 0;
	_registers[make_tuple(ECX, CX, CH, CL)] = 0;
	_registers[make_tuple(EDX, DX, DH, DL)] = 0;
	_registers[make_tuple(ESP, ESP, ESP, ESP)] = 0xFFFFFFFF;
	_registers[make_tuple(EBP, EBP, EBP, EBP)] = 0;
	_registers[make_tuple(EIP, EIP, EIP, EIP)] = 0;

	cleanFlags();
}

/*
* This function set value into register.
* Input:
* reg - the register name.
* value - the value to set into the register.
* Output: NULL.
*/
void MemStore::setRegister(string reg, unsigned int value) {

	//cannot edit the ESP register
	if (reg == ESP) {
		push(value);
		throw RegisterError("MemoryError - Cannot access that register");
	}
	//cannot edit the EIP register
	else if (reg == EIP) {
		throw RegisterError("MemoryError - Cannot access that register");
	}

	//check if the register exists
	for (auto start = _registers.begin(); start != _registers.end(); ++start) {
		//32 bit register
		if (reg == std::get<0>(start->first)){

			//set AF flag
			if (((value & 0xF) ^ (_registers[start->first] & 0xF)) == 0xF)
				_flags.AF = true;
			else
				_flags.AF = false;

			//32 bit register
			_registers[start->first] = value;

			//set ZF flag
			if (value == 0)
				_flags.ZF = true;
			else
				_flags.ZF = false;

			//set SF flag
			if ((value & 0x80000000) != 0)
				_flags.SF = true;
			else
				_flags.SF = false;

			//set PF flag
			if ((value & 0x1) == 0)
				_flags.PF = true;
			else
				_flags.PF = false;

			return;
		}
		//16 bit register
		else if (reg == std::get<1>(start->first)) {
			//check if the size of the value is valid
			if (value != (0xFFFF & value)) {
				throw ValueError("SizeError - Invalid value size.");
			}			

			//set AF flag
			if (((value & 0xF) ^ (_registers[start->first] & 0xF)) == 0xF)
				_flags.AF = true;
			else
				_flags.AF = false;

			_registers[start->first] = (_registers[start->first] ^ (_registers[start->first] & 0xFFFF)) + value;

			//set ZF flag
			if (value == 0)
				_flags.ZF = true;
			else
				_flags.ZF = false;

			//set SF flag
			if ((value & 0x8000) != 0)
				_flags.SF = true;
			else
				_flags.SF = false;

			//set PF flag
			if ((value & 0x1) == 0)
				_flags.PF = true;
			else
				_flags.PF = false;

			return;
		}
		//8 bit register
		else if (reg == std::get<2>(start->first)) {
			//check if the size of the value is valid
			if (value != (0xFF & value)) {
				throw ValueError("SizeError - Invalid value size.");
			}

			//set AF flag
			if (((value & 0xF) ^ ((_registers[start->first] >> 8) & 0xF)) == 0xF)
				_flags.AF = true;
			else
				_flags.AF = false;

			_registers[start->first] = (_registers[start->first] ^ (_registers[start->first] & 0xFF00)) + ((value & 0xFF) << 8);

			//set ZF flag
			if (value == 0)
				_flags.ZF = true;
			else
				_flags.ZF = false;

			//set SF flag
			if ((value & 0x80) != 0)
				_flags.SF = true;
			else
				_flags.SF = false;

			//set PF flag
			if ((value & 0x1) == 0)
				_flags.PF = true;
			else
				_flags.PF = false;

			return;
		}
		//8 bit register
		else if (reg == std::get<3>(start->first)) {
			//check if the size of the value is valid
			if (value != (0xFF & value)) {
				throw ValueError("SizeError - Invalid value size.");
			}

			//set AF flag
			if (((value & 0xF) ^ (_registers[start->first] & 0xF)) == 0xF)
				_flags.AF = true;
			else
				_flags.AF = false;

			_registers[start->first] = (_registers[start->first] ^ (_registers[start->first] & 0xFF)) + value;

			//set ZF flag
			if (value == 0)
				_flags.ZF = true;
			else
				_flags.ZF = false;

			//set SF flag
			if ((value & 0x80) != 0)
				_flags.SF = true;
			else
				_flags.SF = false;

			//set PF flag
			if ((value & 0x1) == 0)
				_flags.PF = true;
			else
				_flags.PF = false;

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
unsigned int MemStore::getRegister(string reg){

	//get the value of the registers by loop over on the registers map
	for (auto start = _registers.begin(); start != _registers.end(); ++start) {
		//32 bit register
		if (reg == std::get<0>(start->first)) {
			return  _registers[start->first];			
		}
		//16 bit register
		else if (reg == std::get<1>(start->first)) {
			return _registers[start->first] & 0xFFFF;		
		}
		//8 bit register
		else if (reg == std::get<2>(start->first)) {
			return (_registers[start->first] >> 8) & 0xFF;			
		}
		//8 bit register
		else if (reg == std::get<3>(start->first)) {
			return _registers[start->first] & 0xFF;
		}
	}

	throw RegisterError("MemoryError - Register not found");

	return 0;
}

/*
* This function get register name and return the size in Bytes of that register.
* Input:
* reg - the register name.
* Output: the size of the register in bytes.
*/
int MemStore::getRegisterSize(string reg){

	//check if the register exists
	for (auto start = _registers.begin(); start != _registers.end(); ++start) {
		//32 bit register
		if (reg == get<0>(start->first)) {			
			return 4;
		}
		//16 bit register
		else if (reg == get<1>(start->first)) {			
			return 2;
		}
		//8 bit register
		else if (reg == get<2>(start->first)) {
			return 1;
		}
		//8 bit register
		else if (reg == get<3>(start->first)) {
			return 1;
		}
	}

	throw RegisterError("MemoryError - Register not found");
}

/*
*This function check if the register name exists.
* Input:
* reg - the register name.
* output: if the register name exists.
*/
bool MemStore::isRegister(string reg) {

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
		//8 bit register
		else if (reg == std::get<3>(start->first)) {
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
void MemStore::push(unsigned int value) {
	if (getRegister(ESP) != 0) {
		_stack.push_back(value);
		_registers[make_tuple(ESP, ESP, ESP, ESP)] = getRegister(ESP) - sizeof(unsigned int);
		_flags.OF = false;
	}
	else {
		Interrupts::INT_4(this);
	}
}

/*
* This function used to pop values from the stack.
* Output: the last value that push into the stack.
*/
unsigned int MemStore::pop() {

	//check if the stack has values to pop
	if (!_stack.empty()) {
		unsigned int value = _stack.back();
		_stack.pop_back();
		_registers[make_tuple(ESP, ESP, ESP, ESP)] = getRegister(ESP) + sizeof(unsigned int);
		_flags.OF = false;

		return value;
	}
	//error when the stack is empty
	else {
		Interrupts::INT_12(this);
	}
}

/*
* This function clean all the flags values and set them to false.
* Output: NULL.
*/
void MemStore::cleanFlags() {
	_flags.AF = false;
	_flags.CF = false;
	_flags.DF = false;
	_flags.IF = true;
	_flags.OF = false;
	_flags.PF = false;
	_flags.SF = false;
	_flags.ZF = false;
}

/*
* This function add opcode to the opcodes history.
* Input:
* opcode - the opcode that added to the history
* Output: NULL.
*/
void MemStore::addToHistory(Opcode* opcode, string line) {
	_history.push_back(make_tuple(opcode, line));

	//increase the EIP register which count the opcodes
	incEIP();
}

/*
* This function remove the last opcode from the history.
* Output: NULL.
*/
void MemStore::removeFromHistory() {
	//check if the history not empty
	if(_history.size())
		_history.pop_back();
}

/*
* This function use to get opcode from the history by its place.
* Input:
* place - the place of the opcode in the history
* Output: the opcode Object.
*/
Opcode* MemStore::getFromHistory(unsigned int place) {	
	return get<0>(_history[place]);
}

/*
* This function increase the EIP register which count the opcodes.
* Output: NULL.
*/
void MemStore::incEIP(){
	_registers[make_tuple(EIP, EIP, EIP, EIP)] = getRegister(EIP) + 1;
}

/*
* This function print the memory to the screen.
* Output: NULL.
*/
void MemStore::printMemory(){
	stringstream reg_1, reg_2;
	vector<unsigned int> stack = _stack;

	//get the stack elements from the last to the first
	reverse(stack.begin(), stack.end());

	//set the value type to hex
	reg_1 << hex;
	reg_2 << hex;

	//loop over all the registers
	unsigned int i = sizeof(unsigned int);
	cout << " Registers:" << endl;
	for (auto start = _registers.begin(); start != _registers.end(); ++start) {
		//check if there is more registers access part
		if (std::get<0>(start->first) != std::get<1>(start->first)) {
			reg_1 << "| " << get<0>(start->first) << ": 0x" << setw(8) << setfill('0') << getRegister(get<0>(start->first));
			reg_1 << " | " << get<1>(start->first) << ": 0x" << setw(4) << setfill('0') << getRegister(get<1>(start->first));
			reg_1 << " | " << get<2>(start->first) << ": 0x" << setw(2) << setfill('0') << getRegister(get<2>(start->first));
			reg_1 << " | " << get<3>(start->first) << ": 0x" << setw(2) << setfill('0') << getRegister(get<3>(start->first)) << "|" << endl;

		}
		else {
			reg_2 << "|" << get<0>(start->first) << ": 0x" << setw(8) << setfill('0') << getRegister(get<0>(start->first)) << "|" << endl;
		}
	}

	//print the registers names and values to the screen
	cout << " ----------------------------------------------------" << endl;
	cout << reg_1.str();
	cout << " ----------------------------------------------------" << endl;

	cout << " ---------------" << endl;
	cout << reg_2.str();
	cout << " ---------------" << endl;

	//print the flag register
	cout << " ---------------------------------------" << endl;
	cout << "|AF " << _flags.AF << "|CF " << _flags.CF << "|DF " <<_flags.DF << "|IF " << _flags.IF << "|OF " << _flags.OF << "|PF " << _flags.PF << "|SF " << _flags.SF << "|ZF " << _flags.ZF << "|" << endl;
	cout << " ---------------------------------------" << endl;	

	//print the stack frame
	if (!_stack.empty()) {
		cout << endl << " Stack frame:" << endl << " ----------" << endl;
		//loop over all the stack elements
		for (int element : stack) {
			printf("|0x%08x| -> 0x%04x\n", element, getRegister(ESP) + i);
			cout << " ----------" << endl;
			i += sizeof(unsigned int);
		}
	}
	
}

/*
* This function print th opcodes history.
* Output: NULL.
*/
void MemStore::printHistory() {
	int i = 0;

	//history title
	cout << "History:" << endl;
	
	//loop over all the opcodes in the history
	for (tuple<Opcode*, string> opcode : _history) {
		cout << "0x" << setw(4) << setfill('0') << i << ": " << get<1>(opcode) << endl;
		i++;
	}
}

/*
* This function used to jump to another opcodes and run them.
* Input:
* place - where shold the function start run opcodes.
* Output: NULL.
*/
void MemStore::jmp(unsigned int place){
	//check if the opcode is exist in the history
	if (getRegister(EIP) < place)
		throw;

	//loop over all the opcodes in the history
	while (place < getRegister(EIP)) {
		try {
			//get opcode from the history and run it
			getFromHistory(place)->run();
		} catch (Exceptions& e) {
		}
		place++;
	}
}

/*
* This function Add Identifiers to the Identifiers map.
* Input:
* name - the ID name.
* value - the ID value.
* Output: NULL.
*/
void MemStore::addIdentifier(string name, unsigned int value) {
	//check if the ID already exists
	if (_identifiers.find(name) != _identifiers.end())
		throw ValueError("IdentifierError - Id already exists.");

	_identifiers[name] = value;
}
