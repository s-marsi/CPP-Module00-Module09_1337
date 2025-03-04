#pragma once

#include "AForm.hpp"
#include <fstream>
#include <cstdlib>

class RobotomyRequestForm: public AForm
{
    std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm &rhs);
        RobotomyRequestForm &operator=(RobotomyRequestForm &rhs);
        void executeAction() const;
        ~RobotomyRequestForm();
};