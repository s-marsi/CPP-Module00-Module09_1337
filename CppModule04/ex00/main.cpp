#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete i;

    
    std::cout << "\n\n------- Wrong Test ---------\n\n" << std::endl;
    const WrongAnimal* test = new WrongAnimal();
    const WrongAnimal* test2 = new WrongCat();
    std::cout << test2->getType() << " " << std::endl;

    test->makeSound();
    test2->makeSound(); //will output the Wrongcat sound!
    delete test;
    delete test2;
}