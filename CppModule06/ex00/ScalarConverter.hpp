#include <iostream>
#include <stdlib.h>
#include <limits.h>
class  ScalarConverter
{
    ScalarConverter();
    ScalarConverter(ScalarConverter &rhs);
    ScalarConverter &operator=(ScalarConverter &rhs);
    ~ScalarConverter();
    public:
        static void convert(std::string literal);
};

bool is_char(std::string literal);
bool is_int(std::string literal);
bool is_float(std::string literal);
bool is_double(std::string literal);
