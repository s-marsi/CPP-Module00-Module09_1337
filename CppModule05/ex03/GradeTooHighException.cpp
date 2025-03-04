#include "GradeTooHighException.hpp"

const char * TooHighException::what() const throw() 
{
    return ("Grade is too high!\n");
}