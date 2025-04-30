#include <iostream>

class  ScalarConverter
{
    ScalarConverter();
    ScalarConverter(ScalarConverter &rhs);
    ScalarConverter &operator=(ScalarConverter &rhs);
    ~ScalarConverter();
    public:
        static void convert(std::string literal);
};