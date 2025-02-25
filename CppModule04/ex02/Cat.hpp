#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(Cat &copy);
        Cat &operator=(Cat &copy);
        void makeSound() const;
        Brain *getBrain();
        virtual ~Cat();
};
