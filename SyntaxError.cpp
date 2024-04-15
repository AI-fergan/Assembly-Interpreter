#include "SyntaxError.h"

/*
* This c'tor gets the error message and store it in the error field.
* Input:
* error - the error message.
*/
SyntaxError::SyntaxError(string error) : Exceptions(error) 
{ /**/ }

/*
* This function return the syntax error message.
* Output: the error message.
*/
const char* SyntaxError::what() {
	return "Syntax Error: ";
}
