#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP
#include "AMateria.hpp"
#include "garbage.hpp"
#include <iostream>


class AMateria;
typedef struct s_garbage t_garbage;
class ICharacter
{
    protected:
        std::string name;
        t_garbage *garbage;
    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};
#endif