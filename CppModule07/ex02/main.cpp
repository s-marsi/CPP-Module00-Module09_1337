#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

 std::cout << "\n\n----------------------------Test default constructor----------------------------\n\n";
    Array<int> a1;
    std::cout << "Size of a1: " << a1.size() << std::endl;

    std::cout << "\n\n----------------------------Test constructor with parameter----------------------------\n\n";
    Array<int> a2(5);
    std::cout << "Size of a2: " << a2.size() << std::endl;
    for (unsigned int i = 0; i < a2.size(); ++i) {
        std::cout << "a2[" << i << "] = " << a2[i] << std::endl;
    }

    std::cout << "\n----------------------------Test copy constructor----------------------------\n\n";
    Array<int> a3(a2);
    std::cout << "Size of a3: " << a3.size() << std::endl;
    for (unsigned int i = 0; i < a3.size(); ++i) {
        std::cout << "a3[" << i << "] = " << a3[i] << std::endl;
    }

    std::cout << "\n----------------------------Test assignment operator-----------------\n\n";
    Array<int> a4;
    a4 = a2;
    std::cout << "Size of a4: " << a4.size() << std::endl;
    for (unsigned int i = 0; i < a4.size(); ++i) {
        std::cout << "a4[" << i << "] = " << a4[i] << std::endl;
    }

    std::cout << "\n---------------------------- Test out of bounds access\n\n";
    try {
        std::cout << "a2[10] = " << a2[10] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "-------------------reading only if the instance is const \n\n";
    //  Array<int const> a8(3);
    // a8[1] = 2;
    std::cout << "\n----------------------------Test Int Elements-----------------\n\n";
    Array<int> a5(5);
    std::cout << "Size of a4: " << a5.size() << std::endl;
    a5[0] = 1;
    a5[3] = 3;
    a5[4] = 4;
    for (unsigned int i = 0; i < a5.size(); ++i) {
        std::cout << "a4[" << i << "] = " << a5[i] << std::endl;
    }

    std::cout << "\n----------------------------Test std::string Elements-----------------\n\n";
    Array<std::string> a6(5);
    std::cout << "Size of a4: " << a6.size() << std::endl;
    a6[0] = "ah";
    a6[3] = "la";
    a6[4] = "pk";
    for (unsigned int i = 0; i < a6.size(); ++i) {
        std::cout << "a4[" << i << "] = " << a6[i] << std::endl;
    }
    return 0;
}