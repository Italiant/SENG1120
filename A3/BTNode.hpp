/*
File: BTNode.hpp
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Provides all methods for working with template BTNodes such as setting and getting the right, left or parent data of a BTNode
*/

using namespace std;

// Constructor
// Precondition: Data of type value type has been defined and provided 
// Postcondition: A new BTNode is created and initialised with the initial data predefined by value type
template <typename value_type>
BTNode<value_type>::BTNode(const value_type& initial_data)
{
	data = initial_data;
	left = NULL;
	right = NULL;
	parent = NULL;
}

// Destructor
// Precondition: None
// Postcondition: Sets all nodes to null and then deletes them to free up memory 
template <typename value_type>
BTNode<value_type>::~BTNode()
{
	left = NULL;
	right = NULL;
	parent = NULL;
	delete left;
	delete right;
	delete parent;
}

// Accessor methods
// Precondition: None
// Postcondition: Returns the data currently stored in a BTNode
template <typename value_type>
value_type BTNode<value_type>::get_data() const
{
	return data;
}

// Precondition: None
// Postcondition: Returns the data currently stored in a BTNode in the form of a reference variable
template <typename value_type>
value_type& BTNode<value_type>::get_data()
{
	return data;
}

// Precondition: None
// Postcondition: Returns the left BTNode with the condition that it will not be changed
template <typename value_type>
const BTNode<value_type>* BTNode<value_type>::get_left() const
{
	return left;
}

// Precondition: None 
// Postcondition: Returns the left BTNode
template <typename value_type>
BTNode<value_type>* BTNode<value_type>::get_left()
{
	return left;
}

// Precondition: None
// Postcondition: Returns the right BTNode with the condition that it will not be changed
template <typename value_type>
const BTNode<value_type>* BTNode<value_type>::get_right() const
{
	return right;
}

// Precondition: None 
// Postcondition: Returns the right BTNode
template <typename value_type>
BTNode<value_type>* BTNode<value_type>::get_right()
{
	return right;
}

// Precondition: None
// Postcondition: Returns the parent BTNode with the condition that it will not be changed
template <typename value_type>
const BTNode<value_type>* BTNode<value_type>::get_parent() const
{
	return parent;
}

// Precondition: None 
// Postcondition: Returns the parent BTNode
template <typename value_type>
BTNode<value_type>* BTNode<value_type>::get_parent()
{
	return parent;
}

// Mutator methods 
// Precondition: Data of type value type has been defined and provided 
// Postcondition: Initilises data
template <typename value_type>
void BTNode<value_type>::set_data(const value_type& new_data)
{
	data = new_data;
}

// Precondition: The left BTNode pointer is provided  
// Postcondition: Initilises the left BTNode  
template <typename value_type>
void BTNode<value_type>::set_left(BTNode<value_type>* left_child)
{
	left = left_child;
}

// Precondition: The right BTNode pointer is provided  
// Postcondition: Initilises the right BTNode  
template <typename value_type>
void BTNode<value_type>::set_right(BTNode<value_type>* right_child)
{
	right = right_child;
}

// Precondition: The right BTNode pointer is provided  
// Postcondition: Initilises the parent BTNode  
template <typename value_type>
void BTNode<value_type>::set_parent(BTNode<value_type>* parent_node)
{
	parent = parent_node;
}