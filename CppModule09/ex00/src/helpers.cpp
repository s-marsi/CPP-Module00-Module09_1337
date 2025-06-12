#include "../headers/BitcoinExchange.hpp"

bool numberRange(double nbr) { 
    return ( (nbr >= 0 && nbr <= 1000) ? 0 : (nbr < 0) ? 1 : 2 ); 
}

bool check_first_last_character(std::string &number) // firt is a space, last is a digit
{
    return (number[0] != ' ' || !std::isdigit(number[number.length() - 1]));
}

bool check_valid_dot_digit(Data &data) {
    std::string &number = data.value;
    int dot_counter = 0;
    if ( number[1] && number[1] != '-' && !std::isdigit(number[1]) ) // not - and not digit like: date | .1
        return (false);
    for (size_t i = 1; i < number.length(); i++) {
        if (i == 1 && number[i] == '-')
            continue;
        if (number[i] == '.')
            dot_counter++;
        else if (!std::isdigit(number[i]))
            return (false);
        if ( dot_counter > 1 ) //case like (1..1, 1.1.1, 1r1) 
            return (false);
    }
    return (true);
}

bool check_date_format(std::string &date) {    
    //       start with digit              space in the end                   length is 11            - after year and month
    return (!std::isdigit(date[0]) ||  date[date.length() - 1] != ' ' || date.length() != 11 || date.at(4) != '-' || date.at(7) != '-');
}

bool is_only_digit(std::string &str) {
    for (size_t i = 0; i < str.length(); i++){
        if (!std::isdigit(str[i]))
            return (false);
    }
    return (true);
}

bool is_in_date_range(std::string &year, std::string &month, std::string &day) {
    time_t      timestamp = time(NULL);
    struct tm   *date = localtime(&timestamp);
    char        current_year[5];
    strftime(current_year, 5, "%Y", date);
    if (atoi(year.c_str()) < 0 || atoi(year.c_str()) > atoi(current_year))
        return (false);
    
    if (atoi(month.c_str()) < 1 || atoi(month.c_str()) > 12)
        return (false);
    if ( ( atoi(month.c_str() ) == 2 && ( atoi(day.c_str()) < 1  ||  atoi(day.c_str()) > 29)))
        return (false);
    if ( atoi(day.c_str()) < 1 ||  atoi(day.c_str()) > 31 )
        return (false);     
    return (true);
}