# this target will compile all of the file
all: queue

queue: main.o Qqueue.o
	g++ main.o Qqueue.o -o queue
main.o: main.cpp
	g++ -c main.cpp
Qqueue.o: Qqueue.cpp
	g++ -c Qqueue.cpp
clean:
	rm -rf *o queue