#include "RegisterError.h"

RegisterError::RegisterError(string error) : Exceptions(error)
{ /**/ }

const char* RegisterError::what() {
    return "RegisterError: ";
}
