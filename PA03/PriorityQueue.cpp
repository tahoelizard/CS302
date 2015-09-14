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
 #include <iostream>
  using namespace std;


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
}

// destructor
template <class DataType>
PriorityQueue<DataType>::~PriorityQueue( )
{
	//delete head; broken
	head = NULL;
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
void PriorityQueue<DataType>::dequeue(DataType& data)
{



	if(!isEmpty()){

		data.priority = (*head)[0].priority;
		strcpy(data.process, (*head)[0].process);

		for(int i = 0; i < head->getSize(); i++){
			(*head)[i].priority = (*head)[i+1].priority;
			strcpy( (*head)[i].process, (*head)[i+1].process );
		}

		head->decrementSize();
	}
	

}

template <class DataType>
void PriorityQueue<DataType>::enqueue (int newPri, char* newPro)
{
		int counter = 0;
	if(isEmpty()){
    	head = new SimpleVector<DataType>; 
    }

   (*head)[head->getSize()].priority = newPri;

   strcpy((*head)[head->getSize()].process, newPro);


    head->incrementSize();

    if(head->getSize() >= head->getCapacity()){
    	head->grow(1);
    }
}

template <class DataType>
void PriorityQueue<DataType>::peekAtFront(DataType &data)
{
	if(!isEmpty()){

	}
	else{
		//throw exception 
	}
}

template <class DataType>
void PriorityQueue<DataType>::showStructure(char name)
{
	if(!isEmpty()){
		cout << name << " (" << head->getSize() << "/" <<head->getCapacity() << "): ";
		for (int i = 0; i < head->getSize(); i++){
			cout << "[";
			cout << (*head)[i].priority << "/";
			cout << (*head)[i].process << "] ";
			
		}
		cout << endl;
	}
	else{
		cout << "Empty list" << endl;
	}
}




#endif		// #ifndef CLASS_PRIORITYQUEUE_CPP