#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() 
{
    std::cout << "WrongAnimal Constructor Called" << std::endl;
    type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal &copy)
{
    std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
    *this = copy;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &copy)
{
    std::cout << "WrongAnimal Assignment Operator Called" << std::endl;
    if (this != &copy)
    {
        type = copy.type;
    }
    return (*this);
}

std::string WrongAnimal::getType() const
{
    return (type);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal Sound" << std::endl;
}

void WrongAnimal::setType(std::string _type)
{
    type = _type;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor Called" << std::endl;
}
