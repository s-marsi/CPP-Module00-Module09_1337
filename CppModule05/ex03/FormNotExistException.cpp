#include "FormNotExistException.hpp"

FormNotExistException::FormNotExistException() : message(NULL) { }

FormNotExistException::FormNotExistException(std::string &msg)
{
    int len = msg.length() + strlen("form ") + strlen(" Does not exist.");
    message = new char[len + 1];
    strcpy(message, "Form ");
    strcat(message, msg.c_str());
    strcat(message, " Does not exist.");
}

const char *FormNotExistException::what() const throw()
{
    return (message);
}

FormNotExistException::~FormNotExistException() throw()
{
    if (message)
        delete[] message;
}
