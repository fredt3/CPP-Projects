all: program
	./program
program: main.o Bag.o
	g++ main.o Bag.o -o program
main.o: main.cpp
	g++ -c main.cpp
Bag.o: Bag.cpp
	g++ -c Bag.cpp
clean:
	rm -rf *o program
