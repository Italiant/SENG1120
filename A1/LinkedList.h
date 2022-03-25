/*
File: LinkedList.h
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Includes all the method headers for the LinkedList.cpp file
*/

#ifndef LINKP
#define LINKP

#include "Node.h"
#include <cstdlib>

using namespace std;

class LinkedList
{
public:

	typedef Node::value_type value_type; // uses same value_type as node
	
	// Constructors
	LinkedList();
	LinkedList(value_type& data);
	
	// Destructor
	~LinkedList();
	
	// Getters
	value_type get_current();
	int size();
	
	// Setters
	void add_to_head(value_type& data);
	void addToTail(value_type& data);
	void remove_from_head();
	void remove_from_tail();
	void remove_from_current();
	
	void forward();
	void back();
	void move_to_head();
	void move_to_tail();
	void remove(string name);
	double calcAverage();
	int count(string name);
	void order();
	
// Private member variables
private:
	Node* head;
	Node* tail;
	Node* current;
	int list_length; // Records the length of the linked list
};

// Overloaded ostream operator
ostream& operator << (ostream& out, LinkedList& list);
// Overloaded += operator
LinkedList& operator += (LinkedList& a, LinkedList& b);

#endif