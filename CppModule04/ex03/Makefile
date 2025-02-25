CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

NAME = Polymorphism

FILES = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp garbage.cpp

INCLUDES = AMateria.hpp ICharacter.hpp Ice.hpp Cure.hpp Character.hpp MateriaSource.hpp IMateriaSource.hpp garbage.hpp

OBJ = $(FILES:.cpp=.o)

$(NAME) : $(OBJ) $(INCLUDES)
	$(CXX) $(OBJ) -o $(NAME)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)