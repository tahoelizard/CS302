// Program Information ////////////////////////////////////////////////////////
/**
 * @file SimpleVector.cpp
 * 
 * @author Michael Leverington
 *
 * @brief Implementation file for SimpleVector class
 * 
 * @details Implements all member methods of the SimpleVector class
 *
 * @version 1.00 (30 August 2015)
 *
 * @Note Requires SimpleVector.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_PRIORITYQUEUE_CPP
#define CLASS_PRIORITYQUEUE_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "PriorityQueue.h"

/**
 * @brief Default constructor
 *
 * @details Constructs vector capacity to default and vector size to zero
 *          creates default size data array
 *          
 * @param None
 *
 * @note None
 */
template <class DataType>
PriorityQueue<DataType>::PriorityQueue()
{
	head = NULL;
	rear = NULL; 
}

// destructor
template <class DataType>
PriorityQueue<DataType>::~PriorityQueue( )
{
	
}

template <class DataType>
bool PriorityQueue<DataType>::isEmpty()
{
    if(head == NULL){
    	return true;
    }
    else{
    	return false;
    }
}

template <class DataType>
void PriorityQueue<DataType>::dequeue(DataType)
{

}

template <class DataType>
void PriorityQueue<DataType>::enqueue (int newPri, char* newPro)
{

}

template <class DataType>
void PriorityQueue<DataType>::peekAtFront(DataType &data)
{
	if(!isEmpty()){
		
	}
}

template <class DataType>
void PriorityQueue<DataType>::showStructure(char name)
{

}



#endif		// #ifndef CLASS_PRIORITYQUEUE_CPP