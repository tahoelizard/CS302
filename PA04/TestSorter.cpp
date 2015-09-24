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
char LOWZ = 'z';
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

/**
 * @brief Default constructor
 *
 * @details Calls parent class's constructor implicitly 
 *          
 * @param None
 *
 * @note None
 */
TestSorter::TestSorter()
{
  //called through base class
}

/**
 * @brief Default destructor
 *
 * @details Calls parent class's destructor implicitly 
 *          
 * @param None
 *
 * @note None
 */
TestSorter::~TestSorter()
{
  //called through base class
}

/**
 * @brief Get Value
 *
 * @details Calls parent getValue to return value at given index
 *          
 * @param in: Int for index
 * @param in: datetype by reference to store found value
 *
 * @note Used scope resolution operator for clarity
 */
void TestSorter::getValueAt(int value, DateType& valFound )const
{
  SimpleVector::getValueAt( value, valFound );
}

/**
 * @brief Get Size
 *
 * @details Calls parent getSize to return the size
 *          
 * @param None
 *
 * @note Used scope resolution operator for clarity
 */
int TestSorter::getSize()const
{
  return SimpleVector::getSize();
}

/**
 * @brief Add
 *
 * @details Adds given value to the parent vector
 *          
 * @param in: New value to store
 *
 * @note Used scope resolution operator for clarity
 */
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

/**
 * @brief Sort 
 *
 * @details Uses bubble sort to organize vector's values 
 * smallest to largest
 *          
 * @param None
 *
 * @note Throws exception if date isn't valid
 */
bool TestSorter::sort()
{
  int index = 0; 
  int curIndex = 0; 
  DateType lhHold;
  DateType rhHold;

  for(index = 0; index < SimpleVector::getSize(); index++){


  for(curIndex = 0; curIndex < SimpleVector::getSize()-1; curIndex++){
    validDate(curIndex);
    validDate(curIndex+1);
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

/**
 * @brief Date to Number
 *
 * @details Support function to change date characters to int
 *          
 * @param in: const datetype by reference to reference to found values
 *
 * @note None
 */
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

/**
 * @brief Year to Number
 *
 * @details Support function to change year characters to int
 *          
 * @param in: const datetype by reference to reference to found values
 *
 * @note None
 */
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

/**
 * @brief Quantify Month 
 *
 * @details Support function to change month to int
 *          
 * @param in: const datetype by reference to reference to found values
 *
 * @note returns 0-12 where 12 is considered inValid
 */
int TestSorter::quantifyMonth(const DateType &check)
{
  char dummy[MONTHLEN]; 
  int findIndex = 0;
  bool match = false;
  int index;

  while (check.date[findIndex] != ' ')
  {
    findIndex++; 
  }
  findIndex++; 

  //make dummy 
  for(index = 0; index < MONTHLEN; index++)
  {
    dummy[index] = check.date[findIndex+index];
  }
  toUpper(dummy);

  index = 0;

  while (!match && index < MONTHLIMIT)
  {
    match = isMonth(dummy, index);
    index++;
  }

  return index; 
}

/**
 * @brief Is Month
 *
 * @details Support function to check if given string is a month
 *          
 * @param in: character pointer to given string
 * @param in: integer to refer to global constant array of months
 *
 * @note None
 */
bool TestSorter::isMonth(char* source, int monthIndex){
  bool check = false;

  if(source[0] == MONTHS[monthIndex][0]
    && source[1] == MONTHS[monthIndex][1]
    && source[2] == MONTHS[monthIndex][2])
  {
    check = true; 
  }
  return check; 
}

/**
 * @brief To Upper
 *
 * @details changes string all to upper case
 *          
 * @param in: character pointer to given string
 *
 * @note None
 */
void TestSorter::toUpper(char* needsUp)
{
  for(int i = 0; i < MONTHLEN; i++){
    if(needsUp[i] <= LOWZ && needsUp[i] >= LOWA){
      needsUp[i] =  needsUp[i]  - LOWA + UPA; 
    }  
  }
}

/**
 * @brief Swap Dates
 *
 * @details Facilitates sort by swapping the position of the two given values
 *          
 * @param in: integer of first index to swap
 * @param in: integer of second index to swap
 *
 * @note None
 */
void TestSorter::swapDates(int firstIndex, int secondIndex)
{
  DateType holdFirst;
  DateType holdSecond; 

  getValueAt( firstIndex, holdFirst );
  getValueAt( secondIndex, holdSecond ); 
  setValueAt(firstIndex, holdSecond);
  setValueAt(secondIndex, holdFirst);
}

/**
 * @brief Compare To
 *
 * @details Constructs vector capacity to default and vector size to zero
 *          creates default size data array
 *          
 * @param in: const left hand datetype by reference to reference to found values
 * @param in: const right hand datetype by reference to reference to found values
 *
 * @note Uses many if statements to ensure every case is covered 
 */
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
      else
      {
        isGreater = 0;
      }
    }
  }
  return isGreater;
}

/**
 * @brief Valid Date
 *
 * @details Makes sure that the given date is within the global constant restaints
 *          
 * @param in: int of index to check 
 *
 * @note Throws exception if the date is invalid. Called by sort function
 */
bool TestSorter::validDate(int index) throw ( logic_error ){
  DateType hold;
  getValueAt(index,hold);
  if(quantifyMonth(hold) != MONTHLIMIT &&
    yearToNumber(hold) > YEARMIN &&
    yearToNumber(hold) < YEARMAX &&
    dateToNumber(hold) > DATEMIN && 
    dateToNumber(hold) < DATEMAX)
  {
    return true;
  }
  else{
    throw logic_error("invalid date attempted to sort");
  }
}

#endif // ifndef TESTSORTER_CPP