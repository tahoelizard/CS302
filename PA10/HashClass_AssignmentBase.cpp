// Program Information ////////////////////////////////////////////////////////
/**
 * @file HashClass.cpp
 *
 * @brief Implementation file for HashClass class
 * 
 * @details Implements the constructor method of the HashClass class
 *
 * @author Michael Leverington
 *
 * @version 1.00 (06 November 2015)
 *
 * @Note Requires HashClass.h, SimpleVector.cpp
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef HASH_CLASS_CPP
#define HASH_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "HashClass.h"
#include "SimpleVector.cpp"
#include <new>

using namespace std;

// Class Implementation  //////////////////////////////////////////////////////

template<typename DataType>
HashNode<DataType>::HashNode
       ( 
        const DataType &newData, HashNode *next 
       )
     : data( newData ), nextPtr( next )
   {
    // no parameters
   }

template<typename DataType>
HashClass<DataType>::HashClass
       (
        // no parameters
       )
     : tableLength( 0 ), hashLetterCount( DEFAULT_HASH_LETTER_COUNT ), list()
   {
    // data placed in initializers
   }
           
template<typename DataType>
HashClass<DataType>::HashClass
       ( 
        const HashClass<DataType> &copied 
       )
     : tableLength( copied.tableLength ), 
       hashLetterCount( copied.hashLetterCount ), list( copied.tableLength )
   {
    // to be implemented
   }

template<typename DataType>
HashClass<DataType>::~HashClass
       (
        // no parameters
       )
   {
    // to be implemented
   }

template <typename DataType>
const HashClass<DataType>& HashClass<DataType>:: operator = 
                                              ( const HashClass &rhHashTable )
   {
    // to be implemented

    return *this;
   }

template <typename DataType>
void HashClass<DataType>::setTableLength
       ( 
        int newTableLength
       )
   {
    // to be implemented
   }

template <typename DataType>
void HashClass<DataType>::setHashLetterCount
       ( 
        int newHashLetterCount
       )
   {
    // to be implemented
   }

template <typename DataType>
bool HashClass<DataType>::addItem
       ( 
        const DataType &newData 
       )
   {
    // to be implemented

    return false;
   }

template <typename DataType>
bool HashClass<DataType>::findItem
       ( 
        const DataType &dataItem
       ) const
   {
    // to be implemented

    return false;
   }

template <typename DataType>
bool HashClass<DataType>::removeItem
       ( 
        const DataType &dataItem 
       )
   {
    // to be implemented

    return false;
   }

template<typename DataType>
bool HashClass<DataType>::isEmpty
       ( 
        // no parameters
       ) const
   {
    // to be implemented

    return false;
   }

template<typename DataType>
double HashClass<DataType>::getChainLengthMean
       ( 
        // no parameters
       ) const
   {
    // to be implemented

    return 0.0;
   }

template<typename DataType>
double HashClass<DataType>::getChainLengthMode
       ( 
        // no parameters
       ) const
   {
    // to be implemented

    return 0.0;
   }

template<typename DataType>
void HashClass<DataType>::showStructure
       (
       ) const
   {
    // to be implemented
   }

template<typename DataType>
int HashClass<DataType>::hash
       (
        const DataType &dataItem
       )
   {
    DataType tempData( dataItem );

    return tempData.hash( hashLetterCount, tableLength );
   }

#endif	// define HASH_CLASS_CPP





