#include <iostream>
using namespace std; 
#include "SimpleVector.h"

 // constructors
template <class DataType>
SimpleVector<DataType>::SimpleVector()
{
	vectorSize = 0; 
	vectorCapacity = DEFAULT_CAPACITY;
	vectorData = new DataType [DEFAULT_CAPACITY];
}

template <class DataType>
SimpleVector<DataType>::SimpleVector( int newCapacity )
{
	vectorSize = 0; 
	vectorCapacity = newCapacity;
	vectorData = new DataType [newCapacity];
}

template <class DataType>
SimpleVector<DataType>::SimpleVector( int newCapacity, const DataType &fillValue )
{
	vectorSize = 0; 
	vectorCapacity = newCapacity;
	vectorData = new DataType [newCapacity];
	for(vectorSize = 0; vectorSize < vectorCapacity; vectorSize++)
	{
		vectorData[vectorSize] = fillValue;
	}
}

template <class DataType>
SimpleVector<DataType>::SimpleVector( const SimpleVector &copiedVector )
{
	vectorCapacity = copiedVector.vectorCapacity;
	vectorSize = copiedVector.vectorSize;
	vectorData = new DataType [vectorCapacity];
	copyVector(vectorData, copiedVector.vectorData);
}

// destructor
template <class DataType>
SimpleVector<DataType>::~SimpleVector( )
{
	vectorSize = 0; 
	vectorCapacity = 0;
	delete vectorData;
}

// assignment
template <class DataType>
const SimpleVector<DataType>& SimpleVector<DataType>::operator = ( const SimpleVector<DataType> &rhVector )
{
	int index; 
	vectorSize =0;
	if(rhVector.vectorSize != 0)
	{
		//don't touch until it's time for refactoring out redundant code
		for(index = 0; index < rhVector.vectorSize; index++)
		{
			vectorData[index] = rhVector.vectorData[index];
			incrementSize();
			//cout << vectorSize << endl;
		}
	}

	return *this;
}

// accessors
template <class DataType>
int SimpleVector<DataType>::getCapacity() const
{
	return vectorCapacity; 
}

template <class DataType>
int SimpleVector<DataType>::getSize() const
{
	return vectorSize; 
}

// index access
template <class DataType>
DataType& SimpleVector<DataType>::operator [ ] ( int index ) throw ( logic_error )
{
	try{
		if (index > vectorSize || index < 0){
			throw;
		}
		else{
			return vectorData[index];
		}
	}
	catch(logic_error){
	}


}

template <class DataType>
const DataType& SimpleVector<DataType>::operator [ ] ( int index ) const throw ( logic_error )
{
	try{
		if (index > vectorSize || index < 0){
			throw;
		}
		else{
			return vectorData[index];
		}
	}
	catch(logic_error){

	}

}

// modifiers

// allows vector to grow by given quantity
template <class DataType>
void SimpleVector<DataType>::grow( int growBy )
{

}

// allows vector to shrink by given quantity
// allows vector to be shrunk to zero, 
//   but throws logic_error if attempt to shrink to less than zero
template <class DataType>
void SimpleVector<DataType>::shrink( int shrinkBy ) throw ( logic_error )
{
	int counter;
	SimpleVector *temp =  new SimpleVector [vectorCapacity];
	if (shrinkBy <= vectorSize){
			vectorSize = vectorSize - shrinkBy;

			for (counter = 0; counter < vectorSize; counter++){
				temp[counter] = vectorData [counter];
			}


			//delete vectorData;
			vectorCapacity = vectorCapacity - shrinkBy;
			//vectorData = new SimpleVector [ vectorCapacity ];
			//vectorData = *temp;

		
	}
	else{
		throw;

	}
}

// increment/decrement don't affect class
//    but allow programmer to keep track of size inside vector
template <class DataType>
void SimpleVector<DataType>::incrementSize()
{
	vectorSize++;
}

template <class DataType>
void SimpleVector<DataType>::decrementSize()
{
	vectorSize--;
}

template <class DataType>
void SimpleVector<DataType>::copyVector( DataType *dest, DataType *src )
{
	int index; 
	if(vectorSize != 0)
	{
		for(index = 0; index < vectorSize; index++)
		{
			vectorData[index] = src[index];
		}
	}
}
