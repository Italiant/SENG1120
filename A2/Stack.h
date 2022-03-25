/*
File: Queue.h
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Includes all the method headers for the template Stack.hpp file
*/

#ifndef STACKP
#define STACKP

#include "LinkedList.h"

template <typename value_type>
	class Stack
	{
		public:	
		// Constructors
		Stack();
		Stack(value_type& data);
		
		// Destructor
		~Stack();

		// Getters
		value_type top() const;
		int size() const;
		bool isEmpty();
		void print_stack(ostream& out);
		
		// Setters
		void push(value_type data);
		value_type& pop();

		// Private member variables
		private:
		LinkedList<value_type>* list_; // contains a linked list to work with the stack 
		int used;
		
	};
	
	// Overloaded ostream operator
	template <typename value_type>
	ostream& operator << (ostream& out, Stack<value_type>& stak);

#include "Stack.hpp"

#endif