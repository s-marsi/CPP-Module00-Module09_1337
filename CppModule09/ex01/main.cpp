#include "RPN.hpp"

void pars_expr(char *expr) {
    std::string current = expr;
    if (current.length() == 2) {
        if (!(current[0] == '-' && isdigit(current[1]))) {
            std::cout << "Error\n";
            exit (1);
        }
    }
    else if (current.length() == 1) {
        if (!isdigit(current[0] ) && !is_operator(current))  {
            std::cout << "Error\n";
            exit (1);
        }
    }
    else {
        std::cout << "Error\n";
        exit (1);
    }
}

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cout << "Error\n"; 
        return (1);
    }
    char *expr = strtok(av[1], " ");
    RPN rpn;
    rpn.evaluator(expr);
    return (0);
}