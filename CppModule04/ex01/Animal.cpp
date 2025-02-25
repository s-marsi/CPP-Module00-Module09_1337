#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Constructor Called" << std::endl;
    type = "Animal";
}

Animal::Animal(Animal &copy)
{
    std::cout << "Animal Copy Constructor Called" << std::endl;
    *this = copy;
}

Animal &Animal::operator=(Animal &copy)
{
    std::cout << "Animal Assignment Operator Called" << std::endl;
    if (this != &copy)
    {
        type = copy.type;
    }
    return (*this);
}

std::string Animal::getType() const
{
    return (type);
}

void    Animal::makeSound() const
{
    std::cout << "No Sound" << std::endl;
}

void Animal::setType(std::string _type)
{
    type = _type;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}
