#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"

class iCharacter;

class Character: public ICharacter
{
    AMateria *slots[4];
    int slots_counter;
    public:
        Character();
        Character(std::string _name);
        Character(Character &copy);
        Character &operator=(Character &copy);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        virtual ~Character();
};
#endif