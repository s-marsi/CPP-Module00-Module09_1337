#pragma once

#include "AForm.hpp"
#include <fstream>
#include <string.h>

class PresidentialPardonForm: public AForm
{
    std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm &rhs);
        PresidentialPardonForm &operator=(PresidentialPardonForm &rhs);
        void executeAction() const;
        ~PresidentialPardonForm();
};