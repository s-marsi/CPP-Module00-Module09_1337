#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "FormNotSignedException.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
    const  std::string name;
    bool   isSigned;
    const int    gradeRequired;
    const int    gradeExecute;
    public :
        AForm();
        AForm(std::string _name);
        AForm(std::string _name,int _gradeRequired, int _gradeExecute);
        AForm(AForm &rhs);
        AForm &operator=(AForm &rhs);
        TooLowException  GradeTooLowException() const;
        TooHighException GradeTooHighException() const;
        FormNotSignedException NotSignedException() const;
        const std::string getName() const;
        bool  getIsSigned() const;
        int   getGraderequired() const;
        int   getGradeExecute() const;
        void  setIsSigned(bool is_signed);
        void  beSigned(const Bureaucrat &bureaucrat);
        void  execute(Bureaucrat const & executor) const;
        virtual void executeAction() const = 0;
        virtual ~AForm();

};

std::ostream & operator << (std::ostream &out, const AForm &rhs);

#endif