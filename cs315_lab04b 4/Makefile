CFLAGS = -ggdb -std=c++11 -Wall	

linearlyNested_rec.x: linearlyNestedParentheses_rec.o Lex.o 
	g++ $(CFLAGS) linearlyNestedParentheses_rec.o Lex.o -o linearlyNested_rec.x

Lex.o: Lex.cpp Lex.hpp Token.hpp
	g++ $(CFLAGS) -c Lex.cpp  -o Lex.o 

linearlyNestedParentheses_rec.o: linearlyNestedParentheses_rec.cpp Lex.hpp Token.hpp
	g++ $(CFLAGS) -c linearlyNestedParentheses_rec.cpp -o linearlyNestedParentheses_rec.o 

clean:
	rm -f *.o *.x *~
