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
bool numberRange(double nbr);
bool check_first_last_character(std::string &number);
bool check_valid_dot_digit(Data &data);
bool check_date_format(std::string &date);
bool is_only_digit(std::string &str);
bool is_in_date_range(std::string &year, std::string &month, std::string &day);
class BitcoinExchange
{
    private:
        std::string file_name;
        std::ifstream _file;
        Data data;
        std::map<std::string, float> csv_data;
        BitcoinExchange();
    public:
        void load_csv();
        BitcoinExchange(std::string &inputinput);
        BitcoinExchange(BitcoinExchange &rhs);
        BitcoinExchange &operator=(BitcoinExchange &rhs);
        void parseData(); // parse the input file
        void check_syntax(Data &data, std::string &line);
        void is_valid_number(Data &data, std::string &line);
        void is_valid_date(Data &data, std::string &line);
        ~BitcoinExchange();
};

#endif