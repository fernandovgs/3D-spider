checkerboard:
	g++ checkerboard.cpp -c -lm -lglut -lGL -lGLU -g -Wall
spider:
	g++ spider.cpp -c -lm -lglut -lGL -lGLU -g -Wall
main:
	g++ main.cpp -c -lm -lglut -lGL -lGLU -g -Wall
compile:
	g++ main.o checkerboard.o spider.o -o exe -lm -lglut -lGL -lGLU -g -Wall
run:
	./exe
clean:
	rm *.o
all: checkerboard	spider	main	compile	run