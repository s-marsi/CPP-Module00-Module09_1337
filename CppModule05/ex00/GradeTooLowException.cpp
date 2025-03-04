#include "GradeTooLowException.hpp"

const char * TooLowException::what() const throw() 
{
    return ("Grade is too low!\n");
}