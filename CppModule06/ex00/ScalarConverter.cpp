#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter(ScalarConverter &rhs) { *this = rhs; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter &rhs) { (void) rhs; return (*this); }

ScalarConverter::~ScalarConverter() { }

void ScalarConverter::convert(std::string literal)
{
    // if (is_char(literal))
    //     std::cout << "is a char\n";
    // else if (is_int(literal))
    //     std::cout << "is a int\n";
}

bool is_char(std::string literal)
{
    if (literal.length() == 1)
    {
        if (!isascii(literal[0]))
            std::cout << "out of ascii range.\n";
        else if (!isprint(literal[0]))
            std::cout << "Non displayable\n";
        else if (!isdigit(literal[0]))
            return (true);
    }
    return (false);
}

