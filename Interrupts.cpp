#include "Interrupts.h"

Interrupts::Interrupts(MemStore* mem) {
	this->_mem = mem;
}

void Interrupts::interruptsHandler(unsigned int interrupt) {
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
	case 4:
		INT_4(_mem);
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
	throw StackError("MemoryError - Stack overflow");
}

/* Interrupt 22 */
void Interrupts::INT_22(MemStore* mem) {
	mem->setRegister(AH, _getch());
}
