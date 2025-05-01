#include "Base.hpp"

Base::~Base() { };

Base * generate(void)
{
    srand(time(0));
    int randomNum = rand() % 3;
    switch (randomNum)
    {
        case 0:
            return (new A);
            break;
        case 1:
            return (new B);
            break;
        default:
            break;
    }
    return (new C);
}

void identify(Base* p)
{
    A *a; B *b; C *c;
    a = dynamic_cast<A *> (p);
    b = dynamic_cast<B *> (p);
    c = dynamic_cast<C *> (p);
    if (a != 0)
        std::cout << "the actual type of the object pointed to by p: A\n";
    else if (b != 0)
        std::cout << "the actual type of the object pointed to by p: B\n";
    else if (c != 0)
        std::cout << "the actual type of the object pointed to by p: C\n";
}

void identify(Base& p)
{
    Base tmp;
    try {
        tmp = dynamic_cast<A &> (p);
        std::cout << "the actual type of the object pointed to by reference p: A\n";
    }
    catch (...) {
        try {
            tmp = dynamic_cast<B &> (p);
            std::cout << "the actual type of the object pointed to by reference p: B\n";
        }
        catch (...) {
            try {
                tmp = dynamic_cast<C &> (p);
                std::cout << "the actual type of the object pointed to by reference p: C\n";
            }
            catch (...) {
                std::cout << "No Type\n";
            }
        }
    }
}
