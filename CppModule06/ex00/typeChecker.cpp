#include "ScalarConverter.hpp"

bool is_char(std::string literal)
{
    if (literal.length() == 1)
    {
        if (!isdigit(literal[0]))
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
    if (literal == "-inf" || literal == "+inf" ||literal == "nan") return true;
    bool flag = false;
    for (size_t i = 0; i < literal.length() - 1; i++)
    {
        if (i == 0 && (literal[i] == '-' || literal[i] == '+')) continue;
        else if (!isdigit(literal[i]) && (literal[i] != '.' && !flag)) return (false);
        else if (literal[i] == '.' && isdigit(literal[i + 1])) flag = true; // to check cases like 1. (a number should be after .)
        else if(literal[i] == '.') return (false);
    }
    return (flag);
}