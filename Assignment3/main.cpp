//CIS 3100 - Data Structures and Algorithms
//Meilin Liu
//Benjamin Ridenbaugh
//ridenbaugh.2@wright.edu
//07/21/19
//Project #3

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Employee.h"
#include "BinarySearchTree.h"
#include "BinaryTreeNode.h"
using namespace std;

int main(){	
	
	//Creates BinaryTree object
	BinarySearchTree tree;

	//Insert
	string lastname;
	string firstname;
	int id;

	//Tree size
	int Tsize = 0;
	
	//Pop size
	int Psize = 0;
	
	//Menu choice
	int choice;
	
	//Search
	Employee *search;
	
	//Empty
	bool empty;
	
	// Input the small database
	ifstream database;
	database.open("Small-Database.txt");
 	if (database.is_open()) {
		while (database >> lastname >> firstname >> id){
			Employee newEmployee(id, lastname, firstname);
			tree.insert(newEmployee);
		}
		database.close();
		cout << "The database file has been loaded." << endl << endl;
	} 
	else {
		cout << "The database file could not be found. Please try again." << endl;
		exit(0);
	}

	do {
	//Menu
	choice = 0;
	cout << "Menu" << endl;
	cout << "Please select one of the following options" << endl;
	cout << "1. Insert New Record" << endl;
	cout << "2. Delete Record" << endl;
	cout << "3. Employee ID Search" << endl;
	cout << "4. Save BinarySearchTree to a file" << endl;
	cout << "5. Quit" << endl;

	cin >> choice;
	
	switch (choice){
	//Insert
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
		tree.insert(newEmployee);
		cout << "Employee has been added." << endl << endl;
	}
	break;
	
	
	//Delete
	case 2:
	{
		cout << "What is the ID of the employee you want to delete: ";
		cin >> id;
		cout << endl << "Searching for the employee to delete..." << endl;
		tree.remove(id);
		cout << endl;
	}
	break;
	
	
	//Search
	case 3:
	{
		cout << "What is the ID of the employee you want to find: ";
		cin >> id;
		cout  << "Searching for the employee..." << endl;
		tree.search(id);
		cout << endl;
	}
	break;
	
	
	//Save
	case 4:
	{
		cout << "Saving the BinarySearchTree to a text file..." << endl;
		tree.save();
	}
	break;
	
	
	//Quit
	case 5:
	{
		cout << "You have chose to quit..." << endl;
		cout << "Clearing the BinarySearchTree..." << endl;
		tree.~BinarySearchTree();
		cout << "BinaryTree dumped." << endl;
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
}while (choice != 5);
}
	