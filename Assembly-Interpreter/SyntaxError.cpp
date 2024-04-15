#include "SyntaxError.h"

SyntaxError::SyntaxError(string error) : Exceptions(error) 
{ /**/ }

const char* SyntaxError::what() {
	return "Syntax Error: ";
}
