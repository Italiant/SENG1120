/*
File: Node.h
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Includes all the method headers for the Node.cpp file
*/

#ifndef NodeP
#define NodeP

#include "Student.h"
#include <cstdlib>

using namespace std;

class Node
{
public:

typedef Student value_type;

// Constructor
Node(const value_type& initial_data);

// Destructor
~Node();

// Getters
value_type get_data() const;
const Node* get_next() const;
Node* get_next();
const Node* get_previous() const;
Node* get_previous();

// Setters
void set_data(const value_type& new_data);
void set_next(Node* next_ptr);
void set_previous(Node* previous_ptr);

// Private member variables
private:
	value_type data; // Contents of nodes  
	Node* next; // Pointer to next node
	Node* previous; // Pointer to previous node
};
#endif