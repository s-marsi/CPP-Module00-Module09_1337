#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Constructor Called" << std::endl;
}

Brain::Brain(Brain &copy)
{
    std::cout << "Animal Copy Constructor Called" << std::endl;
    *this = copy;
}

Brain &Brain::operator=(Brain &copy)
{
    std::cout << "Animal Assignement Operator Called" << std::endl;
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
        {
            ideas[i] = copy.ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Called" << std::endl;
}
