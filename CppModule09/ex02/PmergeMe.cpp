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
    if (ac > 2) {
         args_to_vector(ac, av);
        if (!array_is_sorted(pair_vector))
            merge_sort(pair_vector, 0, pair_vector.size() - 1);
        split_pairs("vector");
        largest.insert(largest.begin(), lowest[0]);
        for(size_t i = 1; i < lowest.size(); i++)
        {
            binary_search_insert(largest, lowest[i], 0, largest.size() - 1);
        }
        if (leftover != -1) 
            binary_search_insert(largest, leftover, 0, largest.size() - 1);
    }
    else
    {
        args.push_back(atoi(av[1]));
        largest.push_back(atoi(av[1]));
    }
    end = std::clock();
    std::cout << "Before: "; print_STL(args); std::cout << std::endl;
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
    if (ac > 2)
    {
        args_to_deque(ac, av);
        if (!array_is_sorted(pair_deque))
            merge_sort(pair_deque, 0, pair_deque.size() - 1);
        split_pairs("deque");
        largest_dq.insert(largest_dq.begin(), lowest_dq[0]);
        for(size_t i = 1; i < lowest_dq.size(); i++)
        {
            binary_search_insert(largest_dq, lowest_dq[i], 0, largest_dq.size() - 1);
        }
        if (leftover != -1) 
            binary_search_insert(largest_dq, leftover, 0, largest_dq.size() - 1);
    }
    else
    {
        args.push_back(atoi(av[1]));
        largest_dq.push_back(atoi(av[1]));
    }
    end = std::clock();
    std::cout << "Time to process a range of " << largest_dq.size() <<  " elements with std::deque :"  << (end - start) << " us" << std::endl;
}

void  PmergeMe::args_to_deque(int ac, char *av[])
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

            push_sort_pair(atoi(av[i]), atoi(av[i + 1]), "deque");
            i++;
        }
    }
}

