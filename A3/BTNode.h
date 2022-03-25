/*
File: BTNode.h
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Includes all the method headers for the template BTNode.hpp file to work with binary search trees
*/

#ifndef BTNodeP
#define BTNodeP

#include <iostream>
#include <cstdlib>

template <typename value_type>
class BTNode
{
public:

// Constructor
BTNode(const value_type& initial_data);

// Destructor
~BTNode();

// Getters
value_type get_data() const;
value_type& get_data();

const BTNode<value_type>* get_left() const;
BTNode<value_type>* get_left();

const BTNode<value_type>* get_right() const;
BTNode<value_type>* get_right();

const BTNode<value_type>* get_parent() const;
BTNode<value_type>* get_parent();

// Setters
void set_data(const value_type& new_data);
void set_left(BTNode<value_type>* left_child);
void set_right(BTNode<value_type>* right_child);
void set_parent(BTNode<value_type>* parent_node);

// Private member variables
private:
	value_type data; // Contents of BTNodes  
	BTNode<value_type>* left; // Pointer to next BTNode
	BTNode<value_type>* right; // Pointer to previous BTNode
	BTNode<value_type>* parent; // Pointer to parent node
};

#include "BTNode.hpp"

#endif