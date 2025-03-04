#pragma once

#include <iostream>

class TooLowException: public std::exception
{
    public:
        virtual const char * what() const throw();
};