/*
File: BSTree.h
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Includes all the method headers for the template BSTree.hpp file
*/

#ifndef BST
#define BST

#include <cstdlib>
#include <iostream>
#include "BTNode.h"

template <typename value_type>
class BSTree
{
public:
	// Constructors
	BSTree();
	BSTree(value_type& data);

	// Destructor
	~BSTree();

	// Getters
	int size();
	value_type root() const;
	void print(ostream& out);

	// Setters
	void add(value_type data);
	void remove(value_type data);
	void remove_tree(BTNode<value_type>* node);

// Private member variables
private:
	BTNode<value_type>* root_;
	int nodes;
	// Private member functions
	void printInOrder(BTNode<value_type>* node, int level, ostream& out);
	int compare(const value_type& a, const value_type& b);
	void insert(BTNode<value_type>* current_node_, value_type& data);
	BTNode<value_type>* remove(BTNode<value_type>* current_node, value_type& data);
};

// Overloaded ostream operator
template <typename value_type>
ostream& operator << (ostream& out, BSTree<value_type>& tree);

#include "BSTree.hpp"

#endif