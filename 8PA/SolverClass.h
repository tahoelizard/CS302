// Program Information ////////////////////////////////////////////////////////
/**
 * @file SolverClass.h
 *
 * @brief Definition file for class that attempts to locate smaller
 *        inside a larger container rectangle
 * 
 * @author Michael Leverington
 * 
 * @details Specifies all member methods of the Solver class
 *
 * @version 1.00 (18 October 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef SOLVERCLASS_H
#define SOLVERCLASS_H

// Header files ///////////////////////////////////////////////////////////////

#include <stdexcept>
 #include "Rectangle.h"
 #include "SimpleVector.h"
 #include "SimpleMatrix.h"

using namespace std;

// Class definition  //////////////////////////////////////////////////////////

class SolverClass
   {
    public:

       // constructor
       SolverClass();

       // destructor
       ~SolverClass( );

       // modifiers
       bool findSolution();
       bool setContainerRectangle( int height, int width );
       bool addInsideRectangle( int height, int width );
       void setDisplayFlag( bool setFlag );
       void displayField() const;
       bool findNextLocation(int& foundRow, int& foundColumn);
       bool addRectToMatrix(Rectangle input);

   private:
      SimpleMatrix<char>* container;
      SimpleVector<Rectangle*> inputList;
   };

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef SOLVERCLASS_H


