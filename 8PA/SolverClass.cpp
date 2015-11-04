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
	return findSolutionHelper(0);
}

bool SolverClass::findSolutionHelper(int indexToTry)
{
	/*
try 
if succes
	try next
	if success
		return true
	else
		rotate self 
		try
		if succes
			try next
			if success
				return true
			else
				remove self
				try next
				if success
					insert self
					if success
						return true
					else
						rotate self 
						try
				


*/
	if(addRectToMatrix(*inputList[indexToTry]))
	{
		if(indexToTry == inputList.getSize()){
			return true;
		}
		else{
			if(findSolutionHelper(indexToTry+1))
			{
				return true; 
			}
			else
			{
				removeCharFromMatrix(inputList[indexToTry]->getIDLetter());
				inputList[indexToTry]->setUsedState(false);
				inputList[indexToTry]->rotate();
				if(addRectToMatrix(*inputList[indexToTry]))
				{
					if(findSolutionHelper(indexToTry+1))
					{
						return true; 
					}
					else
					{
						//remove self
						removeCharFromMatrix(inputList[indexToTry]->getIDLetter());
						inputList[indexToTry]->setUsedState(false);
					}
				}
				else
				{
					//remove self
					removeCharFromMatrix(inputList[indexToTry]->getIDLetter());
					inputList[indexToTry]->setUsedState(false);
					//try next
					if(findSolutionHelper(indexToTry+1))
					{
						if(addRectToMatrix(*inputList[indexToTry]))
						{
							return true;
						}
						else
						{
							if(!addRectToMatrix(*inputList[indexToTry]))
							{
								removeCharFromMatrix(inputList[indexToTry]->getIDLetter());
					inputList[indexToTry]->setUsedState(false);
								inputList[indexToTry]->rotate();
								if(addRectToMatrix(*inputList[indexToTry]))
								{
									return true;
								}
								else
								{
									return false;
								}
							}
							else
							{
								return true;
							}
						}

					}
				
					else
					{
						return false;
					}
				}
			}
		}
	}

}

bool SolverClass::addRectToMatrix(Rectangle input)
{
	int rowBound = container->getNumRows();
	int colBound = container->getNumCols();
	int row;
	int column;
	int rowHold;
	int columnHold;
	char hold;
	if(!input.isUsed()){
		if(findNextLocation(row, column)){
			rowHold = row;
			columnHold = column;
			for(int i= 0; i <input.getWidth();i++){
				for(int j= 0; j <input.getHeight();j++){
					if(row < rowBound && column < colBound)
					{
						container->getValueAt(row,column,hold);
					 	if( hold == 'O'){
							container->setValueAt(row,column,input.getIDLetter());
							row++;
						}
					}
					else{
						removeCharFromMatrix(input.getIDLetter());
						return false;
					}
				}
				column++;
				row = rowHold;
			}
		}
		input.setUsedState(true);
	}
	else{
		return false;
	}
	displayField();
	cout << endl;
	return true; 
}

void SolverClass::removeCharFromMatrix(char scrubChar)
{
	char hold;

	for(int i = 0; i < container->getNumRows(); i++)
	{
		for(int j = 0; j < container->getNumCols(); j++)
		{
			container->getValueAt(i,j, hold);
			if (hold == scrubChar)
			{
				container->setValueAt(i,j, 'O');
			}
		}
	}
}

bool SolverClass::setContainerRectangle( int height, int width )
{
	container = new SimpleMatrix<char> (width, height,  'O');
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