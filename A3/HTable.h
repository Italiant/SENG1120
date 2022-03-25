/*
File: HTable.h
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Includes all the method headers for the template HTable.hpp file to work with hash tables
*/

#ifndef HTableP
#define HTableP

#include <iostream>
#include <cstdlib>

template <typename value_type>
class HTable
{
public:
// Constructor
HTable();

// Destructor
~HTable();

// Getters
void print(ostream& out);

// Setters
void add(value_type value);
void remove(value_type value);

// Private member variables
private:
	int size;
	value_type data[150];
	// Hash Function
	int hashfun(int value);
};

// Overloaded ostream operator
template <typename value_type>
ostream& operator << (ostream& out, HTable<value_type>& table);

#include "HTable.hpp"

#endif