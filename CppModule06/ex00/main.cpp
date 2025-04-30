#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
        std::cout << "Bad Arguments.\n";
    else
    {
        std::string literal(av[1]);
        ScalarConverter::convert(literal);
    }
    return (0);
}