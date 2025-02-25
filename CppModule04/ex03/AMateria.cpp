#include "ICharacter.hpp"

AMateria::AMateria(): type("") { }

std::string const & AMateria::getType() const
{
    return (type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "AMateria " + target.getName() << std::endl;
}

AMateria::~AMateria() { }