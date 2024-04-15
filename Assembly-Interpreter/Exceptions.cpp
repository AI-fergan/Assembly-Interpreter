#include "Exceptions.h"

Exceptions::Exceptions(string error) {
	_error = error;
}

string Exceptions::getError() {
	return _error;
}