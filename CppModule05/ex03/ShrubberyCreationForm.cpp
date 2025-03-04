#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 139) { }

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery", 145, 137), _target(target) { }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &rhs): AForm(rhs.getName(), rhs.getGraderequired(), rhs.getGradeExecute()) { 
    *this = rhs;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &rhs)
{
    if (this != &rhs)
    {
        this->setIsSigned(rhs.getIsSigned());
        _target = rhs._target;
    }
    return (*this);
}

void    ShrubberyCreationForm::executeAction() const
{
    std::string fileName = _target + "_shrubbery";
    std::ofstream	outFile;
    outFile.open(fileName.c_str(), std::ios::trunc | std::ios::out);
    outFile << "                                                |\n";
    outFile << "                                          -x-\n";
    outFile << "                                           |\n";
    outFile << "          v .   ._, |_  .,\n";
    outFile << "       `-._\\/  .  \\ /    |/_\n";
    outFile << "           \\  _\\, y | \\//\n";
    outFile << "     _\\_.___\\, \\/ -.\\||\n";
    outFile << "       `7-,--.`._||  / / ,\n";
    outFile << "       /'     `-. `./ / |/_.'\n";
    outFile << "                 |    |//\n";
    outFile << "                 |_    /\n";
    outFile << "                 |-   |\n";
    outFile << "                 |   =|\n";
    outFile << "                 |    |\n";
    outFile << "--------------------/ ,  . \\--------._\n";
}


ShrubberyCreationForm::~ShrubberyCreationForm() { }
