#ifndef MUTANT_STACK_TPP
#define MUTANT_STACK_TPP

#include "MutantStack.hpp"


template <typename T>
MutantStack<T>::MutantStack(MutantStack &rhs)
{
    *this = rhs;
}
template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack &rhs)
{
    (void) rhs;
    return (*this);
}

#endif