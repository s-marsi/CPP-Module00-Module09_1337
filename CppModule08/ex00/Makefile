CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Easy

SRC = main.cpp

INCLUDES = easyfind.hpp #easyfind.tpp

OBJ = $(SRC:.cpp=.o)


$(NAME) : $(OBJ) $(INCLUDES)
	$(CXX) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)