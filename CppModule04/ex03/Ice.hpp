#pragma once
#include "ICharacter.hpp"

class Ice: public AMateria
{
    public:
        Ice();
        Ice(Ice &copy);
        Ice &operator=(Ice &copy);
        AMateria* clone() const;
        void use(ICharacter& target);
        ~Ice();
};
