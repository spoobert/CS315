CFLAGS = -ggdb -std=c++11 -Wall

binTree.x: main.o BinSearchTree.o
	g++ $(CFLAGS) main.o BinSearchTree.o -o binTree.x

main.o: main.cpp BinSearchTree.cpp
	g++ $(CFLAGS) -c main.cpp -o main.o

BinSearchTree.o: BinSearchTree.cpp BinSearchTree.hpp TreeNode.hpp
	g++ $(CFLAGS) -c BinSearchTree.cpp -o BinSearchTree.o

clean:
	rm  *o, *x, *~
