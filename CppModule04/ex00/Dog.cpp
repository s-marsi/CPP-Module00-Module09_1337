#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Constructor Called" << std::endl;
    type = "Dog";
}

Dog::Dog(Dog &copy)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(Dog &copy)
{
    std::cout << "Dog Assignement Operator Called" << std::endl;
    if (this != &copy)
    {
        type = copy.type;
    }
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "Bark" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;

}
