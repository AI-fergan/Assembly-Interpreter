#include "StackError.h"

/*
* This c'tor gets the error message and store it in the error field.
* Input:
* error - the error message.
*/
StackError::StackError(string error) : Exceptions(error)
{ /**/
}

/*
* This function return the stack error message.
* Output: the error message.
*/
const char* StackError::what() {
	return "StackError: ";
}
