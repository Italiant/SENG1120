/*
File: LinkedList.cpp
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Provided all functionally of a linked list including removing specific nodes, counting the number of identical nodes,
and calculating the average of all nodes as well as overloaded operators for << and +=
*/

#include "LinkedList.h"
#include "Student.h"

#include <iostream>
#include <cstdlib>

using namespace std;

// Constructors
// Precondition: None
// Postcondition: A new linked list is created and initialised with null values
LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
	current = NULL;
	list_length = 0;
}

// Precondition: Data of type value type has been defined and provided 
// Postcondition: A new linked list is created and initialised with one node of the data provided
LinkedList::LinkedList(value_type& data)
{
	head = new Node(data);
	tail = head;
	current = tail;
	list_length = 1;
}

//Destructor
// Precondition: None
// Postcondition: Destroys all the nodes in the linkedlist
LinkedList::~LinkedList()
{
	while(head!=NULL)
	{
		remove_from_head();
	}
	tail = NULL;
	current = NULL;
	list_length = 0;
}

// Accessor methods
// Precondition: The current pointer has been initialised 
// Postcondition: Returns the data of the current node 
LinkedList::value_type LinkedList::get_current()
{
	return current->get_data();
}

// Precondition: None
// Postcondition: Returns the sixe of the linked list
int LinkedList::size()
{
	return list_length;
}

// Mutator methods 
// Precondition: Data of value_type has been supplied to be added
// Postcondition: Created a new node with value_type data and adds it to the head of the linkedlist
void LinkedList::add_to_head(value_type& data)
{
	if(list_length == 0)// if list does not exist then create the linked list like in the constructor
	{
		head = new Node(data);
		tail = head;
		current = tail;
		list_length = 1;
	}
	else
	{
		Node* head_insert = new Node(data); // temp node created 
		
		head->set_previous(head_insert); // swap head with head_insert
		head_insert->set_next(head);
		
		head = head_insert; 
		
		list_length++;
		
		head_insert = NULL; // remove temp head to aviod memory leaks 
	}
}

// Precondition: Data of value_type has been supplied to be added
// Postcondition: Created a new node with value_type data and adds it to the tail of the linkedlist
void LinkedList::addToTail(value_type& data)
{
	if(list_length == 0)
	{
		head = new Node(data);
		tail = head;
		current = tail;
		list_length = 1;
	}
	else
	{
		Node* tail_insert = new Node(data); // temp node created 
		
		tail->set_next(tail_insert); // swap tail with tail_insert
		tail_insert->set_previous(tail);
		
		tail = tail_insert;
		
		list_length++;
		
		tail_insert = NULL; // remove temp tail to aviod memory leaks 
	}
}

// Precondition: None
// Postcondition: Removes one node from the head of the list
void LinkedList::remove_from_head()
{
	if(list_length == 0) // works for lists which are not created yet
	{
		return;
	}
	else if(list_length == 1) // if there is only one node remove the entire list
	{
		delete head;
		head = NULL;
		tail = NULL;
		current = NULL;
		list_length--;
		return;
	}
	else
	{
		Node* temp_head = head; // temp node created 
		
		head = temp_head->get_next(); // move head to next node after head
		
		delete temp_head; // removes pointer
		
		list_length--;
		
		temp_head = NULL;
	}
}

// Precondition: None
// Postcondition: Removes one node from the tail of the list
void LinkedList::remove_from_tail()
{
	if(list_length == 0) // works for lists which are not created yet
	{
		return;
	}
	else if(list_length == 1) // if there is only one node remove the entire list
	{
		delete head;
		head = NULL;
		tail = NULL;
		current = NULL;
		list_length--;
		return;
	}
	else
	{
		Node* temp_tail = tail; // temp node created 
		
		tail = temp_tail->get_previous(); // move tail to next node before tail
		
		delete temp_tail;
		
		list_length--;
		
		temp_tail = NULL;
	}
}

// Precondition: None
// Postcondition: Removes the current node pointer
void LinkedList::remove_from_current()
{
	Node* temp = current->get_previous(); // temp node created 
	
	temp->set_next(current->get_next()); // creates a new current node pointing to the currents previous positions
	temp = current->get_next();
	temp->set_previous(current->get_previous());
	
	delete current; //  remove origional current pointer
	
	current = temp;
	
	list_length--;
}

// Precondition: None
// Postcondition: Sets the current pointer to now point to the next node after the current 
void LinkedList::forward()
{
	current = current->get_next();
}

// Precondition: None
// Postcondition: Sets the current pointer to now point to the previous node after the current  
void LinkedList::back()
{
	current = current->get_previous();
}

// Precondition: None
// Postcondition: Sets the current pointer to now point to the head node	
void LinkedList::move_to_head()
{
	current = head;
}

// Precondition: None
// Postcondition: Sets the current pointer to now point to the tail node
void LinkedList::move_to_tail()
{
	current = tail;
}

// Precondition: A valid name of a student has been provided 
// Postcondition: Searches the list and if the name matches a name in a node then that node is removed
void LinkedList::remove(string name)
{
	bool found = false;
	move_to_head();
	for(int i = 1; i <= list_length; i++)
	{
		if(found){ // to avoid removing not working, when found return to the start of the list and traverse the whole list again
			move_to_head();
			found = false;
			i = 1;
		}

		if(name == current->get_data().get_name())
		{
			if(i == 1){ // remove from head
				remove_from_head(); 
				found = true;
			}else if(i == list_length){ // remove from tail
				remove_from_tail();
				found = true;
			}else{ //  remove from current
				remove_from_current(); 
				found = true;
				}
		}
		forward();
	}
}

// Precondition: None
// Postcondition: Gets the score for each node and adds them together and divided the total by the list size, finding the average and returns it  
double LinkedList::calcAverage()
{
	double average = 0.0, total = 0.0;
	move_to_head();
	for(int i = 1; i <= size(); i++)
	{
		total += current->get_data().get_score(); // add up total score 
		forward();
	}
	average = total/size(); // calculate average by dividing total by list size
	return average;
}

// Precondition: A valid name of a student has been provided 
// Postcondition: Searches the list and if the name matches a name in a node then the count is incramented and returned
int LinkedList::count(string name)
{
	int count = 0;
	move_to_head();
	for(int i = 1; i <= list_length; i++)
	{
		if(name == current->get_data().get_name())
		{
			count++; // adds up number of nodes with same name 
		}
		forward();
	}
	return count;
}

// Precondition: None
// Postcondition: Orders the linked list in alphabetical order from a->z
void LinkedList::order()
{
	int notSwapped = 0;
	while ( notSwapped < list_length - 1) // will continue to order the list again until all nodes are swapped
	{									  // this is becasue after the first run through some elements will still not be ordered			
		notSwapped = 0;
		move_to_head();
		for ( int i = 1; i < list_length; i++ ) // second loop to go through each node and compare them
		{		
			Node* next = current->get_next();			
			if ( next != 0 || next != NULL ) // if the next node is not the tail then order nodes
			{
				if ( current->get_data().get_name() > next->get_data().get_name() ) // for list a b c if a is > than b then swap the nodes
				{
					if ( next->get_next() == NULL || next->get_next() == 0  ) // if tail
					{						
						current->get_previous()->set_next( next );
						
						current->set_next( NULL ); // ensures that current is now tail after swap
						
						next->set_next( current );
						
						next->set_previous( current->get_previous() );
						
						current->set_previous( next );
					}
					else if ( current == head  ) // if head
					{
						current->set_next( next->get_next() );
						
						next->set_next( current );
						
						current->get_next()->set_previous( current );
						
						next->set_previous( NULL ); // ensures that current is now head after swap
						
						current->set_previous( next );
						
						head = next;						
					}
					else // if in middle
					{
						current->get_previous()->set_next( next );
						
						current->set_next( next->get_next() );
						
						next->set_next( current );
						
						current->get_next()->set_previous( current );
						
						next->set_previous( current->get_previous() );
						
						current->set_previous( next );
					}
				}			
				else if ( current->get_next() == 0 || current->get_next() == NULL ) // if at tail do not move the current pointer forward to avoid seg fault
				{
					notSwapped = notSwapped + 1;
					break;
				}
				else // if the nodes are in the correct order then move the current pointer forward and incrament the not swapped counter
				{	
					notSwapped = notSwapped + 1;
					forward();
				}
			} 
			else // if the next node is the tail
			{
				notSwapped++;
			} 
		}		
	}
}

// Overloaded ostream operator
// Precondition: The ostream command cout has been called with a valid linked list 
// Postcondition: Prints the contense of tne entire linked list from the head
ostream& operator << (ostream& out, LinkedList& list)
{
	list.move_to_head();
	for(int i = 1; i <= list.size(); i++)
	{
		out << list.get_current(); 
		list.forward();
	}
    return out;
}

// Overloaded += operator
// Precondition: Two valid linked lists have been provided i.e. list a += list b
// Postcondition: Combines list b into list a 
LinkedList& operator += (LinkedList& a, LinkedList& b)
{
	b.move_to_head();
	for(int i = 1; i <= b.size(); i++)
	{
		LinkedList::value_type c(b.get_current()); // has to be done this way because the method is outisde the linkedlist class
		a.addToTail(c);
		b.forward();
	}
	return a;
}