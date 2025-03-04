#pragma once

#include "AForm.hpp"
#include <fstream>
#include <string.h>
#include "FormNotExistException.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
    std::string _target;
    public:
        Intern();
        Intern(Intern &rhs);
        Intern &operator=(Intern &rhs);
        AForm *makeForm(std::string formName, std::string formTarget);
        FormNotExistException NotExistException(std::string name);
        ~Intern();
};