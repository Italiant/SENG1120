/*
File: LinkedList.hpp
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Provided all functionally of a template linked list
*/

#include <iostream>
#include <cstdlib>
#include <cassert> // needed for assert commands

using namespace std;

// Constructors
// Precondition: None
// Postcondition: A new linked list is created and initialised with null values
template <typename value_type>
LinkedList<value_type>::LinkedList()
{
	head = NULL;
	tail = NULL;
	current = NULL;
	list_length = 0;
}

// Precondition: Data of type value type has been defined and provided 
// Postcondition: A new linked list is created and initialised with one node of the data provided
template <typename value_type>
LinkedList<value_type>::LinkedList(value_type& data)
{
	head = new Node<value_type>(data);
	tail = head;
	current = tail;
	list_length = 1;
}

// Destructor
// Precondition: None
// Postcondition: Destroys all the nodes in the linkedlist
template <typename value_type>
LinkedList<value_type>::~LinkedList()
{
	while(current != NULL)
	{
		Node<value_type>* next_temp = current->get_next();
		delete current;
		current = next_temp;
	}
	tail = NULL;
	current = NULL;
	list_length = 0;
}

// Accessor methods
// Precondition: The current pointer has been initialised 
// Postcondition: Returns the data of the current node 
template <typename value_type>
value_type LinkedList<value_type>::get_current() const
{
	return current->get_data();
}

// Precondition: None
// Postcondition: Returns the sixe of the linked list
template <typename value_type>
int LinkedList<value_type>::size()
{
	return list_length;
}

// Precondition: None 
// Postcondition: Returns the data contained in the head node
template <typename value_type>
value_type LinkedList<value_type>::get_head() const
{
	return head->get_data();
}

// Precondition: None
// Postcondition: Returns the data contained in the tail node
template <typename value_type>
value_type LinkedList<value_type>::get_tail() const
{
	return tail->get_data();
}

// Mutator methods 
// Precondition: Data of value_type has been supplied to be added
// Postcondition: Created a new node with value_type data and adds it to the head of the linkedlist
template <typename value_type>
void LinkedList<value_type>::add_to_head(value_type& data)
{
	if(list_length == 0)// if list does not exist then create the linked list like in the constructor
	{
		head = new Node<value_type>(data);
		tail = head;
		current = tail;
		list_length = 1;
	}
	else
	{
		Node<value_type>* head_insert = new Node<value_type>(data); // temp node created 
		
		head->set_previous(head_insert); // swap head with head_insert
		head_insert->set_next(head);
		
		head = head_insert; 
		
		list_length++;
		
		head_insert = NULL; // remove temp head to aviod memory leaks 
	}
}

// Precondition: Data of value_type has been supplied to be added
// Postcondition: Created a new node with value_type data and adds it to the tail of the linkedlist
template <typename value_type>
void LinkedList<value_type>::addToTail(value_type& data)
{
	if(list_length == 0)
	{
		head = new Node<value_type>(data);
		tail = head;
		current = tail;
		list_length = 1;
	}
	else
	{
		Node<value_type>* tail_insert = new Node<value_type>(data); // temp node created 
		
		tail->set_next(tail_insert); // swap tail with tail_insert
		tail_insert->set_previous(tail);
		
		tail = tail_insert;
		
		list_length++;
		
		tail_insert = NULL; // remove temp tail to aviod memory leaks 
	}
}

// Precondition: None
// Postcondition: Removes one node from the head of the list
template <typename value_type>
value_type& LinkedList<value_type>::remove_from_head()
{
	assert (list_length != 0); // do not remove any node if the list is empty

	if(list_length == 1) // if there is only one node remove the entire list
	{
		Node<value_type>* temp_head = head;
		head = NULL;
		tail = NULL;
		current = NULL;
		list_length--;
		return temp_head->get_data();
	}
	else
	{
		Node<value_type>* temp_head = head; // temp node created 
		
		head = temp_head->get_next(); // move head to next node after head
		
		list_length--;
		
		return temp_head->get_data();
	}
}

// Precondition: None
// Postcondition: Removes one node from the tail of the list
template <typename value_type>
value_type& LinkedList<value_type>::remove_from_tail()
{
	assert (list_length != 0); // do not remove any node if the list is empty
	
	if(list_length == 1) // if there is only one node remove the entire list
	{
		Node<value_type>* temp_tail = tail;
		head = NULL;
		tail = NULL;
		current = NULL;
		list_length--;
		return temp_tail->get_data();
	}
	else
	{
		Node<value_type>* temp_tail = tail; // temp node created 
		
		tail = temp_tail->get_previous(); // move tail to next node before tail
		
		list_length--;
		
		return temp_tail->get_data();
	}
}

// Precondition: None
// Postcondition: Removes the current node pointer
template <typename value_type>
value_type& LinkedList<value_type>::remove_from_current()
{
	Node<value_type>* temp = current->get_previous(); // temp node created 
	
	temp->set_next(current->get_next()); // creates a new current node pointing to the currents previous positions
	temp = current->get_next();
	temp->set_previous(current->get_previous());
	
	current = temp;
	
	list_length--;
	
	return temp->get_data();
}

// Precondition: None
// Postcondition: Sets the current pointer to now point to the next node after the current 
template <typename value_type>
void LinkedList<value_type>::forward()
{
	current = current->get_next();
}

// Precondition: None
// Postcondition: Sets the current pointer to now point to the previous node after the current  
template <typename value_type>
void LinkedList<value_type>::back()
{
	current = current->get_previous();
}

// Precondition: None
// Postcondition: Sets the current pointer to now point to the head node	
template <typename value_type>
void LinkedList<value_type>::move_to_head()
{
	current = head;
}

// Precondition: None
// Postcondition: Sets the current pointer to now point to the tail node
template <typename value_type>
void LinkedList<value_type>::move_to_tail()
{
	current = tail;
}

// Overloaded ostream operator
// Precondition: The ostream command cout has been called with a valid linked list 
// Postcondition: Prints the entire linked list from the head
template <typename value_type>
ostream& operator << (ostream& out, LinkedList<value_type>& list)
{
	list.move_to_tail();
	for(int i = 1; i <= list.size(); i++)
	{
		if(i == list.size())
			out << list.get_current() << " )"; 
		else if(i == 1)
			out << "( "<< list.get_current() << " "; 
		else
			out << " "<< list.get_current() << " ";
		
		list.back();
	}
    return out;
}

// Precondition: None
// Postcondition: Orders the linked list in numerical order from largest->smallest
/*template <typename value_type>
void LinkedList<value_type>::order()
{
	int notSwapped = 0;
	while ( notSwapped < list_length - 1) // will continue to order the list again until all nodes are swapped
	{									  // this is becasue after the first run through some elements will still not be ordered			
		notSwapped = 0;
		move_to_head();
		for ( int i = 1; i < list_length; i++ ) // second loop to go through each node and compare them
		{		
			Node<value_type>* next = current->get_next();			
			if ( next != 0 || next != NULL ) // if the next node is not the tail then order nodes
			{
				if ( current->get_data() < next->get_data()) // for list a b c if a is > than b then swap the nodes
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
}*/