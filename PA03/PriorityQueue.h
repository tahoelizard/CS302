// Program Information ////////////////////////////////////////////////////////
/**
 * @file SimpleVector.h
 *
 * @brief Definition file for SimpleVector class
 * 
 * @author Michael Leverington
 * 
 * @details Specifies all member methods of the SimpleVector class
 *
 * @version 1.00 (30 August 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef CLASS_PRIORITYQUEUE_H
#define CLASS_PRIORITYQUEUE_H

// Header files ///////////////////////////////////////////////////////////////

#include <stdexcept>

using namespace std;

// Class constants /////////////////////////////////////////////////////////////

template <class DataType>
class PriorityQueue
   {
    public:
    // constructors
    PriorityQueue();
    bool isEmpty();
    void dequeue(DataType);
    void enqueue (int,  char* newPro);
    void peekAtFront(DataType&);
    void showStructure(char);
    // destructor
    ~PriorityQueue( );

  private:
  	DataType* head; 
  	DataType* rear;
   };

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef CLASS_PRIORITYQUEUE_H