#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(RPN &rhs) { *this = rhs }

RPN &RPN::operator=(RPN &rhs) { 
    if (this != &rhs) {
        my_stack = rhs.my_stack;
    }
    return (*this);
}

RPN::~RPN() { }