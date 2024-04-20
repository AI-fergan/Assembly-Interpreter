#include "Interrupts.h"

/* Interrupt 0 */
void Interrupts::INT_0(MemStore* mem) {
	throw Error("DivideError - Divide by zero");
}

/* Interrupt 22 */
void Interrupts::INT_22(MemStore* mem) {
	unsigned int value = mem->getRegister(AX);
	value &= 0x00FF;
	value +=  _getch() << 8;
	mem->setRegister(AX, value);	
}
