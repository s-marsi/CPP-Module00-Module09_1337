CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = FileReplacing

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)


$(NAME) : $(OBJ)
	$(CXX) $(OBJ) -o $(NAME)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)
