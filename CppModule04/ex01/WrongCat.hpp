#pragma once
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(WrongCat &copy);
        WrongCat &operator=(WrongCat &copy);
        void makeSound() const;
        virtual ~WrongCat();
};
