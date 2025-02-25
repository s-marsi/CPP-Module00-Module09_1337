#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource()
{
    slots_counter = 0; 
    garbage = NULL;
    for (int i = 0; i < 4; i++)
    {
        slots[i] = NULL;
    }
}

MateriaSource::MateriaSource(MateriaSource &copy)
{
    *this = copy;
}

MateriaSource &MateriaSource::operator=(MateriaSource &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            if (slots[i]){
                delete slots[i];
                slots[i] = NULL;
            }
            *slots[i] = *copy.slots[i];
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *copy)
{
    if (slots_counter < 4)
    {
        for (int i = 0; i < 4; i++)
        {
            if (!slots[i])
            {
                ft_lstadd_back(&garbage, ft_lstnew(copy));
                slots[i] = copy->clone();
                ft_lstadd_back(&garbage, ft_lstnew(slots[i]));
                slots_counter++;
                std::cout << " equipped with " << copy->getType() << " successfully at index: " << i << std::endl;
                break;
            }
            
        }
    }
    else
        std::cout << " have max slots." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (slots[i] && slots[i]->getType() == type)
        {
            std::cout << "AMateria created." << std::endl;
            if (type == "cure")
                return (new Cure());
            else if (type == "ice")
                return  (new Ice());
        }
            
    }
    std::cout << "AMateria not created." << std::endl;
    return (0);
}


MateriaSource::~MateriaSource()
{
    ft_lstclear(&garbage);
}
