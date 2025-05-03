#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef> // pour unsigned int
#include <stdexcept> // pour std::out_of_range

template <typename T>
class Array
{
    private:
        T *elements;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(Array &rhs);
        Array &operator=(Array &rhs);
        T &operator[](unsigned int index);
        T &operator[](unsigned int index) const;
        unsigned int size() const;
        ~Array();
};

#include "Array.tpp"

#endif