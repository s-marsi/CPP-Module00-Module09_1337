#pragma once

#include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(Animal &copy);
        Animal &operator=(Animal &copy);
        virtual void makeSound() const = 0;
        std::string getType() const;
        void setType(std::string _type);
        virtual ~Animal();
};