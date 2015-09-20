// Program Information ////////////////////////////////////////////////////////
/**
 * @file TestSorter.h
 *
 * @brief Definition file for TestSorter class
 * 
 * @author Elizabeth Johnson
 * 
 * @details Specifies all member methods of the TestSorter
 *
 * @version 1.00 (11 September 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef TESTSORTER_H
#define TESTSORTER_H
   #include "DateType.h"
 #include "SimpleVector.h"
 #include "SorterClass.h"
  #include "SimpleVector.cpp"


// Header files ///////////////////////////////////////////////////////////////

using namespace std;

// Class definition  //////////////////////////////////////////////////////////

class TestSorter: public SimpleVector<DateType>
   {
    public:
      TestSorter();
      ~TestSorter();
      void getValueAt(int value, DateType& valFound ) const;
      int getSize () const;
      bool add(char* newDate);
      bool sort();

    private:
      int dateToNumber(int index);
      int yearToNumber(int index);
      int quantifyMonth(int index);
      void swapDates(int firstIndex, int secondIndex);
      bool compareTo(int firstIndex, int secondIndex);

   };

#endif // ifndef TESTSORTER_H
