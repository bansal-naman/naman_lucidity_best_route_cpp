CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

SRCS = unit_tests.cpp location.cpp delivery_executive.cpp utils.cpp restaurant.cpp consumer.cpp order.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = "BestRoute"

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
