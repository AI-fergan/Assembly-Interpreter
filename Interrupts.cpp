#include "Interrupts.h"

/*
* This c'tor create the main interrupt build.
*/
Interrupts::Interrupts(MemStore* mem) {
	this->_mem = mem;
}

/*
* This function help us to handle all the Interrupts by interrupt number.
* Input:
* interrupt - the number of the interrupt.
* Output: NULL.
*/
void Interrupts::interruptsHandler(unsigned int interrupt) {

	//check if the interrupts flag is true
	if (!_mem->_flags.IF)
		return;

	//check which interrupt match that number
	switch (interrupt)
	{
	case 0:
		INT_0(_mem);
		break;
	case 1:
		INT_1(_mem);
		break;
	case 3:
		INT_3(_mem);
		break;
	case 4:
		INT_4(_mem);
		break;
	case 6:
		INT_6(_mem);
		break;
	case 12:
		INT_12(_mem);
		break;
	case 22:
		INT_22(_mem);
		break;

	default:
		throw Error("IntError - Interrupt not found");
		break;
	}
}

/* Interrupt 0 */
void Interrupts::INT_0(MemStore* mem) {
	throw Error("DivideError - Divide by zero");
}

/* Interrupt 1 */
void Interrupts::INT_1(MemStore* mem) {
	system("pause");
}

/* Interrupt 3 */
void Interrupts::INT_3(MemStore* mem) {
	system("pause");
}

/* Interrupt 4 */
void Interrupts::INT_4(MemStore* mem) {
	mem->_flags.OF = true;
	throw Error("MemoryError - Overflow");
}

/* Interrupt 6 */
void Interrupts::INT_6(MemStore* mem) {
	throw Error("OpcodeError - opcode not found.");
}

/* Interrupt 12 */
void Interrupts::INT_12(MemStore* mem) {
	mem->_flags.OF = true;
	throw StackError("MemoryError - Stack Overflow");
}

/* Interrupt 22 */
void Interrupts::INT_22(MemStore* mem) {
	mem->setRegister(AH, _getch());
}
