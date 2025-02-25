#include "Ice.hpp"

Ice::Ice() { type = "ice"; }

Ice::Ice(Ice &copy) { *this = copy; }

Ice &Ice::operator=(Ice &copy)
{
    if (this != &copy)
    {

    }
    return (*this);
}

AMateria* Ice::clone() const { return (new Ice()); }

void Ice::use(ICharacter& target)
{
    std::cout << "Ice: \"* shoots an ice bolt at " + target.getName() + " *\"" << std::endl;
}

Ice::~Ice() { }
