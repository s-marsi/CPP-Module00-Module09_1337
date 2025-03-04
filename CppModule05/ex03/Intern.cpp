#include "Intern.hpp"

Intern::Intern() { }


Intern::Intern(Intern &rhs) { 
    *this = rhs;
}

Intern &Intern::operator=(Intern &rhs)
{
    (void) rhs;
    return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
    AForm *form = NULL;
    std::string arr[3] = {"shrubbery request", "robotomy request", "presidential request"};
    int i = 0;
    while (i < 3 && arr[i] != formName)
        i++;
    switch (i)
    {
        case 0:
            form = new ShrubberyCreationForm(formTarget);
            break;
        case 1:
            form = new RobotomyRequestForm(formTarget);
            break;
        case 2:
            form = new PresidentialPardonForm(formTarget);
            break;
        default:
            throw (NotExistException(formName));
            break;
    }
    std::cout << "Intern creates " << arr[i] << std::endl;
    return form;
}

FormNotExistException Intern::NotExistException(std::string name)
{
    return (FormNotExistException(name));
}


Intern::~Intern() { 

}
