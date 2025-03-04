#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy", 72, 45) { }

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy", 72, 45), _target(target) { }


RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &rhs): AForm(rhs.getName(), rhs.getGraderequired(), rhs.getGradeExecute()) { 
    *this = rhs;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &rhs)
{
    if (this != &rhs)
    {
        this->setIsSigned(rhs.getIsSigned());
        _target = rhs._target;
    }
    return (*this);
}

void    RobotomyRequestForm::executeAction() const
{
    std::cout << "drilling noises!" <<std::endl;
    srand(time(0));
    if (rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully" <<std::endl;
    else
        std::cout << _target << "  the robotomy failed." <<std::endl;
}


RobotomyRequestForm::~RobotomyRequestForm() { }
