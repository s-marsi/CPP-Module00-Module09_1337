#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(5) { }

Bureaucrat::Bureaucrat(int grade)
{
    if (grade < 1)
        throw GradeTooLowException();
    else if (grade > 150)
        throw GradeTooHighException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    if (grade < 1)
        throw TooLowException();
    else if (grade > 150)
        throw TooHighException();
    _grade = grade;
}

TooLowException Bureaucrat::GradeTooLowException()
{
    return (TooLowException());
}

TooHighException Bureaucrat::GradeTooHighException()
{
    return (TooHighException());
}


Bureaucrat::Bureaucrat(Bureaucrat &rhs) { *this = rhs; }

Bureaucrat &Bureaucrat::operator=(Bureaucrat &rhs)
{
    if (this != &rhs)
        _grade = rhs.getGrade();
    return (*this);
}

void Bureaucrat::incrementGrade()
{
    _grade--;
    if (_grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    _grade++;
    if (_grade > 150)
        throw GradeTooLowException();
}



int Bureaucrat::getGrade() const { return (_grade); };

const std::string Bureaucrat::getName() const { return (_name); };

void  Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << getName() << "  couldn\'t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}


void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << getName() << " Not executed " << form.getName() << ": " << e.what() << std::endl;
    }
}

Bureaucrat::~Bureaucrat() { }

std::ostream & operator << (std::ostream &out, const Bureaucrat &rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return out;
}
