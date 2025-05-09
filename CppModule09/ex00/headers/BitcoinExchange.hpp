#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>


struct Data {
    std::string date;
    std::string value;
    Data        *next;
};
typedef std::map<int, Data>::iterator iterator;

class BitcoinExchange
{
    private:
        std::string file_name;
        std::ifstream _file;
        Data data;
        std::map<int, Data> map;
        BitcoinExchange();
    public:
        BitcoinExchange(std::string &inputinput);
        BitcoinExchange(BitcoinExchange &rhs);
        BitcoinExchange &operator=(BitcoinExchange &rhs);
        int numberRange(double nbr);
        void parseData();
        void check_syntax(Data &data, std::string &line);
        void is_valid_number(Data &data, std::string &line);
        ~BitcoinExchange();
};

#endif