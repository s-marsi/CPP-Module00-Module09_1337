#include "AForm.hpp"

AForm::AForm(): name("Default"), isSigned(false), gradeRequired(30), gradeExecute(5)  { }

AForm::AForm(std::string _name): name(_name), gradeRequired(30), gradeExecute(5) { }


AForm::AForm(std::string _name, int _gradeRequired, int _gradeExecute): name(_name), isSigned(false), gradeRequired(_gradeRequired), gradeExecute(_gradeExecute)
{ }


AForm::AForm(AForm &rhs): name(rhs.getName()), isSigned(rhs.getIsSigned()), gradeRequired(rhs.getGraderequired()), gradeExecute(rhs.getGradeExecute())
{ *this = rhs; }

AForm &AForm::operator=(AForm &rhs) { 
    if (this != &rhs)
        isSigned = rhs.getIsSigned();
    return (*this);
}


const std::string AForm::getName() const { return (name); }

bool  AForm::getIsSigned() const { return (isSigned); }

int   AForm::getGraderequired() const { return (gradeRequired); }

int   AForm::getGradeExecute() const { return (gradeExecute); }

void  AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= getGraderequired())
        isSigned = true;
    else 
        throw(GradeTooLowException());
}

void  AForm::setIsSigned(bool is_signed)
{
    isSigned = is_signed;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw NotSignedException();
    else if (executor.getGrade() > getGradeExecute())
        throw GradeTooLowException();
    executeAction();
}

TooLowException  AForm::GradeTooLowException() const
{
    return (TooLowException());
}

TooHighException  AForm::GradeTooHighException() const
{
    return (TooHighException());
}

FormNotSignedException AForm::NotSignedException() const
{
    return (FormNotSignedException());
}


AForm::~AForm() { }


std::ostream & operator << (std::ostream &out, const AForm &rhs)
{
    out << rhs.getName() << ", is signed: " << rhs.getIsSigned() << 
    " grade required to sign it: " << rhs.getGraderequired() << "grade required to execute it: " << rhs.getGradeExecute() << std::endl;
    return out;
}