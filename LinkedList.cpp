/* Jacob Leuquire
 * Original LinkedList.cpp taken from Lab 2, COSC 2030
 * Project 1
 * October 2018
 */



#include "LinkedList.h"
//#include "Node.cpp"
#include <utility>

List::List()
	: first_(NULL)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}

const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}

bool List::operator==(const List &rhs) {
	/*if(size() == 0 && rhs.size() == 0){return true;}//both empty
	if(size() != rhs.size()){return false;}//sizes not the same
	Node * lptr = this->next_;
	Node * rptr = rhs->next_;
		Double lEntry = lptr->entry_;
	Double rEntry = rptr->entry_;
		while (lptr != NULL && rptr != NULL)
		{
	  if(lEntry != rEntry){
		return false;
	  }
	  lptr = lptr->next_;
	  rptr = rptr->next_;
	  lEntry = lptr->entry_;
	  rEntry = rptr->entry_;
		}
		*/
	return true;
}


bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);
}


double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}

void List::printArr()
{

}


int List::size()
{
	int count = 0;
	if (!empty())
	{
		Node * tempPtr = first_;
		while (tempPtr != NULL)
		{
			tempPtr = tempPtr->next_;
			count++;
		}
	}
	return count;
}

double List::sum()
{
	double value = 0;
	double sum = 0;
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		Node * ptr = first_;
		while (ptr != NULL)
		{
			value = ptr->entry_;
			ptr = ptr->next_;
			sum += value;
		}
	}
	return sum;
}

void List::insertAsLast(float x)
{
	Node * current = first_;
	double temp = 0;
	if (current == NULL)
	{
		first_ = new Node(x, first_);
	}
	else
	{
		while (current->next_ != NULL)
		{
			current = current->next_;
		}
		current->next_ = new Node(x, current->next_);
	}
}

double List::max()
{
	Node * current = first_;
	double max = 0;
	while (current != NULL)
	{
		if (max < current->entry_)
		{
			max = current->entry_;
		}
		current = current -> next_;
	}
	return max;
}

double List::min()
{
	Node * current = first_;
	double min = INT_MAX;
	while (current != NULL)
	{
		if (min > current->entry_)
		{
			min = current->entry_;
		}
		current = current->next_;
	}
	return min;
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}