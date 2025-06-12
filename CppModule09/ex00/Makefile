CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = btc

SRC = main.cpp src/BitcoinExchange.cpp src/helpers.cpp

INCLUDES = headers/BitcoinExchange.hpp
OBJ = $(SRC:.cpp=.o)


$(NAME) : $(OBJ) $(INCLUDES)
	$(CXX) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)