#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iomanip>
typedef std::vector< std::pair<int, int> > pair_vector;

class PmergeMe
{
    pair_vector pair_array;
    std::vector<int> largest;
    std::vector<int> lowest;
    int leftover;
    private:
        PmergeMe();
        PmergeMe(PmergeMe& rhs);
        PmergeMe& operator=(PmergeMe& rhs);
    public:
        PmergeMe(int ac, char *av[]);
        void  merge_insert_sort();
        void  sort_pair();
        void split_pairs();
        ~PmergeMe();
};

#endif