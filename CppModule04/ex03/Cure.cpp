#include "Cure.hpp"

Cure::Cure() { type = "cure"; }

Cure::Cure(Cure &copy) { *this = copy; }

Cure &Cure::operator=(Cure &copy)
{
    if (this != &copy)
        type = copy.getType();
    return (*this);
}

AMateria* Cure::clone() const { return (new Cure()); }

void Cure::use(ICharacter& target)
{
    std::cout << "Cure: \"* heals " + target.getName() + "\'s wounds *\"" << std::endl;
}

Cure::~Cure() { }
