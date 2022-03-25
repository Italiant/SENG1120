/*
File: Node.cpp
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Provides all methods for working with nodes such as setting and getting the previous, next or durrent data of a node
*/

#include "Node.h"
#include <iostream>

using namespace std;

//Constructor
// Precondition: Data of type value type has been defined and provided 
// Postcondition: A new node is created and initialised with the initial data predefined by value type
Node::Node(const value_type& initial_data)
{
	data = initial_data;
	next = NULL;
	previous = NULL;
}

// Empty destructor
Node::~Node(){}

// Accessor methods
// Precondition: None
// Postcondition: Returns the data currently stored in a node
Node::value_type Node::get_data() const
{
	return data;
}

// Precondition: None
// Postcondition: Returns the next node with the condition that it will not be changed
const Node* Node::get_next() const
{
	return next;
}

// Precondition: None 
// Postcondition: Returns the next node
Node* Node::get_next()
{
	return next;
}

// Precondition: None
// Postcondition: Returns the previous node with the condition that it will not be changed
const Node* Node::get_previous() const
{
	return previous;
}

// Precondition: None 
// Postcondition: Returns the previous node
Node* Node::get_previous()
{
	return previous;
}

// Mutator methods 
// Precondition: Data of type value type has been defined and provided 
// Postcondition: Initilises data
void Node::set_data(const value_type& new_data)
{
	data = new_data;
}

// Precondition: The next node pointer is provided  
// Postcondition: Initilises the next node  
void Node::set_next(Node* next_ptr)
{
	next = next_ptr;
}

// Precondition: The previous node pointer is provided  
// Postcondition: Initilises the previous node  
void Node::set_previous(Node* previous_ptr)
{
	previous = previous_ptr;
}