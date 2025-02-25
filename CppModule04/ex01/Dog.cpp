#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Constructor Called" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(Dog &copy)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
    brain = new Brain();
    *this = copy;
}

Dog &Dog::operator=(Dog &copy)
{
    std::cout << "Dog Assignement Operator Called" << std::endl;
    if (this != &copy)
    {
        type = copy.type;
        delete brain;
        brain = new Brain();
        *brain = *copy.brain;
    }
    return (*this);
}

Brain *Dog::getBrain()
{
    return (brain);
}


void    Dog::makeSound() const
{
    std::cout << "Bark" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
    delete brain;
}
