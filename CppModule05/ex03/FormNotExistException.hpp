#pragma once

#include <iostream>
#include <string.h>

class FormNotExistException : public std::exception
{
    char * message;
    public :
        FormNotExistException();
        FormNotExistException(std::string &msg);
        virtual const char *what() const throw();
        virtual ~FormNotExistException() throw();

};