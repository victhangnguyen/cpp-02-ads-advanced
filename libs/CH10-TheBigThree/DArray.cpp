#include "DArray.h"

using namespace std;

ostream& operator<<(ostream& out, const DArray& outArray)
{
	for (int i = 0; i < outArray.numOfElements; ++i)
		out << outArray.a[i] << " ";

	return out;
}

DArray::DArray( )
{
    capacity = CAP;
	a = new int[capacity];	
	numOfElements = 0;
}

DArray::DArray(int newCapacity) 
{
	capacity = newCapacity;
    a = new int[capacity];
	numOfElements = 0;	 
}

//copy constructor
DArray::DArray(const DArray& otherArray)
{
	//set all member variables of the calling object
	capacity = otherArray.capacity;
	numOfElements = otherArray.numOfElements;

	//create a new array
	a = new int[capacity];

	//copy all elements of the array parameter
	//  onto the calling object
	for (int i = 0; i < numOfElements; ++i)
		a[i] = otherArray.a[i];
}

void DArray::addElement(int element)
{
    if (numOfElements >= capacity)
    {
        cerr << "Attempt to exceed capacity in DArray.\n";
        exit(0); 
    }
    a[numOfElements] = element;
    ++numOfElements;
}

//overloaded assignment operator
DArray& DArray::operator=(const DArray& rightSide)
{
	//to avoid self assignment, check that the 
	//   parameter passed is not the calling object
	if (&rightSide != this) 
	{
		//if the array we are passing has a different
		//  capacity from the calling object,
		//  then we need to create a new array
		if (capacity != rightSide.capacity)
		{
			//deallocate the memory used by 
			//  the calling object and
			//  re-create the object so that 
			//  it has the same capacity
		    delete [ ] a;  
		    a = new int[rightSide.capacity];
			
			//update capacity
			capacity = rightSide.capacity;
		}

		//update number of elements	
		numOfElements = rightSide.numOfElements;

		// start copying
		for (int i = 0; i < numOfElements; ++i)
			a[i] = rightSide.a[i];
	}
	else
	{
		cerr << "Attempted assignment to itself.";
	}

	return *this;
}

DArray::~DArray( )
{
    delete [] a; //delete the array
	a = nullptr;
}

