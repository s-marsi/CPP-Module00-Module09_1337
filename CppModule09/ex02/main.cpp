#include "PmergeMe.hpp"

void print_error_exit()
{ std::cout << "Error" <<std::endl; exit (1); }

void parse_args(int ac, char *av[])
{
    for (int i = 1; i < ac; i++)
    {
        if (!av[i][0])
        {
            print_error_exit();
        }
        for (size_t j = 0; j < std::string(av[i]).length(); j++) {
            if (!std::isdigit(av[i][j])){
                print_error_exit();
            }
        }
    }
}


int main(int ac, char *av[])
{
    if (ac < 2) {
        print_error_exit();
    }
    parse_args(ac, av);
    PmergeMe test(ac, av);
    test.merge_insert_sort();
    return (0);
}