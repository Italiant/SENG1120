/*
File: Queue.h
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Includes all the method headers for the template Queue.hpp file
*/

#ifndef QUEUEP
#define QUEUEP

#include "LinkedList.h"

template <typename value_type>
	class Queue
	{
		public:	
		// Constructors
		Queue();
		Queue(value_type& data);
		
		// Destructor 
		~Queue();

		// Getters
		bool isEmpty() const;
		int size() const;
		value_type front();
		value_type back();
		void print_queue(ostream& out);

		// Setters
		void enqueue(value_type& entry);
		value_type& dequeue();
		double average();
		value_type minimum();
		value_type maximum();
		double stdeviation();
		//void sort();

		// Private member variables
		private:
		LinkedList<value_type>* list_; // contains a linked list to work with the queue 
		int used; // holds the number of items in the queue

	};
	
	// Overloaded ostream operator
	template <typename value_type>
	ostream& operator << (ostream& out, Queue<value_type>& que);

#include "Queue.hpp"

#endif