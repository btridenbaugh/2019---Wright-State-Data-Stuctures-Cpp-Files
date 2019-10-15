//The Singly Linked List based Stack header file, SSLStack.h, provided by Dr. Meilin Liu, and you can you can modify it if you want. 

#ifndef _SLLStack_
#define _SLLStack_
#include "Lnode.h"
#include "Employee.h"
using namespace std;
class SSLStack

// This implementation of a Singly Linked List based Stack.
{
public:

SSLStack();
// Initialize a new stack so that it is empty. 
SSLStack (const SSLStack &s);
// The copy constructor (performs initialization).

~SSLStack ();
// Perform actions needed when stack goes out of scope.

bool push (const Employee &new_item);
// Place a new item on top of the stack. 
bool pop (Employee &item); 
// Remove and return the top stack item. Check if stack is empty.
bool top (Employee &item) const;
// Return top stack item without removing it. 

// = Check boundary conditions for Stack operations.
bool is_empty() const;
// Returns true if the stack is empty, otherwise returns false.

int size() const;
// Returns the number of elements in the stack.

void print() const;
//Print all the elements in the stack onto the screen. 

void save() const;
//Saves all items in the stack to a text file.

void firstfive() const;
//Prints the first five names in the stack.

bool operator == (const SSLStack &s) const;
// Checks for Stack equality.

private:
Lnode* head;
// The top of the Linked List based Stack.

int num; 
//the number of elements in the stack.

};

#endif