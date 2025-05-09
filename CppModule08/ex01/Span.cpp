#include "Span.hpp"

Span::Span() { }

Span::Span(unsigned int N): _capacity(N) { };

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
    if (_numbers.size() < _capacity)
        _numbers.push_back(number);
    else
        throw std::runtime_error("Span is full.\n");
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
    if (_numbers.empty() || _numbers.size() <= 1)
        throw std::runtime_error("no span can be found.\n");
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    int shortest = tmp[1] - tmp[0];
    return (shortest);
}

int Span::longestSpan()
{
    if (_numbers.empty() || _numbers.size() <= 1)
        throw std::runtime_error("no span can be found.\n");
    std::vector<int> tmp = _numbers;
    std::sort( tmp.begin(), tmp.end() );
    int longest =  *(tmp.end() - 1) - tmp[0];
    return (longest);
}


Span::~Span() { }