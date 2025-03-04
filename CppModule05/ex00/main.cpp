#include "Bureaucrat.hpp"

int main() {



  std::cout << "------------------- Test GradeTooHighException --------------------\n" << std::endl;
  try {
    Bureaucrat bureaucrat(0);
  } 
  catch (std::exception & e) {
    std::cerr << "Error: " << e.what()<< std::endl;
  }





  std::cout << "\n\n------------------- Test GradeTooLowException --------------------\n" << std::endl;

  try {
    Bureaucrat bureaucrat(151);
  } 
  catch (std::exception & e) {
    std::cerr << "Error: " << e.what()<< std::endl;
  }




  std::cout << "\n\n------------------- Test Valid Grade --------------------\n" << std::endl;

  try {
    Bureaucrat bureaucrat("test", 150);
    std::cout << bureaucrat << std::endl;
  } 
  catch (std::exception & e) {
    std::cerr << "Error: " << e.what()<< std::endl;
  }





  std::cout << "\n\n------------------- Test Increment Grade --------------------\n" << std::endl;

  try {
    Bureaucrat bureaucrat("IncrementEmployee", 5);
    for (int i = 0; i < 10; i++)
    {
      std::cout << bureaucrat << std::endl;
      bureaucrat.incrementGrade();
    }
    std::cout << bureaucrat << std::endl;
  } 
  catch (std::exception & e) {
    std::cerr << "Error: " << e.what()<< std::endl;
  }




  std::cout << "\n\n------------------- Test Decrement Grade --------------------\n" << std::endl;

  try {
    Bureaucrat bureaucrat("DecrementEmployee", 145);
    for (int i = 0; i < 10; i++)
    {
      std::cout << bureaucrat << std::endl;
      bureaucrat.decrementGrade();
    }
    std::cout << bureaucrat << std::endl;
  } 
  catch (std::exception & e) {
    std::cerr << "Error: " << e.what()<< std::endl;
  }

}