// Program Information ////////////////////////////////////////////////////////
/**
 * @file TestSorter.cpp
 * 
 * @brief Implementation file for TestSorter
 * 
 * @author Michael Leverington
 *
 * @details Implements all member methods of the TestSorter
 *
 * @version 1.00 (11 September 2015)
 *
 * @Note Requires SorterClass.h, SimpleVector.h, TestSorter.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef TESTSORTER_CPP
#define TESTSORTER_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "SorterClass.h"
#include "SimpleVector.h"
 #include "TestSorter.h"
  #include "DateType.h"
   #include "SimpleVector.cpp"
 #include <iostream>

TestSorter::TestSorter()
{
  //wut
}

TestSorter::~TestSorter()
{
  //implied?
}

void TestSorter::getValueAt(int value, DateType& valFound )const
{
  SimpleVector::getValueAt( value, valFound );
}

 int TestSorter::getSize()const
 {
    return SimpleVector::getSize();
 }

bool TestSorter::add(char* newDate)
{
  int index = 0; 
  SimpleVector::setValueAt( getSize(), newDate );
  SimpleVector::incrementSize();
  if(SimpleVector::getSize() == SimpleVector::getCapacity())
  {
    SimpleVector::grow(getSize());
  }
}

bool TestSorter::sort()
{
  int index = 0; 
  int firstDate, secondDate; 


  while(index < SimpleVector::getSize()){
    //turn first two into nums. should be toNum function 
    
    cout << "comparing " << " to " << endl; 
    index++;
  }
  return true;
}

int TestSorter::toNumber(int index)
{
    DateType hold;
    int result = 2;
    getValueAt( index, hold );
    result = hold.date[0]; 
    result = result - 48;
      if(hold.date[1] != ' ')
    {
      result = result *10; 

    }
}

#endif // ifndef TESTSORTER_CPP

