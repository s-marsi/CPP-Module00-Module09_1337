#pragma once
#include "Animal.hpp"

class Cat: public Animal
{
    public:
        Cat();
        Cat(Cat &copy);
        Cat &operator=(Cat &copy);
        void makeSound() const;
        virtual ~Cat();
};
