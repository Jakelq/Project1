/* Jacob Leuquire
 * Original Node.h taken from lab 2, COSC 2030
 * Project 1
 * October 2018
 */


#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
using std::cout;
using std::endl;


class Node
{
public:
	double entry_;
	Node * next_;

public:
	// Constructors

	// post: this Node contains entry and a NULL pointer
	explicit Node(double entry);

	// post: this Node contains entry and next
	Node(double entry, Node * next);

	// Destructor

	~Node();

private:
	// Inaccessible standard functions
	Node();
	Node(const Node &);
	const Node & operator=(const Node &);
};

#endif