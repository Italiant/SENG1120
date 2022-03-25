/*
File: Node.h
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Includes all the method headers for the template Node.cpp file
*/

#ifndef NodeP
#define NodeP

template <typename value_type>
class Node
{
public:

// Constructor
Node(const value_type& initial_data);

// Destructor
~Node();

// Getters
value_type get_data() const;
value_type& get_data();
const Node<value_type>* get_next() const;
Node<value_type>* get_next();
const Node<value_type>* get_previous() const;
Node<value_type>* get_previous();

// Setters
void set_data(const value_type& new_data);
void set_next(Node<value_type>* next_ptr);
void set_previous(Node<value_type>* previous_ptr);

// Private member variables
private:
	value_type data; // Contents of nodes  
	Node<value_type>* next; // Pointer to next node
	Node<value_type>* previous; // Pointer to previous node
};

#include "Node.hpp"

#endif