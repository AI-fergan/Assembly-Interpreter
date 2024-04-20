#include "Error.h"

/*
* This c'tor gets the error message and store it in the error field.
* Input:
* error - the error message.
*/
Error::Error(string error) : Exceptions(error)
{ /**/
}

/*
* This function return the value error message.
* Output: the error message.
*/
const char* Error::what() {
	return "Error: ";
}
