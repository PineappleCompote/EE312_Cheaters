final: main.o files.o HashMap.o LinkedList.o
	g++ -std=c++0x -o plagiarismCatcher main.o files.o HashMap.o LinkedList.o

main.o: main.cpp HashMap.h files.h
	g++ -std=c++0x -c main.cpp

files.o: files.cpp files.h HashMap.h
	g++ -std=c++0x -c files.cpp

HashMap.o: HashMap.cpp HashMap.h LinkedList.h
	g++ -std=c++0x -c HashMap.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -std=c++0x -c LinkedList.cpp

