#Compilo et flags
CXX = c++

CXXFLAGS = -Wall -Werror  -Wextra -pedantic  -g3

#Fichiers sources
SRCS = main.cpp\
		Source/List/StudentList.cpp\
		Source/List/RoomList.cpp\
		Source/List/CourseList.cpp\
		Source/List/StaffList.cpp\
		Source/Person/Person.cpp\
		Source/Person/Student.cpp\
		Source/Person/Staff.cpp\
		Source/Person/Professor.cpp\
		Source/Person/Headmaster.cpp\
		Source/Person/Secretary.cpp\
		Source/Form/Form.cpp\
		Source/Form/CourseFinishedForm.cpp\
		Source/Form/NeedMoreClassRoomForm.cpp\
		Source/Form/NeedCourseCreationForm.cpp\
		Source/Form/SubscriptionToCourseForm.cpp\
		Source/Course/Course.cpp\
		Source/Room/Room.cpp\
		Source/Room/Classroom.cpp\
		Source/Room/SecretarialOffice.cpp\
		Source/Room/HeadmasterOffice.cpp\
		Source/Room/StaffRestRoom.cpp\
		Source/Room/Courtyard.cpp\

#Fichiers objets
OBJS = $(SRCS:.cpp=.o)

# Fichiers de dépendances



#Nom de l'executable
NAME = simulation

#Règles de compilation
all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

#Règles de compilation des fichiers objets
-include $(DEPS)



clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

