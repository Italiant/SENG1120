/*
File: LinkedList.h
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Includes all the method headers for the template LinkedList.hpp file
*/

#ifndef LINKP
#define LINKP

#include "Node.h"

template <typename value_type>
class LinkedList
{
public:
	
	// Constructors
	LinkedList();
	LinkedList(value_type& data);
	
	// Destructor
	~LinkedList();
	
	// Getters
	value_type get_current() const;
	value_type get_head() const;
	value_type get_tail() const;
	int size();
	
	// Setters
	void add_to_head(value_type& data);
	void addToTail(value_type& data);
	value_type& remove_from_head();
	value_type& remove_from_tail();
	value_type& remove_from_current();
	
	void forward();
	void back();
	void move_to_head();
	void move_to_tail();
	void order();
	
// Private member variables
private:
	Node<value_type>* head;
	Node<value_type>* tail;
	Node<value_type>* current;
	int list_length; // Records the length of the linked list
};

// Overloaded ostream operator
template <typename value_type> // required becasue the 
ostream& operator << (ostream& out, LinkedList<value_type>& list);

#include "LinkedList.hpp"

#endif