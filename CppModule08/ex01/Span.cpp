#include "Span.hpp"

Span::Span() { }

Span::Span(unsigned int N): _capacity(N), index(0) { };

Span::Span(Span &rhs) { 
    *this = rhs;
}

Span &Span::operator=(Span &rhs) { 
    if (this != &rhs) {
        _capacity = rhs._capacity;
        _numbers = rhs._numbers;
    }
    return (*this);
}

void Span::addNumber(int number) {
    if (index < _capacity) {
        index++;
        _numbers.push_back(number);
    }
    else
        throw std::out_of_range("Span is fill.\n");
}

void Span::getNumbers() {
    std::vector<int>::iterator first = _numbers.begin();
    std::vector<int>::iterator end = _numbers.end();
    while (first != end) {
        std::cout << *first << " ";
        first++;
    }
    std::cout << std::endl;
}

int Span::shortestSpan()
{
    if (index <= 1)
        throw std::runtime_error("no span can be found.\n");
    std::vector<int>::iterator first = _numbers.begin();
    std::vector<int>::iterator end = _numbers.end();
    int shortest = abs(*first - *(first + 1));
    while (first != end) {
        std::vector<int>::iterator nested_first = first;
        std::vector<int>::iterator nested_end = _numbers.end();
        while (nested_first != nested_end) {
            if (abs(*nested_first - *(nested_first + 1)) < shortest)
            shortest = abs(*nested_first - *(nested_first + 1));
            nested_first++;
        }
        first++;
    }
    return (shortest);
}

int Span::longestSpan()
{
    if (index <= 1)
        throw std::runtime_error("no span can be found.\n");
    std::vector<int>::iterator first = _numbers.begin();
    std::vector<int>::iterator end = _numbers.end();
    int longest = abs(*first - *(first + 1));
    while (first != end) {
        std::vector<int>::iterator nested_first = first;
        std::vector<int>::iterator nested_end = _numbers.end();
        while (nested_first != nested_end) {
            if (abs(*nested_first - *(nested_first + 1)) > longest)
                longest = abs(*nested_first - *(nested_first + 1));
            nested_first++;
        }
        first++;
    }
    return (longest);
}


Span::~Span() { }