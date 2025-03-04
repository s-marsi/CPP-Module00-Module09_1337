#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include <iostream>
class Bureaucrat;

class Form
{
    const  std::string name;
    bool   isSigned;
    int    gradeRequired;
    int    gradeExecute;
    public :
        Form();
        Form(std::string _name,int _gradeRequired, int _gradeExecute);
        Form(Form &rhs);
        Form &operator=(Form &rhs);
        TooLowException  GradeTooLowException();
        TooHighException  GradeTooHighException();
        const std::string getName() const;
        bool  getIsSigned() const;
        int   getGradeRequired() const;
        int   getGradeExecute() const;
        void  beSigned(const Bureaucrat &bureaucrat);
        ~Form();

};

std::ostream & operator << (std::ostream &out, const Form &rhs);

#endif