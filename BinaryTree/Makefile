all: program
	./program
	
program: main.o BST.o Node.o
	g++ -g main.o BST.o Node.o -o program
	
main.o: main.cpp
	g++ -g -c main.cpp
	
BST.o: BST.cpp
	g++ -g -c BST.cpp
	
Node.o: Node.cpp
	g++ -g -c Node.cpp
	
clean:
	rm -rf *.o program
