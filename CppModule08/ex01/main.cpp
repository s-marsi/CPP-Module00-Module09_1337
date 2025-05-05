#include "Span.hpp"

int main()
{
    Span sp(5);
    try {
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
    return (0);
}