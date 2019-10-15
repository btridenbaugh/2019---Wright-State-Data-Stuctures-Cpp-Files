//Employee.h provided by Dr. Meilin Liu, and you can modify it if you want. 
//CIS 3100 - Data Structures and Algorithms
//Meilin Liu
//Benjamin Ridenbaugh
//ridenbaugh.2@wright.edu
//07/21/19
//Project #3

#ifndef _Employee_
#define _Employee_

#include <cstdlib>
#include <iostream>
#include <string>

class Employee{

public:
	Employee();
	Employee(int IdNum, std::string last, std::string first);
	Employee(const Employee &person);
	~Employee();
	void setFirstName(std::string first);
	void setLastName(std::string last);
	void setID(int IdNum);
	int getID();
	std::string getFirstName();
	std::string getLastName();
	friend std::ostream& operator<<(std::ostream &outs, Employee &person);
	friend std::istream& operator>>(std::istream &ins, Employee &person);
private:
	int ID;
	std::string lastname;
	std::string firstname;

	
};


#endif