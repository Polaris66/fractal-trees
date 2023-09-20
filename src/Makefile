LIBS = -lglut -lGLU -lGL

all: run

run : main.o Point.o Line.o Circle.o
	g++ -o run main.o Circle.o Line.o Point.o $(LIBS) 

main : main.cpp
	g++ -c main.cpp

Point.o: Point.cpp
	g++ -c Point.cpp

Line.o: Line.cpp
	g++ -c Line.cpp

Circle.o: Circle.cpp
	g++ -c Circle.cpp

clean:
	rm -f run main.o Point.o Line.o Circle.o