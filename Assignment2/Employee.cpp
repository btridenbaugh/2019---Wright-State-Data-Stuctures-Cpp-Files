//CIS 3100 - Data Structures and Algorithms
//Meilin Liu
//Benjamin Ridenbaugh
//ridenbaugh.2@wright.edu
//07/09/19
//Project #2
#include <cstdlib>
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

	Employee::Employee(){

	}
	
	Employee::Employee(int IdNum, string last, string first){
		lastname = last;
		firstname = first;
		ID = IdNum;
		
	}
	
	Employee::Employee(const Employee &person){
		lastname = person.lastname;
		firstname = person.firstname;
		ID = person.ID;
	}
	
	Employee::~Employee(){
		
	}
	
	void Employee::setFirstName(string first){
		firstname = first;
	}
	
	void Employee::setLastName(string last){
		lastname = last;
	}
	
	void Employee::setID(int IdNum){
		ID = IdNum;
	}
	
	int Employee::getID(){
		return ID;
	}
	
	string Employee::getFirstName(){
		return firstname;
	}
	
	string Employee::getLastName(){
		return lastname;
	}
	
	ostream& operator<<(ostream &outs, Employee &person){
		outs << person.lastname;
		outs << " ";
		outs << person.firstname;
		outs << " ";
		outs << person.ID;
		outs << endl;
		return outs;
	}
	
	istream& operator>>(istream &ins, Employee &person){
		return ins;
	}

