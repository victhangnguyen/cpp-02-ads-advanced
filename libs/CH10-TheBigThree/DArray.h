#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>

const int CAP = 50;

class DArray
{
	friend std::ostream& operator<<(std::ostream& out, const DArray&);

public:
    DArray();
    DArray(int);
	DArray(const DArray&); //copy constructor
	
    void addElement(int);

    //overloaded assignment operator
	DArray& operator=(const DArray&); 

    ~DArray();

private:
    int *a;			
    int capacity;	
    int numOfElements;	
};

#endif