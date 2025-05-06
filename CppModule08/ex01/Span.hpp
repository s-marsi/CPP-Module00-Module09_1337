#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

class Span
{
    private:
        unsigned int _capacity;
        unsigned int index;
        std::vector<int> _numbers;
        Span();
    public:
        Span(unsigned int N);
        Span(Span &rhs);
        Span &operator=(Span &rhs);
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
        void getNumbers();
        ~Span();
};
#endif