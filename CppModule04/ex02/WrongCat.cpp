#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat Constructor Called" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &copy)
{
    std::cout << "WrongCat Copy Constructor Called" << std::endl;
    *this = copy;
}

WrongCat &WrongCat::operator=(WrongCat &copy)
{
    std::cout << "WrongCat Assignement Operator Called" << std::endl;
    if (this != &copy)
    {
        type = copy.type;
    }
    return (*this);
}

void    WrongCat::makeSound() const
{
    std::cout << "Muaw" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor Called" << std::endl;

}
