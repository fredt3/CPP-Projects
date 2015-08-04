all: program
	./program
program: main.o LargeInt.o
	g++ main.o LargeInt.o -o program
main.o: main.cpp
	g++ -c main.cpp
LargeInt.o: LargeInt.cpp
	g++ -c LargeInt.cpp
clean:
	rm -rf *o program
