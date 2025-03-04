#include "Form.hpp"

Form::Form(): name("Default"), isSigned(false), gradeRequired(30), gradeExecute(5)  { }

Form::Form(std::string _name, int _gradeRequired, int _gradeExecute): name(_name), isSigned(false), gradeRequired(_gradeRequired), gradeExecute(_gradeExecute)
{
    if (_gradeExecute < 1 || _gradeRequired < 1)
        throw GradeTooHighException();
    else if (_gradeExecute > 150 || _gradeRequired > 150)
        throw GradeTooLowException();
}


Form::Form(Form &rhs): name(rhs.getName()), isSigned(rhs.getIsSigned()), gradeRequired(rhs.getGradeRequired()), gradeExecute(rhs.getGradeExecute())
{ 
    *this = rhs; 
}

Form &Form::operator=(Form &rhs) { 
    if (this != &rhs)
        isSigned = rhs.getIsSigned();
    return (*this);
}


TooLowException  Form::GradeTooLowException()
{
    return (TooLowException());
}

TooHighException  Form::GradeTooHighException()
{
    return (TooHighException());
}

const std::string Form::getName() const { return (name); }

bool  Form::getIsSigned() const { return (isSigned); }

int   Form::getGradeRequired() const { return (gradeRequired); }

int   Form::getGradeExecute() const { return (gradeExecute); }

void  Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= getGradeRequired())
        isSigned = true;
    else 
        throw(GradeTooLowException());
}


Form::~Form() { }


std::ostream & operator << (std::ostream &out, const Form &rhs)
{
    out << rhs.getName() << ", is signed: " << rhs.getIsSigned() << 
    " grade required to sign it: " << rhs.getGradeRequired() << "grade required to execute it: " << rhs.getGradeExecute() << std::endl;
    return out;
}