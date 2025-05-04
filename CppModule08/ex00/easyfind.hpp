#pragma once
#include <iostream>
#include <exception>
#include <bits/stdc++.h>

template <typename T> void easyfind(T arg1, int arg2) {
    // typename T::iterator first = arg1.begin();
    // typename T::iterator end = arg1.end();

    // while (first != end) {
    //     if (*first == arg2) {
    //         std::cout << *first << " Is Present\n";
    //         return ;
    //     }
    //     first++;
    // }

    typename T::iterator it = find(arg1.begin(), arg1.end(), arg2);
    if (it != arg1.end())
        std::cout << *it << " Is Present\n";
    else
        throw "Not Present\n";
}