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
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    int shortest = tmp[1] - tmp[0];
    std::vector<int>::iterator first = tmp.begin();
    while (first != tmp.end()) {
        if ( (first + 1) != tmp.end() ) {
            int next = *(first + 1); 
            if ( (next - *first) < shortest )
                shortest = next - *first;
        }
        first++;
    }
    return (shortest);
}

int Span::longestSpan()
{
    if (index <= 1)
        throw std::runtime_error("no span can be found.\n");
    std::vector<int> tmp = _numbers;
    std::sort( tmp.begin(), tmp.end() );
    std::reverse( tmp.begin(), tmp.end() );
    int longest = tmp[0] - *(tmp.end() - 1);
    return (longest);
}


Span::~Span() { }