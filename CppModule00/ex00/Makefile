CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

FILES_C = megaphone.cpp

FILES_O = $(FILES_C:.cpp=.o)

$(NAME) : $(FILES_O)
	$(CXX) $(CXXFLAGS)  -o $(NAME) $(FILES_O)

all : $(NAME)

clean :
	rm -f $(FILES_O)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)