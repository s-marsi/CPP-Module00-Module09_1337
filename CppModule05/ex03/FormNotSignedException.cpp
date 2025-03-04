#include "FormNotSignedException.hpp"

const char *FormNotSignedException::what() const throw()
{
    return ("Form not signed.\n");
}
