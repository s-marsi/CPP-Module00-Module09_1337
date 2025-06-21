#ifndef HELPERS_TPP
#define HELPERS_TPP

template <typename T>
void print_pair(T &to_print, int &leftover) {
    typename T::iterator begin = to_print.begin();
    typename T::iterator end = to_print.end();
    while (begin != end) {
        std::cout << " [" << (*begin).first << ", " << (*begin).second << "] |" ;
        begin++;
    }
    std::cout << " leftover= " << leftover << std::endl;
}


template <typename T>
void print_STL(T &to_print) {
    typename T::iterator begin = to_print.begin();
    typename T::iterator end = to_print.end();
    while (begin != end) {
        std::cout << *begin << " " ;
        begin++;
    }
}

#endif