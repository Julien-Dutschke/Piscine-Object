NAME = WorkStarter

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp\
	  Worker/Worker.cpp\
	  Workshop/Workshop.cpp\
	  Tool/Tool.cpp\
	  Shovel/Shovel.cpp\
	  Hammer/Hammer.cpp\

OBJ = $(SRC:.cpp=.o)

all: $(NAME)


$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

