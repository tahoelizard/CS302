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
	if (head != NULL){
		//delete head;
		head = NULL;
	}
}

template <class DataType>
const bool PriorityQueue<DataType>::isEmpty()
{

    if(head == NULL || head->getSize() == 0){
    	return true;
    }
    else{
    	return false;

    }
}
template <class DataType>
    PriorityQueue<DataType>& PriorityQueue<DataType>::operator = (PriorityQueue<DataType> rhPQueue )
    {
    	if(head == NULL ){
    		head = new SimpleVector<DataType>;
    	}
    	*head = (*rhPQueue.head);
    	    	return *this;
    }

template <class DataType>
void PriorityQueue<DataType>::dequeue(DataType& data)
{
	if(!isEmpty())
	{
		data.priority = (*head)[0].priority;
		strcpy(data.process, (*head)[0].process);
		for(int i = 0; i < head->getSize()-1; i++)
		{
			(*head)[i].priority = (*head)[i+1].priority;
			strcpy( (*head)[i].process, (*head)[i+1].process );
		}
		head->decrementSize();

		if( head->getSize() < (.25*head->getCapacity()))
		{
			head->shrink(head->getCapacity()/2);
		}
	}

}

template <class DataType>
void PriorityQueue<DataType>::enqueue (int newPri, char* newPro)
{
	int placeHolder;
	int counter = 0;
		if(head == NULL)
		{
			//cout << "totally new" << endl;
	    	head = new SimpleVector<DataType>; 
	    }

	    if(head->getCapacity() == 0)
	    {
	    	//cout << "Was empty" << endl;
	    	head->grow(1);
			(*head)[0].priority = newPri;
	    	strcpy((*head)[0].process, newPro);
	    	head->incrementSize();
	    }
    	
    

else{
	//cout << "same old" << endl;
	 	//give wiggle room 
    if(head->getSize() >= head->getCapacity())
    {
    	head->grow(head->getCapacity());
    }

	placeHolder = head->getSize(); 
	//search for place
    while((*head)[counter].priority <= newPri && counter < head->getSize())
    {
   		counter++;
    }

 	head->incrementSize();

 	//shuffle down
 	while(placeHolder > counter)
 	{
 		strcpy((*head)[placeHolder].process, (*head)[placeHolder-1].process);
		(*head)[placeHolder].priority = (*head)[placeHolder-1].priority;
 		placeHolder--;
 	}

 	//put new value in
 	(*head)[counter].priority = newPri;
    strcpy((*head)[counter].process, newPro);
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
		cout << "  List " << name << " (" << head->getSize() << "/" <<head->getCapacity() << "): ";
		for (int i = 0; i < head->getSize(); i++){
			cout << "[";
			cout << (*head)[i].priority << "/";
			cout << (*head)[i].process << "] ";
			
		}
		cout << endl;
	}
	else{
		cout << "  Empty list" << endl;
	}
}




#endif		// #ifndef CLASS_PRIORITYQUEUE_CPP