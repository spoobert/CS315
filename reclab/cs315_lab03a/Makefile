

CFLAGS = -ggdb -std=c++11 -Wall	

all: echoAList.x linearlyNested_iter.x linearlyNested_rec.x

echoAList.x: echoAList.o Lex.o
	g++ $(CFLAGS) echoAList.o Lex.o -o echoAList.x

echoAList.o: echoAList.cpp Lex.hpp Token.hpp
	g++ $(CFLAGS) -c echoAList.cpp  -o echoAList.o 

Lex.o: Lex.cpp Lex.hpp Token.hpp
	g++ $(CFLAGS) -c Lex.cpp  -o Lex.o 


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
