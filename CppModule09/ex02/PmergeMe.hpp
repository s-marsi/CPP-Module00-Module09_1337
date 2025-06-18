#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <stdlib.h>
#include <vector>

typedef std::vector< std::pair<int, int> > pair_vector;

class PmergeMe
{
    private:
        PmergeMe();
        PmergeMe(PmergeMe& rhs);
        PmergeMe& operator=(PmergeMe& rhs);
        pair_vector pair_array;
        int leftover;
    public:
        PmergeMe(int ac, char *av[]);
        void  merge_insert_sort();
        ~PmergeMe();
};



#endif