#pragma once

#include <iostream>

class TooHighException: public std::exception
{
    public : 
        virtual const char * what() const throw();
};