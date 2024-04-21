#pragma once
#include "Error.h"
#include "Pch.h"
#include "MemStore.h"

class Interrupts {
public:
	Interrupts(MemStore* mem);
	void interruptsHandler(unsigned int intinterrupt);

	static void INT_0(MemStore* mem);
	static void INT_1(MemStore* mem);
	static void INT_3(MemStore* mem);
	static void INT_4(MemStore* mem);
	static void INT_22(MemStore* mem);

private:
	MemStore* _mem;
};