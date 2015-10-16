// Program Information ////////////////////////////////////////////////////////
/**
 * @file BSTClass.h
 *
 * @brief Definition file for Binary Search Tree class
 * 
 * @details Specifies all data of the BST class
 *
 * @author Michael Leverington
 *
 * @version 1.00 (03 October 2015)
 *
 * @Note None
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef BST_CLASS_CPP
#define BST_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>
 #include "BSTClass.h"

using namespace std;


/**
 * @brief Initialization constructor
 *
 * @details creats node with data, left, and right
 *          
 * @param in: New string name
  * @param in: New left pointer
   * @param in: New right pointer
 *
 * @note None
 */
template <typename DataType>
BSTNode<DataType>::BSTNode( const DataType &nodeData, BSTNode<DataType> *leftPtr, BSTNode<DataType> *rightPtr )
{
	dataItem = nodeData;
	left = leftPtr;
	right = rightPtr;
}

/**
 * @brief Destructor
 *
 * @details Destroys node
 *          
 * @param in: none
 *
 * @note None
 */
template <typename DataType>
BSTClass<DataType>::BSTClass()
{
	rootNode = NULL;
}

/**
 * @brief Copy constructor
 *
 * @details initializes as a copy of another tree
 *          
 * @param in: Tree to be copied
 *
 * @note None
 */
template <typename DataType>
BSTClass<DataType>::BSTClass( const BSTClass<DataType> &copied )
{
	copyTree(copied);
}

/**
 * @brief Destructor
 *
 * @details Destroys tree
 *          
 * @param in: none
 *
 * @note relies on clearTree
 */
template <typename DataType>
BSTClass<DataType>::~BSTClass()
{
	if(!isEmpty())
	{
		clearTree();
	}
}

/**
 * @brief Overloaded equals sign
 *
 * @details copies other tree into current tree
 *          
 * @param in: Tree to be copied
 *
 * @note Relies on copyTree
 */
template <typename DataType>
const BSTClass<DataType> & BSTClass<DataType>::operator = (const BSTClass<DataType> &rhData )
{
	copyTree(rhData);
}

/**
 * @brief Copy Tree
 *
 * @details copies all of another tree into current tree
 *          
 * @param in: other tree to be copied
 *
 * @note Relies on copyHelper and clearTree
 */
template <typename DataType>
void BSTClass<DataType>::copyTree( const BSTClass<DataType> &copied )
{
	
	if(!copied.isEmpty())
	{
		if(rootNode == NULL)
		{
			rootNode = new BSTNode<DataType>(copied.rootNode->dataItem, NULL,NULL);
		}
		copyHelper(rootNode, copied.rootNode);
	}
	else
	{
		clearTree();
	}
	
}

/**
 * @brief Copy Helper
 *
 * @details Recursively copies nodes into current tree
 *          
 * @param in: destination node pointer
  * @param in: source node pointer
 *
 * @note Recursive
 */
template <typename DataType>
void BSTClass<DataType>::copyHelper(BSTNode<DataType> * dest, BSTNode<DataType> *source) {

	if(source != NULL)
	{
		//left side
		if(source->left !=NULL)
		{
			insert(source->left->dataItem);
			copyHelper(dest->left, source->left);
		}
		else{
			dest->left = NULL;
		}

		//right side
		if(source->right !=NULL)
		{
			insert(source->right->dataItem);
			copyHelper(dest->right, source->right);
		}
		else
		{
			dest->right= NULL;
		}
    }
    
}

/**
 * @brief Clear Tree
 *
 * @details Clears out all nodes in the tree
 *          
 * @param in: None
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::clearTree()
{
	
	if(!isEmpty())
	{
		clearHelper(rootNode);
		delete rootNode;
		rootNode = NULL;
	}
	
}

/**
 * @brief Insert
 *
 * @details Places data into the tree
 *          
 * @param in: Datatype to be added
 *
 * @note Relies on insertHelper
 */
template <typename DataType>
void BSTClass<DataType>::insert( const DataType &newData )
{

	if(isEmpty())
	{
		rootNode = new BSTNode<DataType>(newData, NULL, NULL);
	}
	else
	{
		insertHelper(rootNode, newData);
	}
	
}

/**
 * @brief insert Helper
 *
 * @details Recursively finds the place to add data in the tree
 *          
 * @param in: destination node pointer
  * @param in: Datatype to be added
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::insertHelper(BSTNode<DataType> *dest, const DataType &source)
{

    if (source.compareTo(dest->dataItem) == 0 )
	{
    	return;
    }
    if (source.compareTo(dest->dataItem) > 0 )
    {
        if (dest->left != NULL)
        {
            insertHelper(dest->left, source);	
		}
		else
		{
            dest->left = new BSTNode<DataType>(source, NULL, NULL);
            return;
        }
    }
    else
    {
        if (dest->right != NULL)
        {
            insertHelper(dest->right, source);
        }
        else
        {
            dest->right = new BSTNode<DataType>(source, NULL, NULL);
            return;
        }	
    }
	 

}

/**
 * @brief Find Item 
 *
 * @details Finds desired item 
 *          
 * @param in: Datatype to be found
 *
 * @note None
 */
template <typename DataType>
bool BSTClass<DataType>::findItem( const DataType &searchDataItem ) const
{
	//don't worry
}

/**
 * @brief Remove Item 
 *
 * @details removes nodes
 *          
 * @param in: Datatype to be removed
 *
 * @note None
 */
template <typename DataType>
bool BSTClass<DataType>::removeItem( const DataType &dataItem )
{
	//don't worry
}

/**
 * @brief Is Empty 
 *
 * @details Checks if the tree is empty 
 *          
 * @param in: None
 *
 * @note None
 */
template <typename DataType>
bool BSTClass<DataType>::isEmpty() const
{
	if(rootNode == NULL)
	{
		return true;
	}
	else
	{
		return false; 
	}
}

/**
 * @brief pre order traversal
 *
 * @details Displays tree in pre order
 *          
 * @param in: None
 *
 * @note relies on preOrderHelper
 */
template <typename DataType>
void BSTClass<DataType>::preOrderTraversal() const
{
	
	if(!isEmpty())
	{
		preOrdTraversHelper(rootNode);
	}
	else
	{
		cout << "Tree is empty" << endl;
	}
	
}

/**
 * @brief in order traversal
 *
 * @details Displays tree in in order
 *          
 * @param in: None
 *
 * @note relies on inOrderHelper
 */
template <typename DataType>
void BSTClass<DataType>::inOrderTraversal() const
{
	if(!isEmpty())
	{
		inOrdTraversHelper(rootNode);
	}
	else
	{
		cout << "Tree is empty" << endl;
	}
}

/**
 * @brief post order traversal
 *
 * @details Displays tree in post order
 *          
 * @param in: None
 *
 * @note relies on postOrderHelper
 */
template <typename DataType>
void BSTClass<DataType>::postOrderTraversal() const
{
	if(!isEmpty())
	{
		postOrdTraversHelper(rootNode);
	}
	else{
		cout << "Tree is empty" << endl;
	}
}

/**
 * @brief Get Height
 *
 * @details Returns current height of the tree
 *          
 * @param in: None
 *
 * @note Relies on heightHelper
 */
template <typename DataType>
int BSTClass<DataType>::getHeight() const
{
	if(isEmpty())
	{
		return 0; 
	}
	else
	{
		int hold = 1; 
		heightHelper(hold,rootNode); 
		return hold;
	}
}

/**
 * @brief Height Helper
 *
 * @details Recursively find the current tree height
 *          
 * @param in: int counter
  * @param in: direction node
 *
 * @note None
 */
template <typename DataType>
int BSTClass<DataType>::heightHelper(int counter, BSTNode<DataType> *direction) const
{	
	int rightHold = 0;
	int leftHold = 0;
	counter++;
	if(direction != NULL)
	{

		rightHold = heightHelper(counter+1, direction->right);
		leftHold = heightHelper(counter+1, direction->left);
	}
	

	if(leftHold >= rightHold)
	{
		counter = leftHold;
	}
	else
	{
		counter = rightHold; 

	}
	return counter;
}

/**
 * @brief Show Structure
 *
 * @details Displays the tree with formatting
 *          
 * @param in: none
 *
 * @note relies on showStructureHelper
 */
template <typename DataType>
void BSTClass<DataType>::showStructure() const
{
	
	if(!isEmpty())
	{
		showStructureHelper(rootNode,0);
	}
	else
	{
		cout << "Tree is empty" << endl;
	}
}

/**
 * @brief show Structure Helper
 *
 * @details Displays the tree with formatting
 *          
 * @param in: int tree depth
   * @param in: direction node
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::showStructureHelper(BSTNode<DataType> *direction, int treeDepth) const
{

	if(direction != NULL)
	{
		showStructureHelper(direction->left, treeDepth+1);

		for(int i =0; i < (getHeight() - treeDepth); i++)
		{
			cout << TAB;
		}
		cout << direction->dataItem << endl;

		showStructureHelper(direction->right, treeDepth+1);	
	}
}

/**
 * @brief In order traverse helper
 *
 * @details recursively displays tree in in order
 *          
 * @param in: direction node
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::inOrdTraversHelper(BSTNode<DataType> *direction) const
{
	
	if(direction != NULL)
	{
		inOrdTraversHelper(direction->left);
		cout << direction->dataItem << endl;
		inOrdTraversHelper(direction->right);
	}

}

/**
 * @brief post order traverse helper
 *
 * @details recursively displays tree in post order
 *          
 * @param in: direction node
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::postOrdTraversHelper(BSTNode<DataType> *direction) const
{
	if(direction != NULL)
	{
		postOrdTraversHelper(direction->left);
		postOrdTraversHelper(direction->right);
		cout << direction->dataItem << endl;
	}
}

/**
 * @brief pre order traverse helper
 *
 * @details recursively displays tree in pre order
 *          
 * @param in: direction node
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::preOrdTraversHelper(BSTNode<DataType> *direction) const
{
	if(direction != NULL)
	{
		cout << direction->dataItem << endl;
		preOrdTraversHelper(direction->left);
		preOrdTraversHelper(direction->right);
	}
}

/**
 * @brief Clear Helper
 *
 * @details Recursively helps clear function
 *          
 * @param in: direction node
 *
 * @note None
 */
template <typename DataType>
void BSTClass<DataType>::clearHelper(BSTNode<DataType> *direction) const
{

	if(direction->left != NULL)
	{
		clearHelper(direction->left);
		delete direction-> left;
		direction->left = NULL;
	}
	if(direction->right != NULL)
	{
		clearHelper(direction->right);
		delete direction-> right;
		direction->right = NULL;
	}

}

#endif	// define BST_CLASS_CPP