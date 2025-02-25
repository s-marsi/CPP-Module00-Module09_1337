#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Constructor Called" << std::endl;
    type = "Cat";
}

Cat::Cat(Cat &copy)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
    *this = copy;
}

Cat &Cat::operator=(Cat &copy)
{
    std::cout << "Cat Assignement Operator Called" << std::endl;
    if (this != &copy)
    {
        type = copy.type;
    }
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "Muaw" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;

}
