main.x: main.o  gameBoard.o getChar.o
	g++ -ggdb -o main.x main.o gameBoard.o getChar.o -lcurses -ltermcap

main.o: main.cpp gameBoard.hpp
	g++ -c -ggdb main.cpp -o main.o

gameBoard.o: gameBoard.cpp
	g++ -c -ggdb gameBoard.cpp -o gameBoard.o

getChar.o: getChar.cpp
	gcc -c -ggdb getChar.cpp -o getChar.o

clean:
	/bin/rm -f screen.x screen.o getChar.o *~
