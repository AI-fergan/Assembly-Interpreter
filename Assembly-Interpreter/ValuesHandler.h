#pragma once
#include "Pch.h"
#include "MemStore.h"
#include "ValueError.h"

class ValuesHandler {
public:
	ValuesHandler(string value, MemStore* mem);
	int handler();

private:
	string _value;
	MemStore* _mem;

	bool isHex();
	bool isDec();
	bool isOct();
	bool isBin();

	bool isReg();
};
