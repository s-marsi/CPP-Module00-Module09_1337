CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

NAME = Polymorphism

FILES = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

INCLUDES = Dog.hpp Cat.hpp Animal.hpp WrongCat.hpp WrongAnimal.hpp Brain.hpp

OBJ = $(FILES:.cpp=.o)

$(NAME) : $(OBJ) $(INCLUDES)
	$(CXX) $(OBJ) -o $(NAME)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)