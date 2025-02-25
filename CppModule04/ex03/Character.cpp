#include "Character.hpp"


Character::Character() {
    name = "";
    slots_counter = 0;
    garbage = NULL;
    for (int i = 0; i < 4; i++)
    {
        slots[i] = NULL;
    }
}

Character::Character(std::string _name)
{

    name = _name;
    slots_counter = 0;
    garbage = NULL;
    for (int i = 0; i < 4; i++)
    {
        slots[i] = NULL;
    }
}

Character::Character(Character &copy)
{
    *this = copy;
}

Character &Character::operator=(Character &copy)
{
    if (this != &copy)
    {
        name = copy.name;
        for (int i = 0; i < 4; i++)
        {
            if (slots[i])
            {
                delete slots[i];
                slots[i] = NULL;
            }
            if (copy.slots[i])
                slots[i] = copy.slots[i]->clone();
        }
    }
    return (*this);
}


std::string const & Character::getName() const
{
    return (name);
}

void Character::equip(AMateria* m)
{
    if (m && slots_counter < 4)
    {
        for (int i = 0; i < 4; i++)
        {
            if (!slots[i])
            {
                slots[i] = m;
                ft_lstadd_back(&garbage, ft_lstnew(m));
                slots_counter++;
                std::cout << name << " equipped with " << m->getType() << " successfully at index: " << i << std::endl;
                break;
            }
            
        }
    }
    else
        std::cout << name + " have max slots." << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
    {
        slots[idx] = NULL;
        std::cout << name + " unequiped at index: " << idx << std::endl;
        slots_counter--;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && slots[idx])
    {
        slots[idx]->use(target);
    }
    else
        std::cout << name + "unexisting Materia" << std::endl;
}

Character::~Character()
{
    ft_lstclear(&garbage);
}
