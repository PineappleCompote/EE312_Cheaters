final: main.o
	g++ -std=c++11 -o test main.o
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
