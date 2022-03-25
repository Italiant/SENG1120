/*
File: BSTree.hpp
Author: Thomas Miller
Student Number: C3279309
Course: SENG1120
Program Description: Provides all methods for working with template BSTrees such as inserting and removing nodes and comparing two seperate nodes
*/

using namespace std;

// Constructors
// Precondition: None
// Postcondition: Initialises the root node to null and sets the number of nodes equal zero
template <typename value_type>
BSTree<value_type>::BSTree()
{
	root_ = NULL;
	nodes = 0;
}

// Precondition: A valid reference variable data of type value_type has been provided
// Postcondition: Sets the root node to equal to new value stored in data
template <typename value_type>
BSTree<value_type>::BSTree(value_type& data)
{
	root_ = new BTNode<value_type>(data);
	nodes = 1;
}

// Destructors
// Precondition: None
// Postcondition: Calls the remove_tree method to remove the whole BStree
template <typename value_type>
BSTree<value_type>::~BSTree()
{
	remove_tree(root_);
	delete root_; // deletes pointer to root freeing up memory
	nodes = 0;
}

// Precondition: The initial node of the tree such as the root has been provided 
// Postcondition: Starting at the provided node removes all left and right nodes then finally the root node of the tree via recursion
template <typename value_type>
void BSTree<value_type>::remove_tree(BTNode<value_type>* node)
{
	if(node != NULL)
    {
        remove_tree(node->get_left()); // gets left node
        remove_tree(node->get_right()); // gets right node
        if(node->get_left() != NULL) // removes left then right node
            node->set_left(NULL);
        if(node->get_right() != NULL)
            node->set_right(NULL);
        node = NULL; // removes root node
    }
}

// Accessor methods
// Precondition: Node
// Postcondition: Returns the size of the BSTree
template <typename value_type>
int BSTree<value_type>::size()
{
	return nodes;
}

// Precondition: None
// Postcondition: Returns the data stored in the root node not to be changed
template <typename value_type>
value_type BSTree<value_type>::root() const
{
	return root_->get_data();
}

// Precondition: Two valid value_tyoe data have been provided 
// Postcondition: Compares the value in a with the value in b and returns the result -1, 0 or 1
template <typename value_type>
int BSTree<value_type>::compare(const value_type& a, const value_type& b)
{
	if(a > b)
	{
		return -1;
	}
	else if(a == b)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

// Mutator methods 
// Precondition: Valid data of type value_type has been provided of the node to be added
// Postcondition: Calls the private method insert starting at the root node with the data to be added
template <typename value_type>
void BSTree<value_type>::add(value_type data)
{
	if(root_ == NULL) // if tree does not exist yet add a new root
	{
		root_ = new BTNode<value_type>(data);
		nodes++;
	}
	else // add to root
	{
		insert(root_, data);
	}
}

// Precondition: The current node and data of a node to be inserted has been provided
// Postcondition: Inserts a new node into the BSTree at either the root, right or left node of the current node via recursion
template <typename value_type>
void BSTree<value_type>::insert(BTNode<value_type>* current_node, value_type& data)
{
	int relationship = compare(data, current_node->get_data()); // initialises the relationship between the data to be inserted and the current node
	
	if(relationship == 0) // root
	{
		current_node->set_data(data); // set new root value
	}
	else if(relationship > 0) // right
	{
		if(current_node->get_right() == NULL)
		{
			current_node->set_right(new BTNode<value_type>(data)); // create new right node and add value there
			nodes++;
			return;
		}
		else
		{
			insert(current_node->get_right(), data); // recursion
		}
	}
	else // left
	{
		if(current_node->get_left() == NULL)
		{
			current_node->set_left(new BTNode<value_type>(data)); // create new left node and add value there
			nodes++;
			return;
		}
		else
		{
			insert(current_node->get_left(), data); // recursion
		}
	}
}

// Precondition: Valid data of type value_type has been provided of the node to be removed
// Postcondition: Calls the private method remove starting at the root node with the data to be removed
template <typename value_type>
void BSTree<value_type>::remove(value_type data)
{
	if(nodes == 0) // if tree does not exist then just return 
	{
		return;
	}
	else // remove from the root
	{
		remove(root_, data);
	}
}

// Precondition: The current node and data of a node to be removed has been provided
// Postcondition: Removes the node from BSTree at either the root, right or left node of the current node via recursion 
template <typename value_type>
BTNode<value_type>* BSTree<value_type>::remove(BTNode<value_type>* current_node, value_type& data)
{
	if (current_node == NULL) 
		return current_node;
	
	//cout << "current node = " << current_node->get_data() << endl;
	//cout << "data to compare " << data << endl;
 
		// If the data to be deleted is smaller than the root's data,
		// then look left
		if (data > current_node->get_data())
			current_node->set_left(remove(current_node->get_left(), data));
	 
		// If the data to be deleted is greater than the root's data,
		// then look right
		else if (data < current_node->get_data())
			current_node->set_right(remove(current_node->get_right(), data));
	 
		// if data is same as root's data, then This is the node
		// to be deleted
		else if (data == current_node->get_data())
		{
			nodes--;
			//cout << "node to be deleted " << current_node->get_data() << endl;
			// node with only one child or no child
			if ( current_node->get_left() == NULL )
			{
				BTNode<value_type> *temp = current_node->get_right();
				return temp;
			}
			else if (current_node->get_right() == NULL)
			{
				BTNode<value_type> *temp = current_node->get_left();
				return temp;
			}
			else
			{
				// node with two children: Get the inorder successor (smallest
				// in the right subtree) and move that up to empty position
				
				BTNode<value_type>* current = current_node->get_right();
		 
				/* loop down to find the leftmost leaf */
				while ( current->get_left() != NULL )
					current = current->get_left();		 
				
				BTNode<value_type>* temp = current;
		 
				// Copy the inorder successor's content to this node
				current_node->get_data() = temp->get_data();
		 
				// Delete the inorder successor
				current_node->set_right( remove( current_node->get_right(), temp->get_data() ) );
			}
		}
		else
		{
			return current_node;
		}
		return current_node;
}

// Precondition: Has been called from the overload operator so needs ostream value
// Postcondition: Calls the private print_in_order method to print the BSTree and updates the print string out used by the overloaded operator
template <typename value_type>
void BSTree<value_type>::print(ostream& out)
{
	printInOrder(root_, 0, out); // prints whole tree from the root node
}

// Precondition: The node to print from, the level at which the node is on and the ostream value out to be provided
// Postcondition: With recursion, creats the print string of the BSTree from right to left with 'in order' method 
template <typename value_type>
void BSTree<value_type>::printInOrder(BTNode<value_type>* node, int level, ostream& out)
{
	if(node != NULL)
	{
		printInOrder(node->get_right(), level+1, out); // gets right node
		
		/* uncomment to print out in tree form
		for(int i = 1; i<= level; ++i)
			cout << " | ";
		cout << node->get_data() << endl;
		*/
		out << node->get_data() << " "; // prints out the node
		
		printInOrder(node->get_left(), level+1, out); // gets left node
	}
}

// Overloaded ostream operator
// Precondition: A valid binary search tree has been called from the main program
// Postcondition: Calls the print function which creates a print string for the binary search tree which returns the string to print here
template <typename value_type>
ostream& operator << (ostream& out, BSTree<value_type>& tree)
{
	cout << " " << endl;
	tree.print(out);
    return out;
}
















