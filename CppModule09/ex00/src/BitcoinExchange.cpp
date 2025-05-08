#include "../headers/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { }

BitcoinExchange::BitcoinExchange(BitcoinExchange &rhs) { *this = rhs; }

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &rhs)
{
    data = rhs.data;
    map = rhs.map;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() { }