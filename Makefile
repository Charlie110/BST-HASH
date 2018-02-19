all: main

main: main.cpp BST.cpp Hash.cpp
	g++ -std=c++11 -o main main.cpp BST.cpp Hash.cpp
clean: 
	rm -f main
