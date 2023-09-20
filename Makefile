# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -Wall -g -std=c++17

# OpenGL and GLUT libraries
LIBS = -lglut -lGL -lglut

# Source files and output executable
SRCS = main.cpp 
TARGET = run

all: clean $(TARGET)

$(TARGET) : $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(TARGET)
