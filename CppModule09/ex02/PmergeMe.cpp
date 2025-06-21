#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): leftover(-1) {}

PmergeMe::PmergeMe(PmergeMe& rhs)
{ *this = rhs; }
PmergeMe& PmergeMe::operator=(PmergeMe& rhs)
{ (void) rhs;
return (*this); }
PmergeMe::~PmergeMe()
{ }

void  PmergeMe::push_sort_pair(int num1, int num2, std::string type)
{
    if (type == "vector") {
        if (num1 <= num2)
            pair_vector.push_back(std::make_pair(num1, num2));
        else
            pair_vector.push_back(std::make_pair(num2, num1));
    }
    else {
        if (num1 <= num2)
            pair_deque.push_back(std::make_pair(num1, num2));
        else
            pair_deque.push_back(std::make_pair(num2, num1));  
    }
}

void  PmergeMe::split_pairs(std::string type) {
    if (type == "vector")
    {
        for(size_t i = 0; i < pair_vector.size(); i++)
        {
            largest.push_back(pair_vector[i].second);
            lowest.push_back(pair_vector[i].first);
        }
    }
    else
    {
        for(size_t i = 0; i < pair_deque.size(); i++)
        {
            largest_dq.push_back(pair_deque[i].second);
            lowest_dq.push_back(pair_deque[i].first);

        }  
    }
}

// ---------------------- Vector Logique ---------------

void  PmergeMe::merge_insert_sort_vector(int ac, char *av[])
{
    std::clock_t start;
	std::clock_t end;
    start = std::clock();
    args_to_vector(ac, av);
    split_pairs("vector");
    if (!array_is_sorted(largest))
        merge_sort(largest, 0, largest.size() - 1);
    for(size_t i = 0; i < lowest.size(); i++)
    {
        binary_search_insert(largest, lowest[i], 0, largest.size() - 1);
    } 
    end = std::clock();
    // std::cout << "Before: "; print_STL(pair_vector); std::cout << ", " ; std::cout << std::endl;
    std::cout << "After: "; print_STL(largest); std::cout << std::endl;
    std::cout << "Time to process a range of " << largest.size() <<  " elements with std::vector :" << (end - start) << " us" << std::endl;
}

void  PmergeMe::args_to_vector(int ac, char *av[])
{
    for (int i = 1; i < ac; i++)
    {
        if (ac % 2 == 0 && i == ac - 1) {
            args.push_back(atoi(av[i]));
            leftover = atoi(av[i]);
        }
        else
        {
            args.push_back(atoi(av[i]));
            args.push_back(atoi(av[i + 1]));

            push_sort_pair(atoi(av[i]), atoi(av[i + 1]), "vector");
            i++;
        }
    }
}

// ---------------------- Deque Logique ---------------

void  PmergeMe::merge_insert_sort_deque(int ac, char *av[])
{
    std::clock_t start;
	std::clock_t end;
    start = std::clock();
    args_to_deque(ac, av);
    split_pairs("deque");
    if (!array_is_sorted(largest_dq))
        merge_sort(largest_dq, 0, largest_dq.size() - 1);
    for(size_t i = 0; i < lowest_dq.size(); i++)
    {
        binary_search_insert(largest_dq, lowest_dq[i], 0, largest_dq.size() - 1);
    } 
    end = std::clock();
    std::cout << "Time to process a range of " << largest_dq.size() <<  " elements with std::deque :" << (end - start) << " us" << std::endl;
}

void  PmergeMe::args_to_deque(int ac, char *av[])
{
    for (int i = 1; i < ac; i++)
    {
        if (ac % 2 == 0 && i == ac - 1)
            leftover = atoi(av[i]);
        else
        {
            push_sort_pair(atoi(av[i]), atoi(av[i + 1]), "deque");
            i++;
        }
    }
}

