

CFLAGS = -ggdb -std=c++11 -Wall

all:main.x # linearlyNested_iter.x linearlyNested_rec.x

main.x: main.o Lex.o Token.o
	g++ $(CFLAGS) main.o Lex.o Token.o -o main.x

main.o: main.cpp Lex.hpp Token.hpp
	g++ $(CFLAGS) -c main.cpp  -o main.o

Lex.o: Lex.cpp Lex.hpp Token.hpp
	g++ $(CFLAGS) -c Lex.cpp  -o Lex.o

Token.o: Token.cpp Token.hpp
	g++ $(CFLAGS) -c Token.cpp -o Token.o

linearlyNested_iter.x: linearlyNestedParentheses_iter.o Lex.o
	g++ $(CFLAGS) linearlyNestedParentheses_iter.o Lex.o -o linearlyNested_iter.x

linearlyNestedParentheses_iter.o: linearlyNestedParentheses_iter.cpp Lex.hpp Token.hpp
	g++ $(CFLAGS) -c linearlyNestedParentheses_iter.cpp -o linearlyNestedParentheses_iter.o

linearlyNested_rec.x: linearlyNestedParentheses_rec.o Lex.o
	g++ $(CFLAGS) linearlyNestedParentheses_rec.o Lex.o -o linearlyNested_rec.x

linearlyNestedParentheses_rec.o: linearlyNestedParentheses_rec.cpp Lex.hpp Token.hpp
	g++ $(CFLAGS) -c linearlyNestedParentheses_rec.cpp -o linearlyNestedParentheses_rec.o

clean:
	rm -f *.o *.x *~
