////Employee.h provided by Dr. Meilin Liu, and you can modify it if you want.
//CIS 3100 - Data Structures and Algorithms
//Meilin Liu
//Benjamin Ridenbaugh
//ridenbaugh.2@wright.edu
//07/21/19
//Project #3

#ifndef _BinaryTreeNode_
#define _BinaryTreeNode_
#include <iostream>
#include <cstdlib>
#include "Employee.h"

using namespace std;

class BinaryTreeNode{
public:
	Employee person;
	BinaryTreeNode * parent;
	BinaryTreeNode * left;
	BinaryTreeNode * right;
	
	BinaryTreeNode(){};
	
	BinaryTreeNode(Employee &newEmployee, BinaryTreeNode *parentptr = NULL, BinaryTreeNode *rightptr = NULL, BinaryTreeNode *leftptr = NULL){
		person = newEmployee;
		parent = parentptr;
		left = leftptr;
		right = rightptr;
	};

	~BinaryTreeNode(){
		parent = NULL;
		left = NULL;
		right = NULL;
		delete parent, left, right;
	};
};
#endif
