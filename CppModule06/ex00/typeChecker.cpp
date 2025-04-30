#include "ScalarConverter.hpp"

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
        std::cout << "impossible\n";
        return (false);
    }
    return (true);
}
bool is_float(std::string literal)
{
    if (literal[literal.length() - 1] != 'f') return (false);
    if (literal == "-inff" || literal == "+inff" ||literal == "nanf") return true;
    bool flag = false;
    for (size_t i = 0; i < literal.length() - 1; i++)
    {
        if (i == 0 && (literal[i] == '-' || literal[i] == '+')) continue;
        else if (!isdigit(literal[i]) && (literal[i] != '.' && !flag)) return (false);
        else if (literal[i] == '.' && isdigit(literal[i + 1])) flag = true; // to check cases like 1.f (a number should be after .)
        else if(literal[i] == '.') return (false);
    }
    return (flag);
}

bool is_double(std::string literal)
{
    if (literal == "-inff" || literal == "+inff" ||literal == "nanf") return true;
    bool flag = false;
    for (size_t i = 0; i < literal.length() - 1; i++)
    {
        if (i == 0 && (literal[i] == '-' || literal[i] == '+')) continue;
        else if (!isdigit(literal[i]) && (literal[i] != '.' && !flag)) return (false);
        else if (literal[i] == '.' && isdigit(literal[i + 1])) flag = true; // to check cases like 1.f (a number should be after .)
        else if(literal[i] == '.') return (false);
    }
    return (flag);
}