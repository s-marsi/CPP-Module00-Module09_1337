#include "Base.hpp"

int main()
{
    {
        Base *p = generate();
        identify(p);
        free (p);
    }

    std::cout << "---------------------------------------------------" << std::endl;

    {
        Base *p = generate();
        identify(*p);
        free (p);
    }
    return (0);
}