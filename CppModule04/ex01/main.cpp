#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "\n\n---------- array of Animal objects ---------\n" << std::endl;
    Animal *animal[] = {new Dog(), new Cat(), new Dog(), new Cat()};
    for (int i = 0; i < 4; i++)
    {
        delete animal[i];
    }

    std::cout << "\n\n---------- Exercice Test ---------\n" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//
    delete i;

    std::cout << "\n\n---------- Shallow copy Test ---------\n" << std::endl;

    Cat cat;
    Cat catTest = cat;  

    std::cout << "\n-------------------\n";

    std::cout << cat.getBrain() << std::endl;
    std::cout << catTest.getBrain() << std::endl;
    
    std::cout << "\n-------------------\n";

}