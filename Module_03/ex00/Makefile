NAME = a.out

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp\
	   GazPedal.cpp\
	   Car.cpp\
	   GearLever.cpp\
	   ParkingBrake.cpp\
	   Steering.cpp\
	   IgnitionSystem.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

f: clean
	rm -rf $(NAME)

