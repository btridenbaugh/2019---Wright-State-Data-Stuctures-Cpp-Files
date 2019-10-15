//CIS 3100 - Data Structures and Algorithms
//Meilin Liu
//Benjamin Ridenbaugh
//ridenbaugh.2@wright.edu
//06/09/19
//Project #1
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Qqueue.h"
using namespace std;

int main(){	
	
	//Capacity
	cout << "How large would you like to make the capacity of the queue? (Note: Must be larger than 100)" << endl;
	int capacity;
	cin >> capacity;
	//Creates the DynamicQueue
	Qqueue queue(capacity);
	//This makes it so the whole queue isn't filled
	int cap = capacity - 5;
	
	
	//Name
	string name;
		
	//Queue size
	int Qsize = 0;
	
	//Dequeue size
	int Dsize = 0;
	
	//Menu choice
	int choice;
	
	//Front
	string front;
	string back;
	
	//Empty
	bool empty;
	
	//Equal
	bool equal;
	
	//Print
	/* Print = new string [capacity]; */
	
	
	//input text file and make a list of the names
	string input;
	ifstream txtFile;
	txtFile.open("all.last.txt");
	if (!txtFile) {
		cout << "The text file all.last.txt could not be found. Please try again." << endl;
        exit(0);
	}
	else{
		while (cap > 0){
			getline(txtFile, input);
			queue.enqueue(input);
			cap--;
		}
		int number = capacity - 5;
		cout << "The number of names added was " << number << " names, leaving space for 5 more names." << endl << endl;
		txtFile.close();
	}

	//Creates the initial queue copy for the equals function
	cout << "Creating a copy of the queue to compare to..." << endl;
	Qqueue queuecopy(queue);
	cout << "Queue copy has been made" << endl << endl;


	do {
	//Menu
	choice = 0;
	cout << "Menu" << endl;
	cout << "Please select one of the following options" << endl;
	cout << "1. Enqueue" << endl;
	cout << "2. Dequeue" << endl;
	cout << "3. Front" << endl;
	cout << "4. Equal" << endl;
	cout << "5. Print" << endl;
	cout << "6. Save" << endl;
	cout << "7. Quit" << endl;
	cin >> choice;
	
	switch (choice){
	//Enqueue
	case 1:
	{
		cout << "Please enter the last name you would like to add." << endl;
		//Name to be enqueued
		cin >> name;
		queue.enqueue(name);
		cout << endl;
	}
	break;
	
	
	//Dequeue
	case 2:
	{
		cout << "How many values would you like to dequeue?" << endl;
		cin >> Dsize;
		//Grabs size of queue
		Qsize = queue.size();
		//Gets boolean of if the queue is empty
		empty = queue.IsEmpty();
		if (empty == true){
			cout << "The are no elements in the queue to dequeue." << endl;
		}
		else{	
			if (Dsize >= Qsize){
				int difference = Dsize - Qsize;
				cout << "Size selected was greater than or equal to the whole queue size, deleting queue" << endl;
				while (Qsize>= difference){
					cout << "The name dequeued was " << queue.dequeue() << endl;
					Qsize--;
				}
			}
			else {
				while (Dsize > 0){
					cout << "The name dequeued was " << queue.dequeue() << endl;
					Dsize--;
				}
			}
		}
	}
	break;
	
	//Front
	case 3:
	{
		front = queue.getfront();
		cout << "The last name at the front of the queue is: " << front << endl ;
		cout << "Would you like to see the value at the end of the queue? Type 'y' for yes or 'n' for no." << endl;
		cin >> back;
		if (back == "y"){
			back = queue.getback();
			cout << "The last name at the back of the queue is: " << back << endl << endl;
		}
		else if (back == "n"){
			cout << "Returning to menu..." << endl << endl;
		}
		else {
			cout << "Please select valid option. Returning to the menu..." << endl << endl;
		}
	}
	break;

	
	//Equals
	case 4:
	{
		equal = queuecopy.equals(queue);
		if (equal == 1){
			cout << "The two queues are equal." << endl << endl;
		}
		else {
			cout << "The two queues are not equal." << endl << endl;
		}
	}
	break;
	
	//Print
	case 5:
	{
		cout << "The last names in the queue are:" << endl;
		queue.print();
		cout << endl;
	}
	break;
	
	//Save
	case 6:
	{
		cout << "Making a copy of the queue to Queue.copy.txt..." << endl;
		//Grabs size of queue
		Qsize = queue.size();
		ofstream saveFile;
		saveFile.open("Queue.copy.txt");
		string *save = &(queue.getfront());
		for (int i=0; i<Qsize; i++){
			saveFile << *save << endl;
			*save++;
		}
		saveFile.close();
		cout << "Queue has been saved." << endl << endl;
	}		
	break;
	
	//Quit
	case 7:
	{	
		cout << "You have chose to quit..." << endl;
		queue.~Qqueue();
		cout << "Exiting the program..." << endl;
		exit(0);
	}
	break;
	
	default:
	{
		cout << "You have entered and incorrect option. Please try again." << endl << endl;
	}
	break;
	}
}while (choice != 7);
}
	