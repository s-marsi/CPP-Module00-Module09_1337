#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

struct Data {
    std::string date;
    int         value;
    Data        *next;
};

class BitcoinExchange
{
    private:
        Data data;
        std::map<int, Data> map;
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange &rhs);
        BitcoinExchange &operator=(BitcoinExchange &rhs);
        ~BitcoinExchange();
};

#endif