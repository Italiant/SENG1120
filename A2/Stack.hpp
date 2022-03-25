/*
File: Stack.hpp
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Extends functionality to a pre-existing linkedlist and provides all functionally of a template stack including push, pop, getting the top of the stack,
calculating the average, min, max and standard deviation, and printing out the stack
*/

#include <iostream>
#include <cstdlib>

using namespace std;

// Constructors
// Precondition: None
// Postcondition: The local linkedlist for stack is created and initialised
template <typename value_type>
Stack<value_type>::Stack()
{
	list_ = new LinkedList<value_type>();
	used = 0;
}

// Precondition: Data of type value type has been defined and provided
// Postcondition: The local linkedlist for stack is created and initialised with one node of the data provided
template <typename value_type>
Stack<value_type>::Stack(value_type& data)
{
	list_ = new LinkedList<value_type>(data);
	used = 1;
}

// Destructor 
// Precondition: None
// Postcondition: Removes the local linkedlist pointer and all its nodes 
template <typename value_type>
Stack<value_type>::~Stack()
{
	delete list_; // removes the entire linkedlist
	used = 0;
}

// Accessor methods
// Precondition: None 
// Postcondition: Returns the front of the local linkedlist
template <typename value_type>
value_type Stack<value_type>::top() const
{
	return list_->get_head();
}

// Precondition: None
// Postcondition: Returns the size of the stack
template <typename value_type>
int Stack<value_type>::size() const
{
	return used;
}

// Precondition: None
// Postcondition: Returns the condition true or false depending on if the stack is populated or not 
template <typename value_type>
bool Stack<value_type>::isEmpty()
{
	return used == 0;
}

// Precondition: An overloaded ostream operator << method for linkedlist has been created and defined and the ostream
//				 variable out has been provided from a local overloaded << operator method 
// Postcondition: Uses the overloaded ostream operator to save the print command for the local linkedlist to the variable out
template <typename value_type>
void Stack<value_type>::print_stack(ostream& out)
{
	out << *list_;
}

// Mutator methods 
// Precondition: Data of type value type has been defined and provided 
// Postcondition: Adds the entry to the top of the stack
template <typename value_type>
void Stack<value_type>::push(value_type data)
{
	list_->add_to_head(data);
	used++;
}

// Precondition: None
// Postcondition: Removes an entry from the top of the stack
template <typename value_type>
value_type& Stack<value_type>::pop()
{
	return list_->remove_from_head();
	used--;
}

// Precondition: The ostream command cout has been called with a valid stack 
// Postcondition: Prints the entire stack from the top by calling the local print method 
template <typename value_type>
ostream& operator << (ostream& out, Stack<value_type>& stak)
{
	stak.print_stack(out); // calls the print method becasue the local linkedlist is not defined in this method
	return out;
}