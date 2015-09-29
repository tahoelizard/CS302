// Program Information ////////////////////////////////////////////////////////
/**
 * @file MrgSorter.h
 *
 * @brief Definition file for MrgSorter class using insertion sort,
 *        derived from SorterClass
 * 
 * @author Michael Leverington
 * 
 * @details Specifies all member methods of the MrgSorter Class
 *
 * @version 1.00 (11 September 2015)
 *
 * @Note Requires DateType.h, SorterClass.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef MRGSORTERCLASS_H
#define MRGSORTERCLASS_H

// Header files ///////////////////////////////////////////////////////////////

#include "DateType.h"
#include "SorterClass.h"

// Class definition  //////////////////////////////////////////////////////////

class MrgSorter: public SorterClass<DateType>
  {
    public: 

      // local constants
      static const char NULL_CHAR = '\0';
      static const char SPACE = ' ';
      static const int MONTH_NAME_WIDTH = 3;
      static const int MAX_YEAR_ALLOWED = 3000;

      // Constructors
      MrgSorter();
      MrgSorter( int initialCapacity ); 
      MrgSorter( const SorterClass<DateType> &copiedSorter );

      // Destructor
      virtual ~MrgSorter();

      // Virtual Functions Defined
       
         // Compare Two elements
         virtual int compareTo( const DateType &lhObject,
                                                  const DateType &rhObject );  

         // Sort List Using compareTo()
         virtual bool sort(); 

    private:

      // sort success flag
      bool sortSuccess;

      // special swap method for dates
      void swap( int one, int other ); 

      // make usable values for testing
      int makeDate( const char *str );
      int makeMonth( const char *str );
      int makeYear( const char *str );
      int strToInt( int startIndex, const char *str );
      int findSpace( int startIndex, const char *str );
      bool compMonth( const char *testStr, 
                                      int startIndex, const char *testMonth );
      char toUpper( char testChar );
      bool isDigit( char testDigit );
      bool isLeapYear( int year );
      void mergesort(int low, int high);
      void merge(int low, int high, int mid);
  };

  #endif // ifndef MRGSORTERCLASS_H


