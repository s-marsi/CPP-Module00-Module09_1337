#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

 try
  {
    Bureaucrat a("sdfdf",15);
  	Intern someRandomIntern;
    AForm* rrf = NULL;
    {
      rrf = someRandomIntern.makeForm("robotomy request", "Bender");
      rrf->beSigned(a);
      rrf->execute(a);
    }
    delete rrf;
  }
  catch (std::exception & e)
  {
    std::cout << e.what() << std::endl;
  }


  try
  {

  	Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("noForm request", "Bender");
  }
  catch (std::exception & e)
  {
    std::cout << e.what() << std::endl;
  }
}