CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Iter

SRC = main.cpp

INCLUDES = iter.hpp

OBJ = $(SRC:.cpp=.o)


$(NAME) : $(OBJ) $(INCLUDES)
	$(CXX) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)