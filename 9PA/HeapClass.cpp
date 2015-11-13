// Program Information ////////////////////////////////////////////////////////
/**
 * @file HeapClass.cpp
 *
 * @brief Implementation file for HeapClass
 * 
 * @details Implements all member actions for the HeapClass
 *
 * @author Michael Leverington and Elizabeth Johnson
 *
 * @version 1.00 (30 October 2015)
 *
 * @Note Requires HeapClass.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef HEAP_CLASS_CPP
#define HEAP_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "HeapClass.h"
#include <new>
 #include <iostream>

using namespace std;

// Class Implementation  //////////////////////////////////////////////////////

template<typename KeyType, typename DataType>
HeapNode<KeyType, DataType>::HeapNode
       (
        const KeyType &nodeKey,   // in: key value
        const DataType &nodeData, // in: data value
        HeapNode *parentPtr,      // in: parent pointer
        HeapNode *leftPtr,         // in: left node pointer
        HeapNode *rightPtr         // in: right node pointer
       )
     : keyItem( nodeKey ), dataItem( nodeData ), parent( parentPtr ), 
       left( leftPtr ), right( rightPtr )
   {
    // data placed in initializers
   }

template<typename KeyType, typename DataType>
HeapClass<KeyType, DataType>::HeapClass
       (
        // no parameters
       )
     : rootNode( NULL )
   {
    // data placed in initializers
   }
           
template<typename KeyType, typename DataType>
HeapClass<KeyType, DataType>::HeapClass
       ( 
        const HeapClass<KeyType, DataType> &copied 
       )
     : rootNode( NULL )
   {
    copyTree( copied );
   }

template<typename KeyType, typename DataType>
HeapClass<KeyType, DataType>::~HeapClass
       (
        // no parameters
       )
   {
    clearTree();
   }

template<typename KeyType, typename DataType>
const HeapClass<KeyType, DataType>& HeapClass<KeyType, DataType>:: operator = 
                                                    ( const HeapClass &rhTree )
   {
    if( this != &rhTree ) 
       {
        clearTree();
        copyTree( rhTree );
       }

    return *this;
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::copyTree
       ( 
        const HeapClass<KeyType, DataType> &copiedTree 
       )
   {
    copyTreeHelper( rootNode, NULL, copiedTree.rootNode );
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::clearTree
       (       
        // no parameters
       )
   {
    clearTreeHelper( rootNode );

    rootNode = NULL;
   }


//add functions///////////////////////////////////////////////////////////////
/**
 * @brief Add Item
 *
 * @details Adds the given info to the heap in the right location
 *          
 * @param In: Keytype of new item
 * @param In: Datatype of new item
 *
 * @note None
 */
template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::addItem
       ( 
        const KeyType &newKey,
        const DataType &newData
       )
{

  HeapNode<KeyType, DataType> *parentHold;
  if(isEmpty())
  {
    rootNode = new HeapNode<KeyType, DataType>(newKey, newData,NULL,NULL,NULL);
  }
  else{
    findAddSpot(parentHold);
    if(parentHold->left == NULL )
    {
      parentHold->left =new HeapNode<KeyType, DataType>(newKey, newData,parentHold,NULL,NULL);
      trickleUp(parentHold->left);
    }
    else
    {
      parentHold->right =new HeapNode<KeyType, DataType>(newKey, newData,parentHold,NULL,NULL);
      trickleUp(parentHold->right);
    }  
  }
}

/**
 * @brief Find Add Spot
 *
 * @details Finds proper spot to add a new item
 *          
 * @param in: HeapNode to hold resulting location
 *
 * @note Relies on findAddHelper
 */
template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::findAddSpot(HeapNode<KeyType, DataType>*& holdNode)
{
    HeapNode<KeyType, DataType> *hold;

  if(!isEmpty())
  {
    if(getLeftHeight() == getRightHeight())
    {
      hold = rootNode;
      while(hold->left != NULL)
      {
        hold = hold->left;
      }
      holdNode = hold;
    }
    else
    {
      if(findAddHelper(1, rootNode, hold))
      {
        holdNode = hold;
        return true;
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

/**
 * @brief Find Add Helper
 *
 * @details Recursively searches for the next empty spot in the heap
 *          
 * @param in: int to track depth
 * @param in: HeapNode of the next place to check
 * @param in: HeapNode to hold resulting location
 *
 * @note None
 */
template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::findAddHelper(int currentDepth, HeapNode<KeyType, DataType>* checkNode,  HeapNode<KeyType, DataType>*& hold)
{
  if(checkNode != NULL)
  {   
    if(currentDepth != getRightHeight())
    {
      if(findAddHelper(currentDepth+1, checkNode->left, hold))
      {
        return true;
      }
      else
      {
        return findAddHelper(currentDepth+1, checkNode->right, hold);
      }
    }
    else
    {
      if(checkNode->left == NULL || checkNode->right == NULL)
      {
        hold = checkNode;
        return true;
      }
      else
      {
        return false;
      }
    }
  }
  else
  {
    return false;
  }
}

/**
 * @brief Trickle Up 
 *
 * @details Pushes given node to its proper place
 *          
 * @param in: HeapNode to push
 *
 * @note None
 */
template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::trickleUp(HeapNode<KeyType, DataType>* moveNode)
{
  while(moveNode != rootNode)
  {
    if(moveNode->keyItem < moveNode->parent->keyItem )
    {
      swap(moveNode, moveNode->parent);
    }
    moveNode = moveNode->parent;
  }
}

/**
 * @brief Swap
 *
 * @details Swaps the data of two nodes
 *          
 * @param in: left hand HeapNode
 * @param in: right hand HeapNode
 *
 * @note None
 */
template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::swap(HeapNode<KeyType, DataType>* lhNode, HeapNode<KeyType, DataType>* rhNode)
{
  KeyType keyHold;
  DataType dataHold;
  if(rhNode != NULL && lhNode != NULL)
  {
    keyHold = rhNode->keyItem;
    dataHold = rhNode->dataItem;

    rhNode->keyItem = lhNode->keyItem;
    rhNode->dataItem = lhNode->dataItem;

    lhNode->dataItem = dataHold;
    lhNode->keyItem = keyHold;

    return true;
  }
  else
  {
    return false;
  }
}

//delete functions///////////////////////////////////////////////////////////////
/**
 * @brief Remove Item
 *
 * @details Removes data from root node
 *          
 * @param in: Datatype to store the removed data
 * @param in: Keytype to store the removed key
 *
 * @note Relies on findPromotion trickle Down
 */
template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::removeItem
       ( 
        DataType &returnedDataItem,
        KeyType &returnedKeyItem 
       )
   {
    // assignment component
    HeapNode<KeyType, DataType> *hold;
    HeapNode<KeyType, DataType> *parentHold;
    
    if(!isEmpty())
    {

      findPromotion(1,rootNode,hold);
      if(hold == rootNode)
      {
        delete rootNode;
        rootNode = NULL;
      }
      else
      {
        returnedKeyItem = rootNode->keyItem ;
        returnedDataItem = rootNode->dataItem;

        rootNode->dataItem = hold->dataItem;
        rootNode->keyItem = hold->keyItem;

        //tell parent
        parentHold = hold->parent;
        if(parentHold->right == hold)
        {
          parentHold->right= NULL;
        }
        else
        {
          parentHold->left = NULL;
        }

        //clean up
        delete hold;
        hold = NULL;

        return trickleDown(rootNode);
      }
    }
    else
    {
      return false;
    }
    
   }


/**
 * @brief Find Promotion 
 *
 * @details searches for the last item to promote
 *          
 * @param in: int to track depth
 * @param in: HeapNode of the next place to check
 * @param in: HeapNode to hold resulting location
 *
 * @note None
 */
template<typename KeyType, typename DataType>
   bool HeapClass<KeyType, DataType>::findPromotion(int currentDepth, HeapNode<KeyType, DataType>* checkNode,  HeapNode<KeyType, DataType>*& hold)
{
   if(checkNode != NULL)
    {   
      if(currentDepth != getRightHeight())
      {
        if(findPromotion(currentDepth+1, checkNode->left, hold))
        {
          return true;
        }
        else
        {
          return findPromotion(currentDepth+1, checkNode->right, hold);
        }
      }
      else
      {
        if(checkNode->left == NULL && checkNode->right == NULL)
        {
          return false;
        }

        else
        {
          if(checkNode->left != NULL)
          {
            hold = checkNode->left;
            if(checkNode->right != NULL)
            {
              hold = checkNode->right;
            }
            else{

            }
          }
          
        }
      }
    }
    else
    {
      return false;
    }
}


/**
 * @brief Trickle Down
 *
 * @details Pushes given node down to the proper place
 *          
 * @param in: HeapNode of the node to push
 *
 * @note None
 */
template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::trickleDown(HeapNode<KeyType, DataType>* moveNode)
{
  bool check = true;
  while(check)
  {
    if(moveNode->left->keyItem < moveNode->right->keyItem)
    {
      if(moveNode->keyItem > moveNode->left->keyItem)
      {
        swap(moveNode, moveNode->left);
        moveNode= moveNode->left;
      }
      else if(moveNode->keyItem > moveNode->right->keyItem){
        swap(moveNode, moveNode->right);
        moveNode = moveNode->right;
      }
      else{
        check = false; 
      }
    }
    else
    {

      if(moveNode->keyItem > moveNode->right->keyItem)
      {
        swap(moveNode, moveNode->right);
        moveNode = moveNode->right;
      }
      else if(moveNode->keyItem > moveNode->left->keyItem)
      {
        swap(moveNode, moveNode->left);
        moveNode= moveNode->left;
      }
      else
      {
        check = false; 
      }
    }

  }
}




template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::isEmpty
       ( 
        // no parameters
       ) const
   {
    return ( rootNode == NULL );
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::preOrderTraversal
       (
        // no parameters
       ) const
   {
    if( rootNode != NULL )
       {
        preOrderTraversalHelper( rootNode );
        cout << endl;
       }

    else
       {
        cout << "Tree is empty" << endl;
       }
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::inOrderTraversal
       (
        // no parameters
       ) const
   {
    if( rootNode != NULL )
       {
        inOrderTraversalHelper( rootNode );
        cout << endl;
       }

    else
       {
        cout << "Tree is empty" << endl;
       }
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::postOrderTraversal
       (
        // no parameters
       ) const
   {
    if( rootNode != NULL )
       {
        postOrderTraversalHelper( rootNode );
        cout << endl;
       }

    else
       {
        cout << "Tree is empty" << endl;
       }
   }

template<typename KeyType, typename DataType>
int HeapClass<KeyType, DataType>::getLeftHeight
       (
        // no parameters
       ) const
   {
    return getHeightHelper( rootNode, 'L' );
   }

template<typename KeyType, typename DataType>
int HeapClass<KeyType, DataType>::getRightHeight
       (
        // no parameters
       ) const
   {
    return getHeightHelper( rootNode, 'R' );
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::showStructure
       ( 
        // no parameters
       ) const
   {
    int height = getLeftHeight();

    if( rootNode != NULL )
       {
        showStructureHelper( rootNode, height, 0 );

        cout << endl << "Left Height: " << getLeftHeight() 
             << ", Right Height: "  << getRightHeight() << endl;
       }

    else
       {
        cout << "Empty Tree" << endl;
       }

    cout << endl;
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::showStructureHelper
       ( 
        HeapNode<KeyType, DataType> *workingPtr,
        int fullHeight,
        int presentHeight
       ) const
   {
    char patientName[ MAX_STR_LEN ], medicalCode[ MAX_STR_LEN ];
    char patientGender;

    if( workingPtr != NULL )
       {
        showStructureHelper( workingPtr->left, fullHeight, presentHeight + 1 );

        cout << endl;
        showTabs( fullHeight - presentHeight );

        workingPtr->dataItem.getAccount( patientName, medicalCode, patientGender );

        cout << patientName;

        cout << ", " << int( workingPtr->keyItem ) << endl;

        showStructureHelper( workingPtr->right, fullHeight, presentHeight + 1 );
       }
   }

template<typename KeyType, typename DataType>
int HeapClass<KeyType, DataType>::getHeightHelper
       (
        HeapNode<KeyType, DataType> *workingPtr,
        char leftRightIndicator
       ) const
   {
    if( workingPtr != NULL )
       {
        if( leftRightIndicator == 'L' )
           {
            return 1 + getHeightHelper( workingPtr->left, leftRightIndicator );
           }

        return 1 + getHeightHelper( workingPtr->right, leftRightIndicator );
       }

    return 0;
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::copyTreeHelper
       ( 
        HeapNode<KeyType, DataType> *&workingPtr,      // local working pointer
        HeapNode<KeyType, DataType> *parentPtr,      // local parent pointer
        const HeapNode<KeyType, DataType> *sourcePtr  // incoming source pointer
       )
   {
    if( sourcePtr != NULL )
       {
        workingPtr = new HeapNode<KeyType, DataType>( sourcePtr->keyItem, 
                                  sourcePtr->dataItem, parentPtr, NULL, NULL );
        copyTreeHelper( workingPtr->left, workingPtr, sourcePtr->left );
        copyTreeHelper( workingPtr->right, workingPtr, sourcePtr->right );
       }
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::clearTreeHelper
       ( 
        HeapNode<KeyType, DataType> *workingPtr 
       )
   {
    if ( workingPtr != NULL )
       {
        clearTreeHelper( workingPtr->left );
        clearTreeHelper( workingPtr->right );
        delete workingPtr;
       }
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::preOrderTraversalHelper
       ( 
        HeapNode<KeyType, DataType> *workingPtr 
       ) const
   {
    char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
    int acctNum;

    if( workingPtr != NULL )
       {
        workingPtr->dataItem.getAccount( acctName, acctNum, acctType );

        cout << acctName << endl;

        preOrderTraversalHelper( workingPtr->left );

        preOrderTraversalHelper( workingPtr->right );
       }
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::inOrderTraversalHelper
       ( 
        HeapNode<KeyType, DataType> *workingPtr 
       ) const
   {
    char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
    int acctNum;

    if( workingPtr != NULL )
       {
        inOrderTraversalHelper( workingPtr->left );
   
        workingPtr->dataItem.getAccount( acctName, acctNum, acctType );
    
        cout << acctName << endl;

        inOrderTraversalHelper( workingPtr->right );
       }
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::postOrderTraversalHelper
       ( 
        HeapNode<KeyType, DataType> *workingPtr 
       ) const
   {
    char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
    int acctNum;

    if( workingPtr != NULL )
       {
        postOrderTraversalHelper( workingPtr->left );

        postOrderTraversalHelper( workingPtr->right );

        workingPtr->dataItem.getAccount( acctName, acctNum, acctType );

        cout << acctName << endl;
       }
   }

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::showTabs 
       ( 
        int numTabs 
       ) const
   {
    int counter;

    for( counter = 0; counter < numTabs; counter++ )
       {
        cout << TAB;
       }
   }

#endif	// define HEAP_CLASS_CPP


