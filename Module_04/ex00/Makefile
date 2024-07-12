NAME = ex00

SRCS = main.cpp \

SRCS_PERSON = Person/Person.cpp \

SRCS_IROOM = IRoom/IRoom.cpp \

OBJS = $(SRCS:.cpp=.o) $(SRCS_PERSON:.cpp=.o) $(SRCS_IROOM:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++17

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all