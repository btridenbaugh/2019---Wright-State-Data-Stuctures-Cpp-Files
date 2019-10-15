all: main

main: main.o Employee.o BinarySearchTree.o
	g++ main.cpp BinarySearchTree.cpp Employee.cpp -o main	

main.o: main.cpp Employee.h BinarySearchTree.h BinarySearchTree.cpp BinaryTreeNode.h
	g++ -c main.cpp

Employee.o: Employee.cpp Employee.h
	g++ -c Employee.cpp

BinarySearchTree.o: BinarySearchTree.cpp Employee.h BinarySearchTree.h BinaryTreeNode.h
	g++ -c BinarySearchTree.cpp

clean:
	rm -rf *o main