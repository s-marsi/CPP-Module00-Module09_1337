#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stdio.h>

#include <string.h>
#include <stack>

bool is_operator(std::string expr);
// int  calculate(char &operation, int &left_operator, int &right_operator);
class RPN
{
    private:
        std::stack<int> my_stack;
    public:
        RPN();
        RPN(RPN &rhs);
        RPN &operator=(RPN &rhs);
        // void evaluate(char *expr);
        ~RPN();
};

#endif