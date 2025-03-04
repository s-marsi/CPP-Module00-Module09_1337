#pragma once

#include <iostream>

class FormNotSignedException: public std::exception
{
    public :
        virtual const char *what() const throw();
};