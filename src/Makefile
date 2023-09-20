LIBS = -lglut -lGLU -lGL

all: run

run : main.o Point.o Line.o
	g++ -o run main.o Line.o Point.o $(LIBS) 

main : main.cpp
	g++ -c main.cpp

Point.o: Point.cpp
	g++ -c Point.cpp

Line.o: Line.cpp
	g++ -c Line.cpp

clean:
	rm -f run main.o Point.o Line.o