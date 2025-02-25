#pragma once

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal &copy);
        WrongAnimal &operator=(WrongAnimal &copy);
        void makeSound() const;
        std::string getType() const;
        void setType(std::string _type);
        virtual ~WrongAnimal();
};