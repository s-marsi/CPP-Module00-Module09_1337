#include "headers/BitcoinExchange.hpp"

int main(int ac , char *av[])
{
    try {
        if (ac != 2) {
            std::cout << "You must pass a file as argument.\n";
            return ( 1 );
        }
        std::string file(av[1]);
        BitcoinExchange btc(file);
    
        btc.parseData();
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}