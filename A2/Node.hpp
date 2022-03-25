/*
File: Node.hpp
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Provides all methods for working with template nodes such as setting and getting the previous, next or durrent data of a node
*/

#include <iostream>
#include <cstdlib>

using namespace std;

// Constructor
// Precondition: Data of type value type has been defined and provided 
// Postcondition: A new node is created and initialised with the initial data predefined by value type
template <typename value_type>
Node<value_type>::Node(const value_type& initial_data)
{
	data = initial_data;
	next = NULL;
	previous = NULL;
}

// Destructor
template <typename value_type>
Node<value_type>::~Node()
{
	delete next;
	delete previous;
}

// Accessor methods
// Precondition: None
// Postcondition: Returns the data currently stored in a node
template <typename value_type>
value_type Node<value_type>::get_data() const
{
	return data;
}

// Precondition: None
// Postcondition: Returns the data currently stored in a node in the form of a reference variable
template <typename value_type>
value_type& Node<value_type>::get_data()
{
	return data;
}

// Precondition: None
// Postcondition: Returns the next node with the condition that it will not be changed
template <typename value_type>
const Node<value_type>* Node<value_type>::get_next() const
{
	return next;
}

// Precondition: None 
// Postcondition: Returns the next node
template <typename value_type>
Node<value_type>* Node<value_type>::get_next()
{
	return next;
}

// Precondition: None
// Postcondition: Returns the previous node with the condition that it will not be changed
template <typename value_type>
const Node<value_type>* Node<value_type>::get_previous() const
{
	return previous;
}

// Precondition: None 
// Postcondition: Returns the previous node
template <typename value_type>
Node<value_type>* Node<value_type>::get_previous()
{
	return previous;
}

// Mutator methods 
// Precondition: Data of type value type has been defined and provided 
// Postcondition: Initilises data
template <typename value_type>
void Node<value_type>::set_data(const value_type& new_data)
{
	data = new_data;
}

// Precondition: The next node pointer is provided  
// Postcondition: Initilises the next node  
template <typename value_type>
void Node<value_type>::set_next(Node<value_type>* next_ptr)
{
	next = next_ptr;
}

// Precondition: The previous node pointer is provided  
// Postcondition: Initilises the previous node  
template <typename value_type>
void Node<value_type>::set_previous(Node<value_type>* previous_ptr)
{
	previous = previous_ptr;
}