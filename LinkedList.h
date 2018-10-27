/* Jacob Leuquire
 * Original LinkedList.h taken from Lab 2, COSC 2030
 * Project 1
 * October 2018
 */


#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream>
using std::ostream;

#include "Node.h"

#define ulong unsigned long


class List
{
public:
	//*** Standard functions ***

	// Default constructor
	// post: this List is empty.
	List();

	// Copy constructor
	// post: this List now stores a copy of the sequence stored
	//         in other
	List(const List & other);

	// Destructor
	// post: all the Nodes of this List have been destroyed.
	~List();

	// Assignment operator
	// post: this List now stores a copy of the sequence stored
	//         in other
	const List & operator=(const List & other);

	// Test for equality
	bool operator==(const List &rhs);

	//*** Accessors ***

	// post: true has been returned just if this List is
	//         empty.
	bool empty() const;

	// post: the doubles in this List have been written to
	//         outfile.
	void print(ostream & outfile) const;

	void printArr();

	//*** Mutators ***

	// post: x has been added as the first double in this
	//         List.
	void insertAsFirst(double x);

	// pre:  this List is not empty.
	// post: the first double in this List has been removed
	//         from this List and has been returned.
	double removeFirst();

	int size();

	double sum();

	void insertAsLast(float x);

	double max();

	double min();

private:
	//*** Inaccessible standard functions ***


	//*** Helper functions ***
	// process part of the linked structure

	// post: a pointer to a copy of the linked structure
	//         targeted by ptr has been returned.
	static Node * clone(Node * ptr);


private:
	Node * first_;

};


//*** Auxiliary functions ***

// post: the doubles in list have been written to outfile
ostream & operator<<(ostream & outfile, const List & list);

#endif
