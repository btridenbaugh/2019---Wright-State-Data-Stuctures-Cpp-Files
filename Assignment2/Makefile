all: main

main: main.o Employee.o SSLStack.o
	g++ main.cpp SSLStack.cpp Employee.cpp -o main	

main.o: SSLStack.cpp Employee.h SSLStack.h Lnode.h
	g++ -c main.cpp

Employee.o: Employee.h Employee.cpp
	g++ -c Employee.cpp

SSLStack.o: SSLStack.cpp Employee.h SSLStack.h Lnode.h
	g++ -c SSLStack.cpp

clean:
	rm -rf *o main