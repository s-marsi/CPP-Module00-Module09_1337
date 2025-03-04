#include "Bureaucrat.hpp"

int main() {

  std::cout << "------------------- Test beSigned NUMBER 1 --------------------\n" << std::endl;
  try {
    Bureaucrat bureaucrat("Employe1", 10);
    Form form("Form1", 9, 11);
    std::cout << "isSigned: " << form.getIsSigned() << std::endl;
    form.beSigned(bureaucrat);
    std::cout << "isSigned: " << form.getIsSigned() << std::endl;
    bureaucrat.incrementGrade();
    form.beSigned(bureaucrat);
  } 
  catch (std::exception & e) {
    std::cerr << "Error: " << e.what()<< std::endl;
  }



  std::cout << "\n\n------------------- Test beSigned NUMBER 2 --------------------\n" << std::endl;
  try {
    Bureaucrat bureaucrat("Employe1", 9);
    Form form("Form1", 9, 11);
    std::cout << "isSigned: " << form.getIsSigned() << std::endl;
    form.beSigned(bureaucrat);
    bureaucrat.decrementGrade();
    std::cout << "isSigned: " << form.getIsSigned() << std::endl;
    form.beSigned(bureaucrat);
  } 
  catch (std::exception & e) {
    std::cerr << "Error: " << e.what()<< std::endl;
  }



  std::cout << "------------------- Test signForm NUMBER 1 --------------------\n" << std::endl;
  try {
    Bureaucrat bureaucrat("Employe1", 10);
    Form form("Form1", 9, 11);
    bureaucrat.signForm(form);
    bureaucrat.incrementGrade();
    bureaucrat.signForm(form);
  } 
  catch (std::exception & e) {
    std::cerr << "Error: " << e.what()<< std::endl;
  }



  std::cout << "\n\n------------------- Test signForm NUMBER 2 --------------------\n" << std::endl;
  try {
    Bureaucrat bureaucrat("Employe1", 9);
    Form form("Form1", 9, 11);
    bureaucrat.signForm(form);
    bureaucrat.decrementGrade();
    bureaucrat.signForm(form);
  } 
  catch (std::exception & e) {
    std::cerr << "Error: " << e.what()<< std::endl;
  }

}