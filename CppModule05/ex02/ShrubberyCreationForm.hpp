#include "AForm.hpp"
#include <fstream>
#include <string.h>

class ShrubberyCreationForm: public AForm
{
    std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm &rhs);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm &rhs);
        void executeAction() const;
        ~ShrubberyCreationForm();
};