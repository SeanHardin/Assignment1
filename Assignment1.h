/*
 * Assignment1.h
 *
 *  Created on: Oct 2, 2017
 *      Author: Sean
 */

#ifndef ASSIGNMENT1_H_
#define ASSIGNMENT1_H_
#include <iostream>//needed to use namespace std in file other than main
using namespace std;//to use the includes used in main file

class contact {
	string name, number;
public:
	contact();//default constructor
	contact(const string, const string);//2 arg constructor
	void setName(const string&);//prototypes, descriptions in cpp file.
	string getName();
	void setNumber(const string&);
	string getNumber();
	friend void addEntry(contact *c, int&);
	friend void deleteEntry(contact *c, const int&);
	friend void listEntries(contact *c, const int&);
	friend void searchEntry(contact *c, const int&);
	friend ostream& operator<<(ostream&, const contact&);
};

#endif /* ASSIGNMENT1_H_ */
