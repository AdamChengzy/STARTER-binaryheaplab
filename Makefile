CXX      := g++
CXXFLAGS := -std=c++20 -Wall -Wextra -pedantic -g
LDFLAGS  :=

TARGET := examheap
SRCS   := examheap.cpp heap.cpp
OBJS   := $(SRCS:.cpp=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cpp heap.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)
