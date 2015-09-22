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
  DateType lhHold;
  DateType rhHold;

  for(index = 0; index < SimpleVector::getSize(); index++){


  for(curIndex = 0; curIndex < SimpleVector::getSize()-1; curIndex++){

    getValueAt(curIndex, lhHold); 
    getValueAt(curIndex+1, rhHold); 
    if(compareTo(lhHold, rhHold) > 0) 
      {
        swapDates(curIndex, curIndex+1);
      }
    }
  }
  return true;
}



int TestSorter::dateToNumber(const DateType &check)
{
    int result;
    result = check.date[0]; 
    result = result - 48;
    if(check.date[1] != ' ')
    {
      result = result * 10;
      result = result + (check.date[1] - 48);
   }
    return result;
}

int TestSorter::yearToNumber(const DateType &check){
   DateType hold;
    int result;
    int findIndex = 0;
    while (check.date[findIndex] != ' ')
    { 
      findIndex++; 
    }
    findIndex++; 
    while (check.date[findIndex] != ' ')
    { 
      findIndex++; 
    }
    findIndex++; 

    result = (check.date[findIndex]-48) *1000;
    result = result + ((check.date[findIndex+1]-48) * 100);
    result = result + ((check.date[findIndex+2]-48) * 10);
    result = result + (check.date[findIndex+3]-48);

    return result;
}

int TestSorter::quantifyMonth(const DateType &check)
{
  int result = 0;
  int findIndex = 0;
  while (check.date[findIndex] != ' ')
  {
    findIndex++; 
  }
  findIndex++; 

  switch ( check.date[findIndex] ) {
  case 'j': case 'J':
    if (check.date[findIndex+1] == 'a' || check.date[findIndex+1] == 'A'){
      result = 1;
    }
    else if(check.date[findIndex+1] == 'u' || check.date[findIndex+1] == 'U'){
      if(check.date[findIndex+2] == 'n' || check.date[findIndex+2] == 'N'){
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
    if (check.date[findIndex+2] == 'r' || check.date[findIndex+2] == 'R'){
      result = 3;
    }
    else{
      result = 5;
    }
  break;
  case 'a': case 'A':
      if (check.date[findIndex+1] == 'p' || check.date[findIndex+1] == 'P'){
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

int TestSorter::compareTo( const DateType &lhObject, const DateType &rhObject){ 
  int isGreater;
  if(yearToNumber(lhObject) > yearToNumber(rhObject))
  {
    isGreater = 1;
  }
  else if(yearToNumber(lhObject) < yearToNumber(rhObject))
  {
    isGreater = -1;
  }
  else
  {
    if(quantifyMonth(lhObject)> quantifyMonth(rhObject))
    {
      isGreater = 1;
    }
    else if (quantifyMonth(lhObject) < quantifyMonth(rhObject))
    {
      isGreater = -1;
    }
    else
    {
      if(dateToNumber(lhObject)> dateToNumber(rhObject))
      {
        isGreater = 1;
      }
      else if (dateToNumber(lhObject)< dateToNumber(rhObject))
      {
        isGreater = -1;
      }
      else{
        isGreater = 0;
      }
    }
  }
  return isGreater;
}

bool TestSorter::validDate(int index){
  DateType hold;
  getValueAt(index,hold);
  if(quantifyMonth(hold) != 0 &&
    yearToNumber(hold) > 1 &&
    yearToNumber(hold) < 3000 &&
    dateToNumber(hold) > 0 && 
    dateToNumber(hold) <32)
  {
    return true;
  }
  else{
    return false; 
  }

}

#endif // ifndef TESTSORTER_CPP

