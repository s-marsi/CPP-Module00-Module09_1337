#include <cstdint>
#include <iostream>

struct Data {
    std::string name;
    int         age;
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