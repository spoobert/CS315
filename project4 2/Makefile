CFLAGS = -ggdb -std=c++11 -Wall


Main.x: Main.o Lex.o FileSystemBuilder.o DirectoryEntry.o
	g++ $(CFLAGS) Main.o DirectoryEntry.o Lex.o FileSystemBuilder.o -o Main.x

FileSystemBuilder.o: FileSystemBuilder.hpp FileSystemBuilder.cpp  DirectoryEntry.hpp
	g++ $(CFLAGS) -c FileSystemBuilder.cpp -o FileSystemBuilder.o

Main.o: Main.cpp DirectoryEntry.hpp Lex.hpp
	g++ $(CFLAGS) -c Main.cpp -o Main.o 

Lex.o: Lex.cpp Lex.hpp Token.hpp
	g++ $(CFLAGS) -c Lex.cpp  -o Lex.o

DirectoryEntry.o: DirectoryEntry.cpp DirectoryEntry.hpp Lex.hpp Token.hpp
	g++ $(CFLAGS) -c DirectoryEntry.cpp -o DirectoryEntry.o

clean:
	rm -f *.o *.x *~
