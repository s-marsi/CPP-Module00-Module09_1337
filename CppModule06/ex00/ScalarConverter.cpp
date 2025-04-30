#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() { }

ScalarConverter::ScalarConverter(ScalarConverter &rhs) { *this = rhs; }

ScalarConverter &ScalarConverter::operator=(ScalarConverter &rhs) { (void) rhs; return (*this); }

ScalarConverter::~ScalarConverter() { }

void ScalarConverter::convert(std::string literal)
{
    if (is_char(literal))
        handle_char(literal);
    else if (is_int(literal))
        handle_int(literal);
    else if (is_float(literal))
        handle_float(literal);
    else if (is_double(literal))
        handle_double(literal);
    else 
        std::cout << "bad argument.\n";
}

void handle_char(std::string literal)
{
     if (!isascii(literal[0]))
        std::cout << "char: impossible\n";
    else if (!isprint(literal[0]))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: " << literal << std::endl;
    std::cout << "int: " << static_cast<int> (literal[0]) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float> (literal[0]) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double> (literal[0]) << std::endl;
}

void handle_int(std::string literal)
{
    long long number = std::atoll( literal.c_str() );
    char charValue = static_cast <char> (number);
    if (!isascii(number))
        std::cout << "char: impossible\n";
    else if (isprint(number))
        std::cout << "char: " << charValue << std::endl;
    else
        std::cout << "char: Non displayable\n";
    if (number > INT_MAX || number < INT_MIN)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << number << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float> (number) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double> (number) << std::endl;
}

void handle_float(std::string literal)
{
    (void) literal;
    std::cout << "is a float\n";
}

void handle_double(std::string literal)
{
    std::cout << "is a double\n";
    (void) literal;
}
