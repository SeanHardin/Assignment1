
#include <iostream>
using namespace std;
#include "Assignment1.h"//needed to run

contact::contact(){name=number="";};//default constructor

contact::contact(string a, string b){name=a;number=b;};//2 arg constructor

void contact::setName(string s){//to set the name on already initialized
	name=s;//entries to the array
}

string contact::getName(){return name;}//get the name

void contact::setNumber(string s){//set the number
	number=s;
}

string contact::getNumber(){return number;}//get number

void addEntry(contact *c, int& count){//add entry to the array, nonmember function
	cout << "Enter name of the person you want to add:";
	string input;
	getline(cin,input);//read in the name user adds
	if (input!=""){//any string with characters works
		c[count].setName(input);//sets the name as chosen
		cout<<"Enter their phone number:";
		getline(cin, input);//gets number from user
		if (input=="")//if no input
			goto D;//jump out of the code to give same error as no name
		c[count].number=input;//puts it in array
		cout << c[count].getName() << " has been added to the phonebook."<< '\n'<<'\n';
		count++;//increases the count variable for the new entry
	} else//if user didnt input a name
		D://label for goto command
		cout << "Please enter a real name and number if you want to add someone to the phonebook." << '\n'<<'\n';
}

void deleteEntry(contact *c, int &count){//deletes an entry
	cout << "Enter name of the person you want to remove:";
	string input;
	getline(cin, input);//read input
	bool deleted=0;//bool to check if deleted
	if (input != ""){
		for (int i=0;i<count;i++){//iterates whole array
			if (input==c[i].getName()){//if a match is found
				c[i].setName("");//'deletes' the name
				cout<<input<<" has been removed from the phonebook."<<'\n'<<'\n';
				deleted=true;//sends message saying it has been deleted
			}
		}
		if (!deleted)//if nothing was deleted, say so
			cout << "Nobody by that name was found."<<'\n'<<'\n';
	} else//if no name typed
		cout << "Please input a real name if you want to remove someone from the phonebook."<<'\n'<<'\n';
}

void listEntries(contact *c, int& count){//lists every contact
	for (int i=0;i<count;i++){//iterates whole array
		if (c[i].getName()!="") cout << c[i];//prints all contacts with a name
	}
	cout <<'\n';
}

void searchEntry(contact *c, int& count){//searches for entry matching user input
	cout << "Enter the name of the person you want to call:";
	string input;//to take in the full name
	bool found=0;//bool used to tell if operation was successful or not
	getline(cin, input);//take whole line into string
	if (input!=""){
		for (int i=0;i<count;i++){//iterates the whole array
			if (c[i].getName()==input){//when the search name matches any name in the array
				cout << input << "'s phone number is " << c[i].number<<'\n'<<'\n';//gives the phone number
				found=1;//changes bool to true once it found a match
			}
		}
		if (!found)//if bool is never changed
			cout << "Nobody by that name was found."<<'\n'<<'\n';
	} else//if no name typed
		cout << "Please enter a real name if you want to find someone in the phonebook." << '\n'<<'\n';
}

ostream& operator<<(ostream& os, const contact& c){//borrowed from lecture to modify
	os<<c.name<<' '<<c.number<<'\n';//reads a contact by its information
	return os;
}


