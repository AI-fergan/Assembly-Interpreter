#include "ValueError.h"

/*
* This c'tor gets the error message and store it in the error field.
* Input:
* error - the error message.
*/
ValueError::ValueError(string error) : Exceptions(error)
{ /**/ }

/*
* This function return the value error message.
* Output: the error message.
*/
const char* ValueError::what() {
	return "ValueError: ";
}
