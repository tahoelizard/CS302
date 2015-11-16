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
    tableLength = newTableLength;
    if (list.getCapacity() != tableLength){
      if(list.getCapacity() > tableLength)
      {
        list.shrink(list.getCapacity() - tableLength);
      }
      else{
        list.grow(tableLength - list.getCapacity());
      }
    }
    for(int i = 0; i < tableLength; i++)
    {
      list[i] = NULL;
    }
   }

template <typename DataType>
void HashClass<DataType>::setHashLetterCount
       ( 
        int newHashLetterCount
       )
   {
    hashLetterCount = newHashLetterCount;
   }

template <typename DataType>
bool HashClass<DataType>::addItem
       ( 
        const DataType &newData 
       )
   {
    char patientName[ STD_STR_LEN ], medicalCode[ STD_STR_LEN ];
    char patientGender;
    HashNode<DataType> * holdNext;
    int hold;
    DataType holdNew;

    holdNew = newData; 
    hold = holdNew.hash(hashLetterCount, tableLength);

    if (list[hold] == NULL){
      list[hold] = new HashNode<DataType>(holdNew, NULL);
      return true;
    }
    else{
      holdNext = list[hold];
      while(holdNext->nextPtr != NULL){
        holdNext = holdNext->nextPtr;
      }
      holdNext->nextPtr = new HashNode<DataType>(holdNew, NULL);
      return true;
    }
    
    
   }
  
template <typename DataType>
bool HashClass<DataType>::findItem
       ( 
        const DataType &dataItem
       ) const
   {
 DataType holdFind;  
 holdFind = dataItem; 
 int hold;
 HashNode<DataType> * holdNext;
    hold = holdFind.hash(hashLetterCount, tableLength);

    if(list[hold] != NULL)
    {
        holdNext = list[hold];
        while(holdNext != NULL)
        {
          if (holdNext->data.compareTo(holdFind) == 0)
          {
            return true; 
          }
          holdNext = holdNext->nextPtr;
        }
        return false;
      }
    else
    {
      return false;
    }
   }

template <typename DataType>
bool HashClass<DataType>::removeItem
       ( 
        const DataType &dataItem 
       )
   {
    DataType holdFind;  
 holdFind = dataItem; 
 int hold;
 HashNode<DataType> * holdNext;
 HashNode<DataType> * holdNextParent =NULL;
    hold = holdFind.hash(hashLetterCount, tableLength);
char patientName[ STD_STR_LEN ], medicalCode[ STD_STR_LEN ];
    char patientGender;
    if(findItem(dataItem)){
      holdNext = list[hold];
        while(holdNext != NULL)
        {
          if (holdNext->data.compareTo(holdFind) == 0)
          {
            holdNext->data.getAccount( patientName, medicalCode, patientGender );
        cout <<"found  " << patientName ;
            if(holdNextParent == NULL){
              delete holdNext;
              holdNext = NULL;
              return true;
            }
            if(holdNextParent != NULL && holdNext->nextPtr == NULL){
              delete holdNextParent->nextPtr;
              holdNextParent->nextPtr = NULL;
              return true;
            }
            if(holdNextParent != NULL && holdNext->nextPtr != NULL){
              holdNextParent->nextPtr = holdNext->nextPtr;
              delete holdNext;
              holdNext = NULL;
              return true;
            }


            
          }
          holdNextParent = holdNext;
          holdNext = holdNext->nextPtr;
        }
    }
    else{
      return false;
    }
   }

template<typename DataType>
bool HashClass<DataType>::isEmpty
       ( 
        // no parameters
       ) const
   {
    bool flag = true; 
    int index = 0; 
    while(flag && index < tableLength)
    {
      if(list[index] != NULL){
        flag = false;
      }
      index++;
    }

    return flag;
   }
template<typename DataType>
void HashClass<DataType>::clearList()
{
 
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
double HashClass<DataType>::getChainLengthMedian
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
char patientName[ STD_STR_LEN ], medicalCode[ STD_STR_LEN ];
    char patientGender;
HashNode<DataType> * holdNext;

    for(int i = 0; i < tableLength; i++)
    {

      if(list[i] != NULL)
      {
      holdNext = list[i];
      while(holdNext != NULL){

        holdNext->data.getAccount( patientName, medicalCode, patientGender );
        cout <<"[ " << patientName << " ] " ;
      
        holdNext = holdNext->nextPtr;
      }
      cout << endl;

      }
      else
      {
        cout << "NULL" << endl;
      }
    }
    
    
  
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





