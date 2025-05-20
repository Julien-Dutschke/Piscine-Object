#Compilo et flags
CXX = c++

CXXFLAGS = -Wall -Werror  -Wextra -pedantic -MMD -g3

#Fichiers sources
SRCS = main.cpp\
		Source/StudentList.cpp\
		Source/RoomList.cpp\
		Source/CourseList.cpp\
		Source/StaffList.cpp\

#Fichiers objets
OBJS = $(SRCS:.cpp=.o)

# Fichiers de dépendances
DEPS = $(OBJS:.o=.d)


#Nom de l'executable
NAME = simulation

#Règles de compilation
all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

#Règles de compilation des fichiers objets
-include $(DEPS)



clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

