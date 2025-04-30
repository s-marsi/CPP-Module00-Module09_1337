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

bool is_int(std::string literal)
{
    for (size_t i = 0; i < literal.length(); i++)
    {
        if (i == 0 && (literal[i] == '-' || literal[i] == '+'))
            continue;
        else if (!isdigit(literal[i]))
            return (false);
    }
    long long number = std::atoll( literal.c_str() );
    if (number > INT_MAX || number < INT_MIN)
    {
        std::cout << "int overflow.\n";
        return (false);
    }
    std::cout << number << "\n";
    return (true);
}
