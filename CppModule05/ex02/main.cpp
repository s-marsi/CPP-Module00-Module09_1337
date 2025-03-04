#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

  std::cout << "\n\n------------------- PresidentialPardonForm -------------------\n" << std::endl;



  try
  {
  	PresidentialPardonForm formPresident("President");
  	Bureaucrat bureaucrat("MyBureaucrat", 6);
  	bureaucrat.signForm(formPresident);
  	formPresident.execute(bureaucrat);
  }
  catch (std::exception & e)
  {
    std::cout << e.what() << std::endl;
  }


  try
  {
  	PresidentialPardonForm formPresident("President");
    Bureaucrat bureaucrat("MyBureaucrat", 5);
  	bureaucrat.signForm(formPresident);
    formPresident.execute(bureaucrat);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }



  std::cout << "\n\n------------------- ShrubberyCreationForm -------------------\n" << std::endl;

  try
  {
    ShrubberyCreationForm formShrubbery("Shrubbery");
    Bureaucrat bureaucrat("MyBureaucrat", 138);
    bureaucrat.signForm(formShrubbery);
    formShrubbery.execute(bureaucrat);
  }
  catch (std::exception & e)
  {
    std::cout << e.what() << std::endl;
  }


  try
  {
    ShrubberyCreationForm formShrubbery("Shrubbery");
    Bureaucrat bureaucrat("MyBureaucrat", 137);
    bureaucrat.signForm(formShrubbery);
    formShrubbery.execute(bureaucrat);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }



  std::cout << "\n\n------------------- RobotomyRequestForm -------------------\n" << std::endl;

  try
  {
		RobotomyRequestForm formRobotomy("Robotomy");
		Bureaucrat bureaucrat("MyBureaucrat", 46);
		bureaucrat.signForm(formRobotomy);
    formRobotomy.execute(bureaucrat);
  }
  catch (std::exception & e)
  {
    std::cout << e.what() << std::endl;
  }


  try
  {
    RobotomyRequestForm formRobotomy("Robotomy");
		Bureaucrat bureaucrat("MyBureaucrat", 45);
		bureaucrat.signForm(formRobotomy);
    formRobotomy.execute(bureaucrat);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }

	std::cout << "\n\n------------------- Bureaucrat executeForm -------------------\n" << std::endl;

  try
  {
		RobotomyRequestForm formRobotomy("Robotomy");
		Bureaucrat bureaucrat("MyBureaucrat", 46);
		bureaucrat.signForm(formRobotomy);
		bureaucrat.executeForm(formRobotomy);
  }
  catch (std::exception & e)
  {
    std::cout << e.what() << std::endl;
  }


  try
  {
    RobotomyRequestForm formRobotomy("Robotomy");
		Bureaucrat bureaucrat("MyBureaucrat", 45);
		// bureaucrat.signForm(formRobotomy);
		bureaucrat.executeForm(formRobotomy);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
}