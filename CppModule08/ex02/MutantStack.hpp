#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <deque>
#include <stack>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack()
        { };

        MutantStack(MutantStack &rhs)
        { *this = rhs; };

        MutantStack &operator=(MutantStack &rhs)
        { (void) rhs; return (*this); };

        typedef typename std::deque<T>::iterator iterator;

        iterator begin()
        { return MutantStack::c.begin(); }

        iterator end()
        { return MutantStack::c.end(); }

        typedef typename std::deque<T>::const_iterator const_iterator ;

        const_iterator cbegin() 
        { return MutantStack::c.cbegin(); }

        const_iterator cend() 
        { return MutantStack::c.cend(); }

        ~MutantStack(){};
};

// #include "MutantStack.tpp"

#endif
