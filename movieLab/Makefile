CFLAGS = -g -std=c++11 -Wall

Movies.x: Movies.o
	g++ $(CFLAGS) Movies.o -o Movies.x
Movies.o: Movies.cpp
	g++ $(CFLAGS) -c Movies.cpp -o Movies.o
clean:
	rm -rf *.o *.x 
run: Movies.x
	./Movies.x
