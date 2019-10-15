//CIS 3100 - Data Structures and Algorithms
//Meilin Liu
//Benjamin Ridenbaugh
//ridenbaugh.2@wright.edu
//07/09/19
//Project #2
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "SSLStack.h"
#include "Lnode.h"
#include "Employee.h"
using namespace std;

SSLStack::SSLStack(){
// Initialize a new stack so that it is empty. 
	head=NULL;
	num = 0;
}

SSLStack::SSLStack (const SSLStack &s){
// The copy constructor (performs initialization).
	Lnode* copy = s.head;
	head = NULL;
	num = 0;
	while (copy != NULL){
		push(copy->NewEmployee);
		copy = copy->next;
	}
}

SSLStack::~SSLStack (){
// Perform actions needed when stack goes out of scope.
	Lnode* oldnode;
	while (head != NULL){
		oldnode = head;
		head = head->next;
		delete(oldnode);
	}
}

bool SSLStack::push (const Employee &new_item){
// Place a new item on top of the stack. 
	Lnode* newnode = new Lnode(new_item);
	newnode->next = head;
	head = newnode;
	num++;
	return true;
}

bool SSLStack::pop (Employee &item){
// Remove and return the top stack item. Check if stack is empty.
	Lnode* oldhead = head;
	if (head == NULL) {
		cout << "There are no Employees to delete" << endl;
		return false;
	}
	item = head->NewEmployee;
	head = head->next;
	delete(oldhead);
	num--;
	return true;
}

bool SSLStack::top (Employee &item) const{
// Return top stack item without removing it. 
	item = head->NewEmployee;
	return true;
}


// = Check boundary conditions for Stack operations.
bool SSLStack::is_empty() const{
// Returns true if the stack is empty, otherwise returns false.
	if(num == 0){
		return true;
	}
	else{
		return false;
	}
}

int SSLStack::size() const{
// Returns the number of elements in the stack.
	return num;
}

void SSLStack::print() const{
//Print all the elements in the stack onto the screen. 
   Lnode* ptr;
   if(num==0){
		cout<<"The stack is empty."<< endl;
   }
   else {   
		ptr = head; 
		cout<<"Stack elements are: " << endl;
			while (ptr != NULL) { 
				cout<< ptr->NewEmployee; 
				ptr = ptr->next; 
			}
    }
	cout << endl;
}

void SSLStack::save() const{
//Saves all items in stack to a text file.
	if (num ==0) {
		cout << "There are no items in the stack to save." << endl << endl;
	}
	else{
		ofstream saveFile;
		saveFile.open("Stack.copy.txt");
		Lnode* save = head;
		for (int i=0; i<num; i++){
			saveFile << save->NewEmployee << endl;
			save = save->next;
		}
		saveFile.close();
		cout << "The items in the stack have been saved to the text file Stack.copy.txt." << endl << endl;
	}
}

void SSLStack::firstfive() const{
//Prints the first five employees in the stack.
	Lnode* five = head;
	for (int i=6; i>0; i--){
		cout << five->NewEmployee;
		five = five->next;
	}
}

bool SSLStack::operator == (const SSLStack &s) const{
// Checks for Stack equality.
	Lnode* sh = s.head;
	Lnode* h = head;
	Employee test, stest;
	while (sh != NULL && h != NULL){
		test = h -> NewEmployee;
		stest = sh -> NewEmployee;
		if (test.getLastName() != stest.getLastName() && test.getFirstName() != stest.getFirstName() && test.getID() != stest.getID()){
			cout << "The two stacks are NOT equal to each other." << endl << endl;
			return false;
		}
		sh = sh -> next;
		h = h -> next;
	}
	cout << "The two stacks are equal to each other." << endl << endl;
	return true;
}
