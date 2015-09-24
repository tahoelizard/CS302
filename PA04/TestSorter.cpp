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

// Global constant definitioans  //////////////////////////////////////////////
char UPA = 'A';
char LOWA = 'a';
int MONTHLEN = 3; 
char MONTHS[12][4] = {"JAN","FEB","MAR","APR","MAY","JUN",
                      "JUL","AUG","SEP","OCT","NOV","DEC"};
int MONTHLIMIT = 13; 
int DATEMAX = 32; 
int DATEMIN = 0;
int YEARMIN =1;
int YEARMAX = 3000;
char ZEROCHAR = '0';
int YEARLEN = 4;


TestSorter::TestSorter()
{
  //called through base class
}

TestSorter::~TestSorter()
{
  //called through base class
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
  bool returnVal = true;

  SimpleVector::setValueAt( getSize(), newDate );
  SimpleVector::incrementSize();

  if(SimpleVector::getSize() == SimpleVector::getCapacity())
  {
    SimpleVector::grow(getSize());
  }
  return returnVal;
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
  char dummy[MONTHLEN]; 
  int findIndex = 0;
  bool match = false;
  int i;

  while (check.date[findIndex] != ' ')
  {
    findIndex++; 
  }
  findIndex++; 

  //make dummy 
  for(int i = 0; i < 3; i++)
  {
    dummy[i] = check.date[findIndex+i];
  }
  toUpper(dummy);

  i = 0;

  while (!match && i < MONTHLIMIT)
  {
    match = isMonth(dummy, i);
    if (match){
      //cout << "found month!" << endl;
    }
    else{
      //cout << "not month!" << endl;
    }
    
    i++;
  }

  return i; 
}

bool TestSorter::isMonth(char* source, int monthIndex){
  bool check = false;
  int index = 0; 
  if(source[0] == MONTHS[monthIndex][0]
    && source[1] == MONTHS[monthIndex][1]
    && source[2] == MONTHS[monthIndex][2])
  {
    check = true; 
  }
  return check; 
}

void TestSorter::toUpper(char* needsUp)
{
  for(int i = 0; i < MONTHLEN; i++){
    if(needsUp[i] <= 'z' && needsUp[i] >= LOWA){
      needsUp[i] =  needsUp[i]  - LOWA + UPA; 
    }  
  }
}

void TestSorter::swapDates(int firstIndex, int secondIndex)
{
  DateType holdFirst;
  DateType holdSecond; 
  //cout << "swapping" << endl;
  getValueAt( firstIndex, holdFirst );
  getValueAt( secondIndex, holdSecond ); 
  setValueAt(firstIndex, holdSecond);
  setValueAt(secondIndex, holdFirst);
}

int TestSorter::compareTo( const DateType &lhObject, const DateType &rhObject){ 
  int isGreater;
  //cout << "compare calling" <<endl;
  //cout << yearToNumber(lhObject)  << " and " << yearToNumber(rhObject) << endl;
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
      //cout << "comparing "<< dateToNumber(lhObject) << " to " << dateToNumber(rhObject) << endl;
      if(dateToNumber(lhObject)> dateToNumber(rhObject))
      {
        //cout << dateToNumber(lhObject) << " is bigger" << endl;
        isGreater = 1;
      }
      else if (dateToNumber(lhObject)< dateToNumber(rhObject))
      {
        //cout << dateToNumber(rhObject) << " is bigger" << endl;
        isGreater = -1;
      }
      else
      {
        //cout << "they equal" << endl; 
        isGreater = 0;
      }
    }
  }
  return isGreater;
}

bool TestSorter::validDate(int index)
{
  DateType hold;
  getValueAt(index,hold);
  //cout << "validate calling" <<endl;
  if(quantifyMonth(hold) != DATEMIN &&
    yearToNumber(hold) > YEARMIN &&
    yearToNumber(hold) < YEARMAX &&
    dateToNumber(hold) > DATEMIN && 
    dateToNumber(hold) <DATEMAX)
  {
    return true;
  }
  else
  {
    return false; 
  }
}

#endif // ifndef TESTSORTER_CPP

