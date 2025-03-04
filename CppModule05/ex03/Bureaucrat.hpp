#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include <iostream>
class AForm;

class Bureaucrat
{
    const std::string _name;
    int _grade;
    public :
        Bureaucrat();
        Bureaucrat(int grade);
        Bureaucrat(std::string name, int _grade);
        Bureaucrat(Bureaucrat &rhs);
        Bureaucrat &operator=(Bureaucrat &rhs);
        TooLowException  GradeTooLowException();
        TooHighException  GradeTooHighException();
        int getGrade() const;
        const std::string getName() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &form);
        void executeForm(AForm const & form);
        ~Bureaucrat();
};
std::ostream & operator << (std::ostream &out, const Bureaucrat &rhs);

#endif