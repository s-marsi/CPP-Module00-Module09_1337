#include "RPN.hpp"

RPN::RPN() { }

RPN::RPN(RPN &rhs) { *this = rhs; }

RPN &RPN::operator=(RPN &rhs) { 
    if (this != &rhs) {
        my_stack = rhs.my_stack;
    }
    return (*this);
}

int calculate(char &operation, int &left_operator, int &right_operator) {
    if (operation == '+')
        return (left_operator + right_operator);
    if (operation == '-')
        return (left_operator - right_operator);
    if (operation == '*')
        return (left_operator * right_operator);
    return (left_operator / right_operator);
}

bool is_operator(std::string expr) {
    std::string operators = "+-*/";
    for (int i = 0; i < operators.length(); i++) {
        if (operators[i] == expr[0])
            return (true);
    }
    return (false);
}

// void RPN::evaluate(char *expr) {
//     while (expr != NULL)
//     {
//         int left_operator;
//         int right_operator;
//         std::string current_expr = expr;
//         expr = strtok(NULL, "-");
//     }
// }

RPN::~RPN() { }