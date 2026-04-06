NAME		=	leak_information
CXX			=	c++
CXXFLAGS		=	-Wall -Werror -Wextra -std=c++98
SRC_FILES	=	tests.cpp Account.cpp
OBJ_FILES	=	$(SRC_FILES:.cpp=.o)

OBJ			=	$(OBJ_FILES)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re