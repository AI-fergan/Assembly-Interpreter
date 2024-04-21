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

/* Interrupt 22 */
void Interrupts::INT_22(MemStore* mem) {
	mem->setRegister(AH, _getch());
}
