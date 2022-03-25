/*
File: Queue.hpp
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Extends functionality to a pre-existing linked list and provides all functionally of a template queue including enqueue, dequeue, getting the front or back of the queue,
calculating the average, min, max and standard deviation, and printing out the queue
*/

#include <iostream>
#include <cstdlib>
#include<cmath> // needed for pow and sqrt commands

using namespace std;

// Constructors
// Precondition: None
// Postcondition: The local linked list for queue is created and initialised
template <typename value_type>
Queue<value_type>::Queue()
{
	list_ = new LinkedList<value_type>();
	used = 0;
}

// Precondition: Data of type value type has been defined and provided
// Postcondition: The local linked list for queue is created and initialised with one node of the data provided
template <typename value_type>
Queue<value_type>::Queue(value_type& data)
{
	list_ = new LinkedList<value_type>(data);
	used = 1;
}

// Destructor
// Precondition: None
// Postcondition: Removes the local linked list pointer and all its nodes 
template <typename value_type>
Queue<value_type>::~Queue()
{
	delete list_; // removes the entire linked list
	used = 0;
}

// Accessor methods
// Precondition: None
// Postcondition: Returns the condition true or false depending on if the queue is populated or not 
template <typename value_type>
bool Queue<value_type>::isEmpty() const
{
	return used == 0;
}

// Precondition: None
// Postcondition: Returns the size of the queue
template <typename value_type>
int Queue<value_type>::size() const
{
	return used;
}

// Precondition: None
// Postcondition: Returns the head of the local linked list
template <typename value_type>
value_type Queue<value_type>::front()
{
	return list_->get_head();
}

// Precondition: None
// Postcondition: Returns the tail of the local linked list
template <typename value_type>
value_type Queue<value_type>::back()
{
	return list_->get_tail();
}

// Precondition: An overloaded ostream operator << method for linked list has been created and defined and the ostream
//				 variable out has been provided from a local overloaded << operator method 
// Postcondition: Uses the overloaded ostream operator to save the print command for the local linked list to the variable out
template <typename value_type>
void Queue<value_type>::print_queue(ostream& out)
{
		out << *list_;
}

// Mutator methods 
// Precondition: An entry of type value type has been defined and provided
// Postcondition: Adds the entry to the front of the queue
template <typename value_type>
void Queue<value_type>::enqueue(value_type& entry)
{
	list_->add_to_head(entry);
	used++;
}

// Precondition: None
// Postcondition: Removes an entry from the front of the queue
template <typename value_type>
value_type& Queue<value_type>::dequeue()
{
	return list_->remove_from_head();
	used--;
}

// Precondition: None
// Postcondition: Calculates and returns the average of all the nodes in the queue
template <typename value_type>
double Queue<value_type>::average()
{
	double average = 0.0, total = 0.0;
	list_->move_to_head();
	for(int i = 1; i <= size(); i++)
	{
		total += list_->get_current(); // add up total score 
		list_->forward();
	}
	average = total/size(); // calculate average by dividing total by list size
	return average;
}

// Precondition: None
// Postcondition: Calculates and returns the minimum node/value of the queue
template <typename value_type>
value_type Queue<value_type>::minimum()
{
	list_->move_to_head();
	value_type min = list_->get_current(); // initialise the minimum to the current value
	for(int i = 1; i <= size(); i++)
	{
		if(list_->get_current() < min) // if the current value is less than the current minimum 
			min = list_->get_current(); // set the new minimum value 
		list_->forward();
	}
	return min;
}

// Precondition: None
// Postcondition: Calculates and returns the maximum node/value of the queue
template <typename value_type>
value_type Queue<value_type>::maximum()
{
	list_->move_to_head();
	value_type max = list_->get_current(); // initialise the maximum to the current value
	for(int i = 1; i <= size(); i++)
	{
		if(list_->get_current() > max) // if the current value is greater than the current maximum 
			max = list_->get_current(); // set the new maximum value 
		list_->forward();
	}
	return max;
}

// Precondition: None
// Postcondition: Calculates and returns the standard deviation of all the nodes in the queue
template <typename value_type>
double Queue<value_type>::stdeviation()
{
	double mean = average(); // calls the average method to initialise the local mean value
	double variance = 0.0;
	double stdev = 0.0;
	list_->move_to_head();
	for(int i = 1; i <= size(); i++)
	{
		variance += pow((list_->get_current() - mean), 2); // calculates the variance by summing (xi - mean)^2 for each node
		list_->forward();
	}
	variance = variance/(size()-1); // calculates the variance for the size of the sample
	stdev = sqrt(variance); // the standard deviation is the square root of the variance 
	return stdev;
}

// Precondition: None
// Postcondition: Sorts the queue in order of largest to smallest from front to back
/*template <typename value_type>
void Queue<value_type>::sort()
{
	;
}*/

// Precondition: The ostream command cout has been called with a valid queue 
// Postcondition: Prints the entire queue from the front by calling the local print method
template <typename value_type>
ostream& operator << (ostream& out, Queue<value_type>& que)
{
	que.print_queue(out); // calls the print method becasue the local linked list is not defined in this method
	return out;
}