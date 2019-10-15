//CIS 3100 - Data Structures and Algorithms
//Meilin Liu
//Benjamin Ridenbaugh
//ridenbaugh.2@wright.edu
//06/09/19
//Project #1
#include <iostream>
#include <cstdlib>
#include <string>
#include "Qqueue.h"
using namespace std;

// Constructor
Qqueue::Qqueue( int cap){
	cout << "Calling Constructor..." << endl;
	num = 0;
	Capacity = cap;
	DynamicQueue = new string [Capacity];
	
}

//Copy Constructor
Qqueue::Qqueue( const Qqueue& s ){
	cout << "Calling Copy Constructor..." << endl;
	DynamicQueue = new string [num];
	string *queue = &(s.getfront());
	
 	for (int i=0; i < num; i++){
		
		DynamicQueue[i] = *(queue + i);
		
	} 
	
	cout << "Copy of the queue has been made." << endl;
}

//Destructor is in the Quit

//Get Size
int Qqueue::size() const{
	return num;
}

//Get Capacity
int Qqueue::getCapacity() const{
	return Capacity;
}

//1. Enqueue
void Qqueue::enqueue ( const string&  s ){
	
	
	if (Capacity == num){
		cout << "The queue is at capacity. Try dequeueing first before enqueueing." << endl << endl;
	}
	else {
		cout << "Enqueueing..." << endl;
		DynamicQueue[ num ] = s;
		num++;
		if (num >= 5){
			int i = 0;
			while ( i <= 4 ){
				cout << "The name in position " << i+1 << " of the queue is " << DynamicQueue[ i ] << endl;
				i++;
			}
			cout << "The queue is now " << num << " name(s) long." << endl;
			cout << endl;
		}
		else{
		cout << "The queue is now " << num << " name(s) long." << endl;
		}
		
	}
	
}

//2. Dequeue
string Qqueue::dequeue (){
	string Dname = DynamicQueue[0];
	for(int i = 0; i < num ; i++){
		
		DynamicQueue[i] = DynamicQueue[i+1];
		
	}
	num --;
	return Dname;
}

//3. Front
string& Qqueue::getfront () const{

	return DynamicQueue[0];

}

//Back
string& Qqueue::getback () const{
	
	return DynamicQueue[num - 1];
	
}

//Empty
bool Qqueue::IsEmpty () const{
	bool empty;
	if (num == 0){
		empty = true;
	}
	else {
		empty = false;
	}
	return empty;
}

//4. Equal
bool Qqueue::equals(const Qqueue& q) const{
	bool equal;
	string *value = &(q.getfront());
	for (int i=0; i<num; i++){
		
		string a = *(DynamicQueue + i);
		string b = *(value + i);
		if (a != b){
			equal = false;
			return equal;
		}
	}
	equal = true;
	return equal; 	
}

//5. Print
void Qqueue::print() const{
	int i = 0;
	while ( i < num ){
		cout << DynamicQueue[i] << endl;
		i++;
	}
	/* return *DynamicQueue; */
}


//7. Quit/Destructor
Qqueue::~Qqueue( ){
	cout << "Calling Destructor..." << endl;
	delete [] DynamicQueue;
	cout << "The queue has been deleted." << endl;
}