#include "Serializer.hpp"

int main()
{
    Data data = { 26, "Test" };
    uintptr_t dataAdd = Serializer::serialize(&data);
    int *d = reinterpret_cast<int *>(&data);
    std::cout << "P = " << *d << std::endl;
    d++;
    std::string *p = reinterpret_cast<std::string *>(d);
    std::cout << "P = " << p << std::endl;
    Data *dataBack = Serializer::deserialize(dataAdd);
    std::cout << "----------------- " << dataBack->name << " - " << dataBack->age << "------------\n";
    return (0);
}