CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = PmergeMe

SRC = main.cpp PmergeMe.cpp

INCLUDES = PmergeMe.hpp merge_sort.tpp binary_search_insertion.tpp
OBJ = $(SRC:.cpp=.o)


$(NAME) : $(OBJ) $(INCLUDES)
	$(CXX) $(OBJ) -o $(NAME) -fsanitize=address -g3
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)