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
void merge_sort(std::vector<int> &arr_to_sort, int left, int right);
bool array_is_sorted(std::vector<int> &arr_to_sort);
#endif