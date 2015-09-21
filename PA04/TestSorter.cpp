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
  int index = 0; 
  int curIndex = 0; 

  for(index = 0; index < SimpleVector::getSize(); index++){


  for(curIndex = 0; curIndex < SimpleVector::getSize()-1; curIndex++){

    if(compareTo(curIndex, curIndex+1))
      {
        swapDates(curIndex, curIndex+1);
        //cout << "swapped " <<  quantifyMonth(curIndex) << " with " <<  quantifyMonth(curIndex+1) << endl;
      }
    }
  }
  return true;
}



int TestSorter::dateToNumber(int index)
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

int TestSorter::yearToNumber(int index){
   DateType hold;
    int result;
    int findIndex = 0;
    getValueAt( index, hold );
    while (hold.date[findIndex] != ' ')
    { 
      findIndex++; 
    }
    findIndex++; 
    while (hold.date[findIndex] != ' ')
    { 
      findIndex++; 
    }
    findIndex++; 

    result = (hold.date[findIndex]-48) *1000;
    result = result + ((hold.date[findIndex+1]-48) * 100);
    result = result + ((hold.date[findIndex+2]-48) * 10);
    result = result + (hold.date[findIndex+3]-48);

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
  case 'f': case 'F':
    result = 2; 
  break;
  case 'm': case 'M':
    if (hold.date[findIndex+2] == 'r' || hold.date[findIndex+2] == 'R'){
      result = 3;
    }
    else{
      result = 5;
    }
  break;
  case 'a': case 'A':
      if (hold.date[findIndex+1] == 'p' || hold.date[findIndex+1] == 'P'){
      result = 4;
    }
    else{
      result = 8;
    }
  break;
  case 's': case 'S':
    result = 9;
  break;
  case 'o': case 'O':
    result = 10;
  break;
  case 'n': case 'N':
    result = 11;
  break;
  case 'd': case 'D':
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

bool TestSorter::compareTo(int firstIndex, int secondIndex){
  bool isGreater;
  if(yearToNumber(firstIndex) > yearToNumber(secondIndex))
  {
    isGreater = true;
  }
  else if(yearToNumber(firstIndex) < yearToNumber(secondIndex))
  {
    isGreater = false;
  }
  else
  {
    if(quantifyMonth(firstIndex)> quantifyMonth(secondIndex))
    {
      isGreater = true;
    }
    else if (quantifyMonth(firstIndex) < quantifyMonth(secondIndex))
    {
      isGreater = false;
    }
    else
    {
      if(dateToNumber(firstIndex)> dateToNumber(secondIndex))
      {
        isGreater = true;
      }
      else
      {
        isGreater = false;
      }
    }
  }
  return isGreater;
}

bool TestSorter::validDate(int index){
  if(quantifyMonth(index) != 0 &&
    yearToNumber(index) > 1 &&
    yearToNumber(index) < 3000 &&
    dateToNumber(index) > 0 && 
    dateToNumber(index) <32)
  {
    return true;
  }
  else{
    return false; 
  }

}

#endif // ifndef TESTSORTER_CPP

