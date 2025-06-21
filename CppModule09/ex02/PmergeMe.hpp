#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <deque>
#include <iomanip>
#include <climits>
#include <ctime>

typedef std::vector< std::pair<int, int> > pair_vector;
typedef std::deque< std::pair<int, int> > pair_deque;

class PmergeMe
{
    pair_vector pair_vector;
    pair_deque pair_deque;

    std::vector<int> args; // to save the args in the same order because we need to print it at the end of the program

    std::vector<int> largest;
    std::vector<int> lowest;

    std::deque<int> largest_dq;
    std::deque<int> lowest_dq;
    
        int leftover;
    private:
    PmergeMe(PmergeMe& rhs);
    PmergeMe& operator=(PmergeMe& rhs);
    public:
        PmergeMe();
        void  merge_insert_sort_vector(int ac, char *av[]);
        void  merge_insert_sort_deque(int ac, char *av[]);
        void  args_to_deque(int ac, char *av[]) ;
        void  args_to_vector(int ac, char *av[]) ;
        void  push_sort_pair(int num1, int num2, std::string type);
        void split_pairs(std::string type);
        ~PmergeMe();
};

#include "merge_sort.tpp"
#include "binary_search_insertion.tpp"
#include "helpers.tpp"

#endif