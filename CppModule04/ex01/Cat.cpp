#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Constructor Called" << std::endl;
    type = "Cat";
    brain = new Brain();
}

Cat::Cat(Cat &copy)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
    brain = new Brain();
    *this = copy;
}

Cat &Cat::operator=(Cat &copy)
{
    std::cout << "Cat Assignement Operator Called" << std::endl;
    if (this != &copy)
    {
        type = copy.type;
        delete brain;
        brain = new Brain();
        *brain = *copy.brain;
    }
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "Muaw" << std::endl;
}

Brain *Cat::getBrain()
{
    return (brain);
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;
    delete brain;
}
