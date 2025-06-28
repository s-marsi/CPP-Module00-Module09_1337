#include "../headers/BitcoinExchange.hpp"

void BitcoinExchange::load_csv() {
    std::ifstream csv("resources/data.csv");
    if (!csv.is_open())
        throw  std::runtime_error ("Error: Unable to open data.csv file!");
    int i = 0;
    std::string line;
    std::getline(csv, line);
    while (std::getline(csv, line)) {
        std::size_t pos = line.find(',', 0);
        if (pos != std::string::npos) {
            std::string line_before_comma  = line;
            std::string line_after_comma  = line;
            line_before_comma.erase(pos);
            line_after_comma.erase(0, pos + 1);
            csv_data.insert(std::make_pair(line_before_comma, line_after_comma));
            i++;
        }
    }
}

BitcoinExchange::BitcoinExchange(): file_name(""), _file() { load_csv(); }

BitcoinExchange::BitcoinExchange(std::string &input): file_name(input), _file(input.c_str()) {
    if (!_file.is_open()) {
        throw  std::runtime_error ("Error: Unable to open file!");
    }
    load_csv();
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
        csv_data = rhs.csv_data;
    }
    return (*this);
}

void BitcoinExchange::is_valid_number(Data &data, std::string &line) {
    std::string &number = data.value;
    if (check_first_last_character(number) || !check_valid_dot_digit(data)) {
        data.date = "Error: bad input => ";
        data.value = line;
        return ;
    }
    int is_number = numberRange(std::atof(data.value.c_str()));
    if ( !is_number )
        return ;
    if ( is_number == 1 )
        data.date = "Error: not a positive number.";
    else if ( is_number == 2 )
        data.date = "Error: too large a number.";
    data.value = "";
}

void BitcoinExchange::is_valid_date(Data &data, std::string &line) {
    std::string &date = data.date;
    if ( check_date_format(date) )
    {
        data.date = "Error: bad input => ";
        data.value = line;
        return ;
    }
    std::string year = data.date;
    std::string month = data.date;
    std::string day = data.date;

    year.erase(4);
    month.erase(0, 5).erase(2);
    day.erase(0, 8).erase(2);
    if (!is_only_digit(year) || !is_only_digit(month) || !is_only_digit(day) || !is_in_date_range(atoi(year.c_str()), atoi(month.c_str()), atoi(day.c_str()))) {
        data.date = "Error: bad input => ";
        data.value = line;
        return ;
    }
}

void BitcoinExchange::check_syntax(Data &data, std::string &line) {
    is_valid_date(data, line);
    is_valid_number(data, line);
}

void BitcoinExchange::print_result(Data &data) {
    if (isdigit(data.date[0])) {
        std::map<std::string, std::string>::const_reverse_iterator searched;
        for (searched = csv_data.rbegin(); searched != csv_data.rend(); ++searched) {
            if (searched->first <= data.date) {
                break;
            }
        }
        if (searched == csv_data.rend())
            searched--;
        float value = std::atof(data.value.c_str()) * std::atof(searched->second.c_str());
        std::cout << data.date << " =>" << data.value << " = " << value << std::endl;
    }
    else {
        std::cout << data.date << data.value << std::endl;
    }
}

void BitcoinExchange::parseData() {
    int i = 0;
    std::string line;
    while (std::getline(_file, line)) {
        if (i == 0) {
            if (line !=  "date | value")
                std::cout << "Error: bad input => " << line << std::endl;
        }
        else {
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
                print_result(data);
            }
            else { // No pipe Found
                std::cout << "Error: bad input => " << line << std::endl;
            }
        }
        i++;
    }
}

BitcoinExchange::~BitcoinExchange() { _file.close(); }