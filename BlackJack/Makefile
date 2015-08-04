all: program
	./program
	
program: main.o Card.o LinkedList.o Node.o
	g++ main.o Card.o LinkedList.o Node.o -o program
	
main.o: main.cpp
	g++ -c main.cpp
	
Card.o: Card.cpp
	g++ -c Card.cpp
	
LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp
	
Node.o: Node.cpp
	g++ -c Node.cpp
	
clean:
	rm -rf *o program
