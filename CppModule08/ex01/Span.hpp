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
        std::vector<int> _numbers;
        Span();
    public:
        Span(unsigned int N);
        Span(Span &rhs);
        Span &operator=(Span &rhs);
        void addNumber(int number);
        template <typename T>
        void addNumber(T first, T end)
        { 
            int i = 0;
            while (first != end) {
                if ( _numbers.size() >= _capacity )
                    throw ( std::runtime_error("Span is full..\n") );
                _numbers.push_back(*first);
                i++;
                first++;
            }
        }
        int shortestSpan();
        int longestSpan();
        void getNumbers();
        ~Span();
};
#endif