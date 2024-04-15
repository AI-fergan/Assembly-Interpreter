#include "ValueError.h"

ValueError::ValueError(string error) : Exceptions(error)
{ /**/ }

const char* ValueError::what() {
	return "ValueError: ";
}
