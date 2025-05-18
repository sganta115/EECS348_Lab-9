all:
	g++ -std=c++17 -c main.cpp
	g++ -std=c++17 -c matrix.cpp
	g++ -std=c++17 -o matrix_app main.o matrix.o


clean:
	rm -f *.o matrix_app