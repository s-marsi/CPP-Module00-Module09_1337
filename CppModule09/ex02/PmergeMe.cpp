#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): leftover(-1) {}

void print_pair(pair_vector &to_print, int &leftover) {
    pair_vector::iterator begin = to_print.begin();
    pair_vector::iterator end = to_print.end();
    while (begin != end) {
        std::cout << " [" << (*begin).first << ", " << (*begin).second << "] |" ;
        begin++;
    }
    std::cout << " leftover= " << leftover << std::endl;
}

void print_vector(std::vector<int> &to_print) {
    std::vector<int>::iterator begin = to_print.begin();
    std::vector<int>::iterator end = to_print.end();
    while (begin != end) {
        std::cout << " [" << std::setw(5) << *begin << "] |" ;
        begin++;
    }
    std::cout << "\n";
}


void  PmergeMe::sort_pair()
{
    for(size_t i = 0; i < pair_array.size(); i++)
    {
        if (pair_array[i].first < pair_array[i].second) {
            int tmp = pair_array[i].first;
            pair_array[i].first = pair_array[i].second;
            pair_array[i].second = tmp;
        }
    }
}

void  PmergeMe::split_pairs() {
    for(size_t i = 0; i < pair_array.size(); i++)
    {
        largest.push_back(pair_array[i].first);
        lowest.push_back(pair_array[i].second);
    }
}

void  PmergeMe::merge_insert_sort()
{
    std::cout << std::setw(20) << "before sort: ";
    print_pair(pair_array, leftover);
    sort_pair();
    std::cout << std::setw(20) << "after sort: ";
    print_pair(pair_array, leftover);
    split_pairs();
    std::cout << std::setw(20) << "largest numbers: ";
    print_vector(largest);
    std::cout << std::setw(20) << "lowest numbers: ";
    print_vector(lowest);

    if (!array_is_sorted(largest))
        merge_sort(largest, 0, largest.size() - 1);
    print_vector(largest);
    print_vector(lowest);

}

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
}

PmergeMe::PmergeMe(PmergeMe& rhs)
{ *this = rhs; }
PmergeMe& PmergeMe::operator=(PmergeMe& rhs)
{ (void) rhs;
return (*this); }
PmergeMe::~PmergeMe()
{ }