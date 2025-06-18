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
    else if (operation == '/') {
        if (right_operator == 0) {
                std::cout << "Error\n";
                std::cout << "Division by zero\n";
                exit (1);
        }
        return (left_operator / right_operator);
    }
    return (0);
}

bool is_operator(std::string expr) {
    if (expr.length() != 1)
        return (false);
    std::string operators = "+-*/";
    for (size_t i = 0; i < operators.length(); i++) {
        if (operators[i] == expr[0])
            return (true);
    }
    return (false);
}

void RPN::evaluator(char *expr) {
    bool flag = false;
    while (expr != NULL)
    { 
        pars_expr(expr);
        if (is_operator(expr)) {
            flag = true;
            std::string current_expr = expr;
            if (my_stack.size() < 2 || current_expr.length() > 1) {
                std::cout << "Error\n";
                return;
            }
            int left_operator;
            int right_operator;
            right_operator = my_stack.top();
            my_stack.pop();
            left_operator = my_stack.top();
            my_stack.pop();
            my_stack.push(calculate(expr[0], left_operator, right_operator));
        }
        else {
            my_stack.push(atoi(expr));
        }
        expr = strtok(NULL, " ");
    }
    if (!flag) {
        std::cout << "Error\n";
        return ;
    }
    std::cout << my_stack.top() << std::endl;
}

RPN::~RPN() { }