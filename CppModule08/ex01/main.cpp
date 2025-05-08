#include "Span.hpp"

int main()
{
    {
        try {
            Span sp(5);
            sp.addNumber(0);
            sp.addNumber(10);
            sp.addNumber(20);
            sp.addNumber(-8);
            sp.addNumber(30);
            // sp.getNumbers();
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what();
        }
    }

    std::cout << "\n-----------------------------------\n" << std::endl;

    {
        try {
            Span sp(5);
            std::vector<int> numbers;

            for (int i = 0; i < 5; i++) {
                numbers.push_back(i);
            }

            sp.addNumber(numbers.begin(),  numbers.end());
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what();
        }
    }

    std::cout << "\n-----------------------------------\n" << std::endl;

    {
        try {
            Span sp(5);
            std::vector<int> numbers;
            
            for (int i = 0; i < 6; i++) {
                numbers.push_back(i);
            }

            sp.addNumber(numbers.begin(),  numbers.end());
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what();
        }
    }

    return (0);
}