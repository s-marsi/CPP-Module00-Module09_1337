#pragma once
#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

template <typename T> void easyfind(T arg1, int arg2) {
    typename T::iterator it = find(arg1.begin(), arg1.end(), arg2);
    if (it != arg1.end())
        std::cout << *it << " Is Present\n";
    else
        throw "Not Present\n";
}