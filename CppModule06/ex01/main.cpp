#include "Serializer.hpp"

int main()
{
    Data data = { "Test", 26 };
    uintptr_t dataAdd = Serializer::serialize(&data);
    Data *dataBack = Serializer::deserialize(dataAdd);
    std::cout << "----------------- " << dataBack->name << " - " << dataBack->age << "------------\n";
    return (0);
}