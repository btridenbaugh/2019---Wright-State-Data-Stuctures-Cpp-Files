//CIS 3100 - Data Structures and Algorithms
//Meilin Liu
//Benjamin Ridenbaugh
//ridenbaugh.2@wright.edu
//07/21/19
//Project #3

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "BinarySearchTree.h"
#include "BinaryTreeNode.h"
#include "Employee.h"
using namespace std;

BinarySearchTree::BinarySearchTree(){
	//constructor
	size=0;
	root = NULL;
}

BinarySearchTree::~BinarySearchTree(){
	//destructor
	clear(root);
}

bool BinarySearchTree::clear(BinaryTreeNode * node){
	if(node->left != NULL){
		clear(node->left);
	}
	if(node->right != NULL){
		clear(node->right);
	}
	delete node;
}

bool BinarySearchTree::insert(Employee & emp){
	BinaryTreeNode *e = new BinaryTreeNode(emp);
	if (root == NULL){
		//Insert first node
		root = e;
		cout << "Inserting Root: " << e->person << endl;
		size++;
		return true;
	}
	BinaryTreeNode *tempptr = root;
	Employee temp = root->person;
	while(true){
		//Insert Right
		if (temp.getID() < emp.getID()){	
			if(tempptr->right == NULL){
				e->parent = tempptr;
				tempptr->right = e;
				cout << "Inserting Right: " << e->person << endl;
				size++;
				return true;
			}
			else{
				tempptr = tempptr->right;
				temp = tempptr->person;
			}
		}
		//Insert Left
		else if (temp.getID() > emp.getID()){
			if(tempptr->left == NULL){
				e->parent = tempptr;
				tempptr->left = e;
				cout << "Inserting Left: " << e->person << endl;
				size++;
				return true;
			}
			else{
				tempptr = tempptr->left;
				temp = tempptr->person;
			}
		}
		else {
			cout << "This employee ID is already being used." << endl;
		}
	}	
}

//NOTE:: I changed the return data type to a BinaryTreeNode that way it can be used in the remove function
BinaryTreeNode* BinarySearchTree::search(int k){
	BinaryTreeNode *tempptr = root;
	Employee temp = root->person;
	if (size == 0) {
		cout << "There are no employees in the BinarySearchTree." << endl << endl;
	}
	else {
		while(true){
			// Employee found return the treenode pointer
			if (temp.getID() == k){
				cout << "The employee " << temp << "was found after searching through " << size << " employees." << endl;
				return tempptr;
			}
			//RIGHT
			else if (temp.getID() < k){
				//Cannot be found
				if (tempptr->right == NULL){
					cout << "That employee ID does not exsist." << endl;
					tempptr = NULL;
					return tempptr;
				}
				else{
					tempptr = tempptr->right;
					temp = tempptr->person;
				}
			}
			//LEFT
			else if (temp.getID() > k){
				//Cannot be found
				if (tempptr->left == NULL){
					cout << "That employee ID does not exsist." << endl;
					tempptr=NULL;
					return tempptr;
				}
				else{
					tempptr = tempptr->left;
					temp = tempptr->person;
					
				}
			}
			
		}
	}

}

bool BinarySearchTree::remove(int k){
	//Gets the pointer to the searched node from the int k
	BinaryTreeNode *treeptr = NULL;
	treeptr = search(k);
	BinaryTreeNode *tparent = NULL; 
	tparent = treeptr->parent;
	//This may be redundant but makes sure there is a tree
	if (root == NULL){
		cout << "There are no employees to delete. " << endl << endl;
		return false;
	}
	
	//Employee ID not found
	else if (treeptr == NULL){
		cout << "NOTE: Delete cannot be done since the employee ID doesn't exsist." << endl;
		return false;
	}
	
	//No children, removes node
	else if(treeptr->left == NULL && treeptr->right == NULL) { 
		cout << "Deleting w/ no children" << endl << treeptr->person << "---DELETED---" << endl;
		if(tparent->right == treeptr){
			tparent->right = NULL;
			size--;
			delete treeptr;
			return true;
		}
		else if (tparent->left == treeptr) {
			tparent->left = NULL;
			size--;
			delete treeptr;
			return true;
		}
	}
	
	 //One child on right, replaces node with right 
	else if(treeptr->left == NULL) {
		cout << "Deleting w/ one child on right" << endl << treeptr->person << "---DELETED--- " << endl;
		BinaryTreeNode *temp = treeptr->right;
		if(tparent->right == treeptr){
			tparent->right = treeptr->right;
			temp->parent = tparent;
			size--;
			delete treeptr;
			return true;
		}
		else if (tparent->left == treeptr) {
			tparent->left = treeptr->right;
			temp->parent = tparent;
			size--;
			delete treeptr;
			return true;
		}
	}
	
	//One child on left, replaces node with left
	else if(treeptr->right == NULL) {
		cout << "Deleting w/ one child on left" << endl << treeptr->person << "---DELETED---" << endl;
			BinaryTreeNode *temp = treeptr->right;
		if(tparent->right == treeptr){
			tparent->right = treeptr->left;
			temp->parent = tparent;
			size--;
			delete treeptr;
			return true;
		}
		else if (tparent->left == treeptr) {
			tparent->left = treeptr->left;
			temp->parent = tparent;
			size--;
			delete treeptr;
			return true;
		}
	}
	
 	// 2 children, replaces with least node from the right child/tree
	else { 
		BinaryTreeNode *temp;
		temp = treeptr->right;
		BinaryTreeNode *leftchild;
		leftchild = treeptr->left;
		while (true){
			if(temp->left !=NULL){
				temp = temp->left;
			}
			else if (temp->left == NULL){
				if(temp->right != NULL && temp->parent != treeptr){
					temp->parent->left = temp->right;
				}
				else if (temp->right == NULL && temp->parent->right != NULL){
					temp->parent->left = NULL;
				}
				else if (temp->right == NULL && temp->left == NULL){
					temp->parent->right == NULL;
				}
				else if (temp->right != NULL && temp->parent == treeptr){
					temp->parent->right = temp->right;
				}
				else{
					return false;
				}
				cout << "Deleting w/ two children" << endl << treeptr->person << "---DELETED---" << endl;
				if(tparent->right == treeptr){
					tparent->right = temp;
					temp->parent = tparent;
					temp->left = treeptr->left;
					leftchild->parent = temp;
					size--;
					delete treeptr;
					return true;
				}
				else if (tparent->left == treeptr) {
					tparent->left = temp;
					temp->parent = tparent;
					temp->left = treeptr->left;
					leftchild->parent = temp;
					size--;
					delete treeptr;
					return true;
				}
			
			}
		}
	}	 
}

int BinarySearchTree::BSTsize(){
	return size;
}

bool BinarySearchTree::save(){
	if (size ==0) {
		cout << "There are no items in the stack to save." << endl << endl;
	}
	else{
		ofstream saveFile;
		saveFile.open("Tree.copy.txt");
		filesave(saveFile,root);
		saveFile.close();
		cout << "The " << size << " employees in the BinarySearchTree have been saved to the text file Tree.copy.txt." << endl << endl;
	}
}

void BinarySearchTree::filesave(ostream & save, BinaryTreeNode * node){
	//This will print all the items in the tree INORDER into a text file
	if(node->left != NULL){
		filesave(save,node->left);
	}
	save << node->person;
	if (node->right != NULL){
		filesave(save,node->right);
	}
}