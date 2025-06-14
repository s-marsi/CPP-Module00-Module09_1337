#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<int> my_stack;
    public:
        RPN();
        RPN(RPN &rhs);
        RPN &operator=(RPN &rhs);
        ~RPN();
};

#endif