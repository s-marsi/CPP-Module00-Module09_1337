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
            std::vector<int> _numbers = {1, -2, 3, 4, 5};

            sp.addNumber(_numbers.begin(),  _numbers.end());
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        } catch (std::exception &e) {
            std::cout << e.what();
        }
    }
    return (0);
}