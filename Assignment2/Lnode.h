 //The Singly Linked List node header file Lnode.h provided by Dr. Meilin Liu, and you can modify it if you want. 


#ifndef _Lnode_
#define  _Lnode_

#include <cstdlib>
#include <string>
#include "Employee.h"

class Lnode
{
	public:
		Employee NewEmployee;
		Lnode *next;
		Lnode(Employee NewPerson) {NewEmployee = NewPerson; next = NULL;}
};


#endif