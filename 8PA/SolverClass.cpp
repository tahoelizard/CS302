// Program Information ////////////////////////////////////////////////////////
/**
 * @file SolverClass.cpp
 *
 * @brief Implementation file for class that attempts to locate smaller
 *        inside a larger container rectangle
 * 
 * @author Elizabeth Johnson
 * 
 * @details Specifies all member methods of the Solver class
 *
 * @version 1.00 (18 October 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef SOLVERCLASS_CPP
#define SOLVERCLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include <stdexcept>
 #include "SolverClass.h"
  #include "SimpleMatrix.cpp"
 #include <iostream>

using namespace std;

// constructor
SolverClass::SolverClass()
{

}

// destructor
SolverClass::~SolverClass( )
{

}

// modifiers
bool SolverClass::findSolution()
{
	cout << (*inputList[0]).getIDLetter() << endl;
addRectToMatrix(*inputList[0]);
addRectToMatrix(*inputList[1]);
addRectToMatrix(*inputList[2]);
addRectToMatrix(*inputList[3]);


}

bool SolverClass::addRectToMatrix(Rectangle input)
{
	int row;
	int column;
	int rowHold;
	int columnHold;
	if(!input.isUsed()){
		if(findNextLocation(row, column)){

			rowHold = row;
			columnHold = column;
			for(int i= 0; i <input.getWidth();i++){
				for(int j= 0; j <input.getHeight();j++){
					container->setValueAt(row,column,input.getIDLetter());
					row++;
				}
				column++;
				row = rowHold;
			}
		}
		
	}
}


bool SolverClass::setContainerRectangle( int height, int width )
{
	container = new SimpleMatrix<char> (height, width, 'O');
}
bool SolverClass::addInsideRectangle( int height, int width )
{
	char hold;
	if (inputList.getSize() > 14){
		hold = inputList.getSize()+1 + 'A';
	}
	else{
		hold = inputList.getSize() + 'A';
	}

	inputList[inputList.getSize()] = new Rectangle (height, width, hold);
	inputList.incrementSize();
}
void SolverClass::setDisplayFlag( bool setFlag )
{

}
void SolverClass::displayField() const
{
	char hold;
	for(int j = 0; j < container->getNumCols(); j++)
	{
		for(int i = 0; i < container->getNumRows(); i++)
		{
			container->getValueAt(i,j, hold);
			cout << hold << ' ';		
		}
		cout << endl;
	}
}

bool SolverClass::findNextLocation(int& foundRow, int& foundColumn)
{
	bool flag = false;
	char hold;

	for(int i = 0; i < container->getNumRows(); i++)
	{
		for(int j = 0; j < container->getNumCols(); j++)
		{
			container->getValueAt(i,j, hold);
			if (hold== 'O')
			{
				flag = true;
				foundRow = i;
				foundColumn = j; 
				return flag;
			}
		}
	}
	return flag;
}

// Terminating precompiler directives  ////////////////////////////////////////

#endif		// #ifndef SOLVERCLASS_CPP