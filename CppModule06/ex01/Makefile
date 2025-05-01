CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Conversion

SRC = main.cpp

INCLUDES =

OBJ = $(SRC:.cpp=.o)


$(NAME) : $(OBJ) $(INCLUDES)
	$(CXX) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
