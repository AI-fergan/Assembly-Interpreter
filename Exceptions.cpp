#include "Exceptions.h"

/*
* This c'tor get error message and store it in her error field.
* Input:
* error - the error to store.
*/
Exceptions::Exceptions(string error) {
	_error = error;
}

/*
* This function return the error message.
* Output: the error mesaage.
*/
string Exceptions::getError() {
	return _error;
}