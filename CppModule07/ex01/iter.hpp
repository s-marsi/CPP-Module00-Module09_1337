#include <iostream>

template <typename T, typename F> void iter(T *arg1, size_t arg2, F fun) {
    for (size_t i = 0; i < arg2; i++)
    {
        fun(arg1[i]);
    }
}

template <typename T> void myFun(T args) {
    std::cout << args << "  ";
}