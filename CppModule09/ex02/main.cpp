#include "PmergeMe.hpp"

void parse_args(int ac, char *av[])
{
    std::size_t tmp;
    for (int i = 1; i < ac; i++)
    {
        if (!av[i][0])
            throw std::runtime_error("Error: bad args");

        for (size_t j = 0; j < std::string(av[i]).length(); j++) {
            if (!std::isdigit(av[i][j])){
                throw std::runtime_error("Error: bad args");
            }
        }

        tmp = atoll(av[i]);

        if (tmp > INT_MAX)
            throw std::runtime_error("Error: bad args");
    }
}


int main(int ac, char *av[])
{
    try
    { 
        if (ac < 2)
            throw std::runtime_error("Error: bad args");

        parse_args(ac, av);
            
        PmergeMe test;
        test.merge_insert_sort();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
   

    return (0);
}