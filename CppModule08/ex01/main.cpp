#include "Span.hpp"

int main()
{
    {
        try {
            Span sp(5);
            sp.addNumber(0);
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3);
            sp.addNumber(4);
            // sp.getNumbers();
            // sp.addNumber(12); // should throw a exception
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
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            // sp.getNumbers();
            // sp.addNumber(12); // should throw a exception
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what();
        }
    }
    return (0);
}