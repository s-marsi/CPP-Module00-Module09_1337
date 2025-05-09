#include "../headers/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(): file_name("")  { }

BitcoinExchange::BitcoinExchange(std::string &input): file_name(input), _file(input.c_str()) { 
    if (!_file.is_open()) {
        throw  std::runtime_error ("Error: Unable to open file!");
    }
}


BitcoinExchange::BitcoinExchange(BitcoinExchange &rhs): _file(rhs.file_name.c_str()) { *this = rhs; }

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &rhs)
{

    if (this != &rhs)
    {
        file_name = rhs.file_name;
        if (_file.is_open())
            _file.close();
        _file.open(file_name.c_str());
        data = rhs.data;
        map = rhs.map;
    }
    return (*this);
}

int BitcoinExchange::numberRange(double nbr) { 
    return ( (nbr >= 0 && nbr <= 1000) ? 0 : (nbr < 0) ? 1 : 2 ); 
}

bool check_first_last_character(std::string &number) // firt is a space, last is a digit
{
    return (number[0] != ' ' || ! std::isdigit(number[number.length() - 1]));
}

bool check_valid_dot_digit(Data &data) {
    std::string &number = data.value;
    int dot_counter = 0;
    if ( number[1] && number[1] != '-' && !std::isdigit(number[1]) ) // not - and not digit like: date | .1
        return (false);
    for (size_t i = 1; i < number.length(); i++) {
        if (number[i] == '.')
            dot_counter++;
        else if (i == 1 && number[i] == '-')
            continue;
        if ( dot_counter > 1 ) //case like (1..1, 1.1.1, 1r1) 
            return (false);
        if (!std::isdigit(number[i]))
            return (false);
    }
    return (true);
}

void BitcoinExchange::is_valid_number(Data &data, std::string &line) {
    std::string &number = data.value;
    if (check_first_last_character(number) || !check_valid_dot_digit(data)) {
        data.date = "Error: bad input => ";
        data.value = line;
        return ;
    }

    int is_number = numberRange(std::atof(data.value.c_str()));
    if (!is_number)
        return ;
    if (is_number == 1)
        data.date = "Error: not a positive number.";
    else if (is_number == 2)
        data.date = "Error: too large a number.";
    data.value = "";
}

void BitcoinExchange::check_syntax(Data &data, std::string &line) {
    // if (data.value && data.value[0] != ' ')
        // continue working on check syntax for number ...
    is_valid_number(data, line);
}

void BitcoinExchange::parseData() {
    int i = 0;
    std::string line;
    while (std::getline (_file, line)) {
        Data data;
        std::size_t pos = line.find('|', 0);
        std::string line_before_pipe  = line;
        std::string line_after_pipe  = line;

        if (pos != std::string::npos) {
            line_before_pipe.erase(pos);
            line_after_pipe.erase(0, pos + 1);
            data.date = line_before_pipe;
            data.value = line_after_pipe;
            check_syntax(data, line);
        }
        else { // No pipe FOund
            data.date = "Error: bad input => ";
            data.value = line;
        }
        map.insert(std::pair<int, Data>(i, data));
        i++;
    }
    iterator first = map.begin();
    iterator last = map.end();
    while (first != last) {
        std::cout << first->second.date << first->second.value << std::endl;
        first++;
    }
}

BitcoinExchange::~BitcoinExchange() { _file.close(); }