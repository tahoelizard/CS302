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
  SimpleVector::setValueAt( getSize(), newDate );
  SimpleVector::incrementSize();
  if(SimpleVector::getSize() == SimpleVector::getCapacity())
  {
    SimpleVector::grow(getSize());
  }
}












bool TestSorter::sort()
{
  int index = 1; 
  int firstDate, secondDate; 
  int firstMonth, secondMonth;
  swapDates(0, 1);

  while(index < SimpleVector::getSize()){

    firstDate  = toNumber(index);
    firstMonth = quantifyMonth(index);
    cout << firstDate << endl; 
    index++;
    
  }
  return true;
}
























int TestSorter::toNumber(int index)
{
    DateType hold;
    int result;
    getValueAt( index, hold );
    result = hold.date[0]; 
    result = result - 48;
    if(hold.date[1] != ' ')
    {
      result = result * 10;
      result = result + (hold.date[1] - 48);
   }
    return result;
}

int TestSorter::quantifyMonth(int index)
{
  int result = 0;
  int findIndex = 0;
  DateType hold;
  getValueAt( index, hold );
  while (hold.date[findIndex] != ' ')
  {
    findIndex++; 
  }
  findIndex++; 

  switch ( hold.date[findIndex] ) {
  case 'j': case 'J':
    if (hold.date[findIndex+1] == 'a' || hold.date[findIndex+1] == 'A'){
      result = 1;
    }
    else if(hold.date[findIndex+1] == 'u' || hold.date[findIndex+1] == 'U'){
      if(hold.date[findIndex+2] == 'n' || hold.date[findIndex+2] == 'N'){
        result = 6;
      }
      else{
        result = 7;
      }
    }
  break;
  case 'f':
    result = 2; 
  break;
  case 'm':
    if (hold.date[findIndex+2] == 'r' || hold.date[findIndex+2] == 'R'){
      result = 3;
    }
    else{
      result = 5;
    }
  break;
  case 'a':
      if (hold.date[findIndex+1] == 'p' || hold.date[findIndex+1] == 'P'){
      result = 4;
    }
    else{
      result = 8;
    }
  break;
  case 's':
    result = 9;
  break;
  case 'o':
    result = 10;
  break;
  case 'n':
    result = 11;
  break;
  case 'd':
    result = 12;
  break;
default:
    result = 0;
  break;
}

  return result;
}

void TestSorter::swapDates(int firstIndex, int secondIndex){
  DateType holdFirst;
  DateType holdSecond; 
  getValueAt( firstIndex, holdFirst );
  getValueAt( secondIndex, holdSecond ); 
  setValueAt(firstIndex, holdSecond);
  setValueAt(secondIndex, holdFirst);
}

#endif // ifndef TESTSORTER_CPP

