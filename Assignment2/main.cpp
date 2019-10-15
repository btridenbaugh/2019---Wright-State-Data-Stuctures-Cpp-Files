//CIS 3100 - Data Structures and Algorithms
//Meilin Liu
//Benjamin Ridenbaugh
//ridenbaugh.2@wright.edu
//07/09/19
//Project #2
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Employee.h"
#include "SSLStack.h"
#include "Lnode.h"
using namespace std;

int main(){	
	
	//Creates SSLStack object
	SSLStack stack;

	//Push
	string lastname;
	string firstname;
	int id;

	//Stack size
	int Ssize = 0;
	
	//Pop size
	int Psize = 0;
	
	//Menu choice
	int choice;
	
	//Empty
	bool empty;
	
	// Input the small database
	ifstream database;
	database.open("Small-Database.txt");
 	if (database.is_open()) {
		while (database >> lastname >> firstname >> id){
			Employee newEmployee(id, lastname, firstname);
			stack.push(newEmployee);
		}
		database.close();
		cout << "The database file has been loaded." << endl << endl;
	} 
	else {
		cout << "The database file could not be found. Please try again." << endl;
		exit(0);
	}

	cout << "Calling the copy constructor to create a stack copy..." << endl;
	SSLStack reverse = stack;
	//This needs to be done because the first time youy use the copy constructor the stack it creates is reversed
	SSLStack copy = reverse;
	reverse.~SSLStack();
	cout << "Copy of the stack has been made." << endl << endl;
	

	do {
	//Menu
	choice = 0;
	cout << "Menu" << endl;
	cout << "Please select one of the following options" << endl;
	cout << "1. Push" << endl;
	cout << "2. Pop" << endl;
	cout << "3. Top" << endl;
	cout << "4. Print" << endl;
	cout << "5. Save" << endl;
	cout << "6. Equals" << endl;
	cout << "7. Quit" << endl;
	cin >> choice;
	
	switch (choice){
	//Push
	case 1:
	{
		cout << "Please enter the following information for the employee you would like to add." << endl;
		//Employee's information to be pushed
		cout << "Employee's last name:";
		cin >> lastname;
		cout << "Employee's first name:";
		cin >> firstname;
		cout << "Employee's ID number:";
		cin >> id;	
		Employee newEmployee(id, lastname, firstname);
		stack.push(newEmployee);
		cout << "Employee has been added" << endl << endl;
		Ssize = stack.size();
		if (Ssize >= 5){
			cout << "Printing first 5 employees in the stack..." << endl;
			stack.firstfive();
			cout << endl << endl;
		}
	}
	break;
	
	
	//Pop
	case 2:
	{
		cout << "How many Employees would you like to pop?" << endl;
		cin >> Psize;
		//Grabs size of queue
		Ssize = stack.size();
		//Gets boolean of if the queue is empty
		empty = stack.is_empty();
		if (empty == true){
			cout << "The are no elements in the queue to dequeue." << endl;
		}
		else{	
			if (Psize >= Ssize){
				cout << "Size selected was greater than or equal to the whole stack size, popping the whole stack..." << endl;
				while (Ssize >= 0){
					Employee deleted;
					stack.pop(deleted);
					cout << "The employee popped was: " << deleted;
					Ssize--;
				}
			}
			else {
				while (Psize > 0){
					Employee deleted;
					stack.pop(deleted);
					cout << "The employee popped was: " << deleted;
					Psize--;
				}
			}
		}
		Ssize = stack.size();
		cout << "The number of the employees in the stack is now " << Ssize << endl << endl;
	}
	break;
	
	
	//Top
	case 3:
	{
		Ssize = stack.size();
		if (Ssize == 0){
			cout << "The stack is empty" << endl << endl;
		}
		else{		
		Employee top;
		stack.top(top);
		cout << "The employee at the top of the stack is: " << top ;
		cout << "Total number of employees in the stack is: "<< Ssize << endl << endl;
		}
	}
	break;

	
	//Print
	case 4:
	{
		cout << "Printing the stack..." << endl;
		stack.print();
	}
	break;
	
	
	//Save
	case 5:
	{
		cout << "Saving the stack to a text file..." << endl;
		stack.save();
	}
	break;
	
	
	//Equals
	//NOTE: This compares to the stack copy that was originally made at the beginning of the program. So if any changes
	//were made prior to calling this option they will not be equal
	case 6:
	{
		cout << "Testing to see if the current stack is equal to the copy made before..." << endl;
		copy == stack;
		
	}
	break;
	
	
	//Quit
	case 7:
	{
		cout << "You have chose to quit..." << endl;
			cout << "Clearing both of the stacks..." << endl;
		stack.~SSLStack();
		copy.~SSLStack();
		cout << "Stacks dumped." << endl;
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
	