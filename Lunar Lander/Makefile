all:program
	./program
program: main.o Lunar.o
	g++ main.o Lunar.o -o program 
	
	
	
main.o: main.cpp
	g++ -c main.cpp
	
Cat.o: Lunar.cpp
	g++ -c Lunar.cpp
	
clean:
	rm -rf *o program	
