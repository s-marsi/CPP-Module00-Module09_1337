#include "easyfind.hpp"

int main() {
    {
        std::vector<int> arr;
        try {
            arr.push_back(0);
            arr.push_back(1);
            arr.push_back(2);
            arr.push_back(3);
            arr.push_back(4);
            easyfind(arr, 5);
        } catch (char const*e) {
            std::cout << e;
        } catch (...) {
            std::cout << "vector error.\n";
        }
    }
    return (0);
}