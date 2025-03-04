CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Bureaucrat

SRC = main.cpp  Bureaucrat.cpp GradeTooLowException.cpp GradeTooHighException.cpp Form.cpp

INCLUDES = Bureaucrat.hpp GradeTooLowException.hpp GradeTooHighException.hpp Form.hpp

OBJ = $(SRC:.cpp=.o)


$(NAME) : $(OBJ) $(INCLUDES)
	$(CXX) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
