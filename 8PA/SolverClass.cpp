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
	bool flag; 
	flag = findSolutionHelper(0);
	if (!flag){
		removeAllFromMatrix();
	}
}

bool SolverClass::findSolutionHelper(int indexToTry)
{
	//cout << "trying " << inputList[indexToTry]->getIDLetter() << endl;
	//check if at end of list
	if(indexToTry != inputList.getSize() && !(*inputList[indexToTry]).isUsed())
	{
	//try
		
		if(addRectToMatrix(*inputList[indexToTry]))
		{
		//if success:
			//try next
			if(findSolutionHelper(indexToTry+1))
			{
				//if success:
					//return true
				//cout << "hear" << endl;
				return true;
			}
				//if fail:
			else{
				//rotate self
				//cout << "rotated" << endl;
				removeCharFromMatrix(inputList[indexToTry]->getIDLetter());
					inputList[indexToTry]->setUsedState(false);
				inputList[indexToTry]->rotate();
				//try next
				if(findSolutionHelper(indexToTry+1))
				{
						//if success:
							//return true
					return true;
				}
				//if fail:
				else
				{
					//cout << "hear" << endl;
					//remove self
					removeCharFromMatrix(inputList[indexToTry]->getIDLetter());
					inputList[indexToTry]->setUsedState(false);
					//try next
					if(findSolutionHelper(indexToTry+1))
					{
				 	//if success:
				 		//try self
				 		if(findSolutionHelper(indexToTry+1))
						{
				 			//if success:
				 				//return true
							return true;
						}
						else{
							//if fail:
							//rotate 
							//cout << "rotated" << endl;
							removeCharFromMatrix(inputList[indexToTry]->getIDLetter());
					inputList[indexToTry]->setUsedState(false);
							inputList[indexToTry]->rotate();
							if(addRectToMatrix(*inputList[indexToTry]))
							{
								return true;
							}
							else{
								return false;
							}

							 				//try self
							 					//if success:
							 						//return true
												//if fail:
													//return false
						}
					}
					else{
						//if fail:
							//return false
						return false;
					}					
								
				}

			}
		}
		else{
	//if fail:
		//try next
			if(findSolutionHelper(indexToTry+1)){
			//if success:
				//try self
					if(addRectToMatrix(*inputList[indexToTry]))
					{
						return true;
					}
					else{
													inputList[indexToTry]->rotate();
							if(addRectToMatrix(*inputList[indexToTry]))
							{
								return true;
							}
							else{
								return false;
							}
					}
					//if success:
						//return true
					//if fail:
						//return false
			}
			else{
			//if fail:
				//return false
				return false;
			}
		}
	}
	else{
		//cout << "nope " << endl;
		return true;
	}
}

bool SolverClass::addRectToMatrix(Rectangle input)
{
	int rowBound = container->getNumRows();
	int colBound = container->getNumCols();
	int row = 0;
	int column = 0;
	int rowHold;
	int columnHold;
	int rowCounter;
	int columnCounter;
	char hold;
	bool flag =false;
	if(!input.isUsed())
	{
		while(flag == false)
		{
			if(findNextLocation(row, column))
			{
				rowHold = row;
				columnHold = column;
				rowCounter = row;
				columnCounter = column;
				//cout << "-----[" << row << "," << column << "]" << endl;
				int i, j;

				
					for(j= 0; j <input.getHeight();j++)
				{
					for( i= 0; i <input.getWidth();i++)
					{

						//cout << i << "," << j << endl;
						
						if(rowCounter < rowBound && columnCounter < colBound)
							{
								
								container->getValueAt(rowCounter,columnCounter,hold);
								//cout << hold << endl;
								
							 	if( hold == 'O')
							 	{
							 		//cout << "[" << rowCounter << "," << columnCounter << "]" << endl;
									container->setValueAt(rowCounter,columnCounter,input.getIDLetter());
									//cout << row- input.getHeight()<< "," << column-columnHold << " is not " << rowHold << "," << columnHold << endl;
									if(j ==input.getHeight()-1 && i ==input.getWidth()-1){
										//cout <<  "successfully added " << input.getIDLetter() << endl; 
										flag = true;
									}
									rowCounter++;
								}
								else
								{
									//	cout <<  "could not add " << input.getIDLetter() << endl; 
									removeCharFromMatrix(input.getIDLetter());
									return false;
								}

							}

							else
							{
								//cout << "not2" << endl; 
								removeCharFromMatrix(input.getIDLetter());
								return false;

							}
						
					}
					columnCounter++;
					rowCounter = rowHold;
					//cout << "~~" <<rowHold << endl;
					
				}
				//flag = true;
				row++;
				column++;
			}
		}
		input.setUsedState(true);
	}
	else
	{
		return false;
	}
//displayField();
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
void SolverClass::removeAllFromMatrix()
{
	char hold;

	for(int i = 0; i < container->getNumRows(); i++)
	{
		for(int j = 0; j < container->getNumCols(); j++)
		{
			container->getValueAt(i,j, hold);
			if (hold != 'O')
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
	cout << endl;
}

bool SolverClass::findNextLocation(int& foundRow, int& foundColumn)
{
	bool flag = false;
	char hold;

	for(int i = foundRow; i < container->getNumRows(); i++)
	{
		for(int j = foundColumn; j < container->getNumCols(); j++)
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