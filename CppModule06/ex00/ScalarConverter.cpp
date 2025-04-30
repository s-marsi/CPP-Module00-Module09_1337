#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter(ScalarConverter &rhs) { *this = rhs; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter &rhs) { (void) rhs; return (*this); }

ScalarConverter::~ScalarConverter() { }

void ScalarConverter::convert(std::string literal)
{
    if (is_char(literal))
        std::cout << "is a char\n";
    else if (is_int(literal))
        std::cout << "is a int\n";
    else if (is_float(literal))
        std::cout << "is a float\n";
    else if (is_double(literal))
        std::cout << "is a double\n";
    else 
        std::cout << "bad argument.\n";
}
