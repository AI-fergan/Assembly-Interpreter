#pragma once
#include "Pch.h"
#include "MemStore.h"
#include "ValueError.h"

class MemStore;

/*
* This class used to handle every value format that the user input.
*/
class ValuesHandler {
public:
	ValuesHandler(string value, MemStore* mem);
	unsigned int handler();

private:
	string _value;
	MemStore* _mem;

	bool isHex();
	bool isDec();
	bool isOct();
	bool isBin();

	bool isReg();
};
