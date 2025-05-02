#include <iostream>
#include <stdint.h>

struct Data {
    int         age;
    std::string name;
};

class Serializer
{
    Serializer();
    Serializer(Serializer &rhs);
    Serializer &operator=(Serializer &rhs);
    ~Serializer();
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};