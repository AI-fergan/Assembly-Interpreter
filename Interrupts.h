#pragma once
#include "Error.h"
#include "Pch.h"
#include "MemStore.h"

class Interrupts {
public:
	static void INT_0(MemStore* mem);
	static void INT_22(MemStore* mem);

};