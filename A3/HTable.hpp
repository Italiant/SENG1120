/*
File: BTNode.hpp
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Provides all methods for working with template HTables such as adding and removing values all influenced by the underlying hash function
*/

using namespace std;

// Constructor
// Precondition: None
// Postcondition: Creates an array of 150 positions to store value_type and initialises the size of the hash table
template <typename value_type>
HTable<value_type>::HTable()
{
	for(int index = 0; index < 150; index++)
	{
		data[index] = 0;
	}
	size = 0;
}

// Destructor
// Precondition: None
// Postcondition: Does same method as constructor, resetting all positions and size to 0
template <typename value_type>
HTable<value_type>::~HTable()
{
	for(int index = 0; index < 150; index++)
	{
		data[index] = 0;
	}
	size = 0;
}

// Accessor methods
// Precondition: Has been called from the overload operator so needs ostream value
// Postcondition: Creates a print string to send to the overloaded operator to print onto the screen
template <typename value_type>
void HTable<value_type>::print(ostream& out)
{
	for(int index = 0; index < 150; ++index)
	{
		if(data[index] != 0) // only print if there is a value other than 0
			out << data[index] << " ";
	}
} 

// Mutator methods 
// Precondition: A valid value of type value_type to be added
// Postcondition: Creates an index integer position unique to the value, provided by the hash function, and then adds that
//				  value into the data array, also incraments the size
template <typename value_type>
void HTable<value_type>::add(value_type value)
{
	int index = hashfun(value);
	data[index] = value;
	size++;
} 

// Precondition: A valid value of type value_type to be added
// Postcondition: Creates an index integer position unique to the value, provided by the hash function, and then removes that
//				  value from the data array by setting its value to 0, also decraments the size
template <typename value_type>
void HTable<value_type>::remove(value_type value)
{
	int index = hashfun(value);
	data[index] = 0;
	size--;
} 

// Precondition: A valid integer position of the value in the array
// Postcondition: Returns the 'hashed' value of the input 
template <typename value_type>
int HTable<value_type>::hashfun(int value)
{
	return value%150;
} 

// Overloaded ostream operator
// Precondition: A valid hash table has been called from the main program
// Postcondition: Calls the print function which creates a print string for the hash table seperated by a space then returns the string to print here
template <typename value_type>
ostream& operator << (ostream& out, HTable<value_type>& table)
{
	cout << " " << endl;
	table.print(out);
    return out;
}