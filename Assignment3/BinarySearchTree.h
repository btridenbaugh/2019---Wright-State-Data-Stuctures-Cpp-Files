//Employee.h provided by Dr. Meilin Liu, and you can modify it if //you want.
//CIS 3100 - Data Structures and Algorithms
//Meilin Liu
//Benjamin Ridenbaugh
//ridenbaugh.2@wright.edu
//07/21/19
//Project #3

#ifndef _BinarySearchTree_
#define _BinarySearchTree_

#include <cstdlib>
#include "BinaryTreeNode.h"
#include "Employee.h"

using namespace std;

class BinarySearchTree {
	public:
		BinarySearchTree();	//constructor
		~BinarySearchTree();	//destructor
		bool clear(BinaryTreeNode * node);
		bool insert(Employee & emp);
		BinaryTreeNode* search(int k);
		bool remove(int k);
		int BSTsize();
		bool save();
		void filesave(ostream & save, BinaryTreeNode * node);
	private:
		BinaryTreeNode * root;
		int size;
};


#endif
 
