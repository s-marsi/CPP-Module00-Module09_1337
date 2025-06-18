#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): leftover(-1) {}

PmergeMe::PmergeMe(int ac, char *av[]): leftover(-1)
{
    for (int i = 1; i < ac; i++)
    {
        if (ac % 2 == 0)
        {
            if (i == ac - 1)
                leftover = atoi(av[i]);
            else {
                pair_array.push_back(std::make_pair(atoi(av[i]), atoi(av[i + 1])));
                i++;
            }
        }
        else {
                pair_array.push_back(std::make_pair(atoi(av[i]), atoi(av[i + 1])));
                i++;
        }
    }
    pair_vector::iterator begin = pair_array.begin();
    pair_vector::iterator end = pair_array.end();
    while (begin != end) {
        std::cout << " [" << (*begin).first << ", " << (*begin).second << "] |" ;
        begin++;
    }
    std::cout << std::endl;
    std::cout << "leftover= " << leftover << std::endl;
}

PmergeMe::PmergeMe(PmergeMe& rhs)
{ *this = rhs; }
PmergeMe& PmergeMe::operator=(PmergeMe& rhs)
{ (void) rhs;
return (*this); }
PmergeMe::~PmergeMe()
{ }