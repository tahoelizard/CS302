// Program Information ////////////////////////////////////////////////////////
/**
 * @file NameType.cpp
 *
 * @brief Implementation file for NameType class
 * 
 * @details Implements the constructor method of the NameType class
 *
 * @author Michael Leverington
 *
 * @version 1.00 (03 October 2015)
 *
 * @Note Requires NameType.h
 */

// Precompiler directives /////////////////////////////////////////////////////

#ifndef BST_CLASS_CPP
#define BST_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "BSTClass.h"
#include <new>

using namespace std;

// Class Implementation  //////////////////////////////////////////////////////

template<typename DataType>
BSTNode<DataType>::BSTNode
       (
        const DataType &nodeData, // in: data value
        BSTNode *leftPtr,         // in: left node pointer
        BSTNode *rightPtr         // in: right node pointer
       )
     : dataItem( nodeData ), left( leftPtr ), right( rightPtr )
   {
    // data placed in initializers
   }

template<typename DataType>
BSTClass<DataType>::BSTClass
       (
        // no parameters
       )
     : rootNode( NULL )
   {
    // data placed in initializers
   }
           
template<typename DataType>
BSTClass<DataType>::BSTClass
       ( 
        const BSTClass<DataType> &copied 
       )
     : rootNode( NULL )
   {
    copyTree( copied );
   }

template<typename DataType>
BSTClass<DataType>::~BSTClass
       (
        // no parameters
       )
   {
    clearTree();
   }

template <typename DataType>
const BSTClass<DataType>& BSTClass<DataType>:: operator = 
                                                    ( const BSTClass &rhTree )
   {
    if( this != &rhTree ) 
       {
        clearTree();
        copyTree( rhTree );
       }

    return *this;
   }

template<typename DataType>
void BSTClass<DataType>::copyTree
       ( 
        const BSTClass<DataType> &copiedTree 
       )
   {
    copyTreeHelper( rootNode, copiedTree.rootNode );
   }

template<typename DataType>
void BSTClass<DataType>::clearTree
       (       
        // no parameters
       )
   {
    clearTreeHelper( rootNode );

    rootNode = NULL;
   }

template <typename DataType>
void BSTClass<DataType>::insert
       ( 
        const DataType &newData 
       )
   {
    insertHelper( rootNode, newData);
   }

template <typename DataType>
bool BSTClass<DataType>::findItem
       ( 
        DataType &dataItem 
       ) const
   {
    BSTNode<DataType>* foundLocParent;
    BSTNode<DataType>* foundLoc;
    return findItemHelper(dataItem,rootNode, foundLoc, foundLocParent);
   }

template <typename DataType>
bool BSTClass<DataType>::findItemHelper
       ( 
        DataType &dataItem,
        BSTNode<DataType> *direction,
        BSTNode<DataType> *&foundLoc,
        BSTNode<DataType> *&foundLocParent
       ) const
   {

    bool hold = false; 

    if(!isEmpty())
    {
      if(dataItem.compareTo(direction->dataItem) == 0)
      {
        foundLoc = direction;
        dataItem = direction->dataItem;
        return true;
      }
      else
      {
        if(direction->left !=NULL)
        {
          foundLocParent = direction;
          hold = findItemHelper(dataItem, direction->left, foundLoc, foundLocParent);
          if(hold == true)
          {
            return hold;
          }
        }
        if(direction->right !=NULL)
        {
          foundLocParent = direction;
          hold = findItemHelper(dataItem, direction->right, foundLoc, foundLocParent);
        }
        return hold;
      }
    }
    else
    {
      return false;
    }
    
}

////////////////////////////// to be implemented //////////////////////////////
template <typename DataType>
bool BSTClass<DataType>::removeItem
       ( 
        const DataType &dataItem 
       )
   {
    DataType hold;
    hold = dataItem;
    BSTNode<DataType> *foundLoc = NULL;
    BSTNode<DataType> *foundLocParent = NULL;
    if (findItemHelper(hold,rootNode,foundLoc, foundLocParent))
    {
      cout << "found" << endl;
      removeItemHelper(dataItem,foundLoc,foundLocParent);
      return true;
    }
    else{
      cout << "didn't find" << endl;
      return false;
    }
   }

template <typename DataType>
bool BSTClass<DataType>::removeItemHelper( const DataType &dataItem, BSTNode<DataType> *&foundLoc, BSTNode<DataType> *&foundLocParent){ //what params?? I'd like to use the findHelper function but I also need to know the parent. Don't I? But it seems like just in the case of no children since you need to let the parent know the child died 
  
  if (foundLoc != NULL){
    //if rootNode
    if(foundLoc == rootNode){
      cout << "here1" <<endl;
      //if rootNode has no children
       if (rootNode->left == NULL && rootNode->right == NULL){
        cout << "here2" <<endl;
        delete rootNode;
        rootNode = NULL;
      }
      else{
        //if rootNode has children, promote
      }
    }
    else{
      //if not root and no children, delete and adjust parent
      if (foundLoc->left == NULL && foundLoc->right == NULL){
        if(foundLocParent->left == foundLoc){
          foundLocParent->left = NULL;
          delete foundLoc;
          foundLoc = NULL;
        }
        else{
          foundLocParent->right = NULL;
          delete foundLoc;
          foundLoc = NULL;
        }
      }
      //if children, promote
      else{
        promote(foundLoc, foundLocParent);
      }
    }

  }  

}

template <typename DataType>
bool BSTClass<DataType>::promote( BSTNode<DataType> *&foundLoc, BSTNode<DataType> *&foundLocParent)
{
  BSTNode<DataType> *hold, *parHold;
  showIndividual(foundLoc); 
  if(foundLoc->left != NULL)
  {
    hold = foundLoc->left;
    while(hold->right != NULL)
    {
      parHold = hold;
      hold = hold->right;
    }
    cout <<"about to promote ";
     showIndividual(hold);
     cout <<" to the position of ";
     showIndividual(foundLoc);
     cout << endl;

   if (hold->left != NULL)
    {
      parHold->left = hold->left; 
      showIndividual(parHold->left); 
    }

    cout << "here128" <<endl;

    //foundLoc->dataItem = hold->dataItem;

  }
}

template<typename DataType>
bool BSTClass<DataType>::isEmpty
       ( 
        // no parameters
       ) const
   {
    return ( rootNode == NULL );
   }

template<typename DataType>
void BSTClass<DataType>::preOrderTraversal
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

template<typename DataType>
void BSTClass<DataType>::inOrderTraversal
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

template<typename DataType>
void BSTClass<DataType>::postOrderTraversal
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

template<typename DataType>
int BSTClass<DataType>::getHeight
       (
        // no parameters
       ) const
   {
    return getHeightHelper( rootNode );
   }

////////////////////////////// to be implemented //////////////////////////////
template<typename DataType>
int BSTClass<DataType>::getWidthAtRow
       ( 
        int row    // in: row of width to get
       ) const
   {
    int counter = 0;
    getWidthAtRowHelper(row, 0, counter, *rootNode);
    return counter;
   }

template<typename DataType>
int BSTClass<DataType>::getWidthAtRowHelper(const int levelToCountTo, int levelAt, int& counter, BSTNode<DataType> direction) const
{
  if(levelToCountTo == levelAt){
    counter++; 
  }
  if(levelAt < levelToCountTo){
    if(direction.left != NULL){
      getWidthAtRowHelper(levelToCountTo, levelAt+1, counter, *(direction.left));
    }
    if(direction.right != NULL){
      getWidthAtRowHelper(levelToCountTo, levelAt+1, counter, *(direction.right));
    }
  }
}

////////////////////////////// to be implemented //////////////////////////////
template<typename DataType>
void BSTClass<DataType>::getMaxWidth
       (
        int &maxWidth,     // out: max width found
        int &maxWidthRow   // out: row at which max width found
       ) const
   {
    //setting the givens to zero since they're uninitialized in driver and potentially garbage
    //prime this instead though 
    maxWidth = 0;
    maxWidthRow = 0;

    int holdWidth = 0;
    int holdRow = 0; 
    for(int i = 0; i < getHeight(); i++){
      holdWidth = getWidthAtRow(i); 
      if(holdWidth > maxWidth){
        maxWidth = holdWidth; 
        maxWidthRow = i;
      }
    }
   }

////////////////////////////// to be implemented //////////////////////////////
template<typename DataType>
void BSTClass<DataType>::getMinWidth
      (
        int &minWidth,        // out: min width found
        int &minWidthRow      // out: row at which min width found
       ) const
   {

    int holdWidth = 0;
    int holdRow = 0; 

  minWidth = getWidthAtRow(0); 
  minWidthRow = 0;

    for(int i = 0; i < getHeight(); i++){
      holdWidth = getWidthAtRow(i); 
      if(holdWidth < minWidth){
        minWidth = holdWidth; 
        minWidthRow = i;
      }
    }
   }

////////////////////////////// to be implemented //////////////////////////////
template<typename DataType>
int BSTClass<DataType>::getBottomWidth
       (
        // no parameters
       ) const
   {
    return getWidthAtRow(getHeight() -1);
   }

template<typename DataType>
bool BSTClass<DataType>::isCompleteTree
       (
        // no parameters
       ) const
   {
    int depth;

    if( rootNode != NULL )
       {
        checkDepth( INITIALIZE, getHeight() - 1 );

        for( depth = 0; depth < getHeight() - 1; depth++ )
           {
            if( getWidthAtRow( depth ) != toPower( 2, depth ) )
               {
                return false;
               }
           }
       }

    isCompleteTreeHelper( rootNode, getHeight() - 1, 0 );

    return checkDepth( GET_RESULT, 0 );
   }

////////////////////////////// to be implemented //////////////////////////////
template<typename DataType>
bool BSTClass<DataType>::isFullTree
       (
        // no parameters
       ) const
   {
    return false; // temporary stub return
   }

template<typename DataType>
void BSTClass<DataType>::showStructure
       ( 
        // no parameters
       ) const
   {
    int height = getHeight();

    showStructureHelper( rootNode, height, 0 );

    cout << endl;
   }

template<typename DataType>
void BSTClass<DataType>::showIndividual(BSTNode<DataType> *workingPtr){
  char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
    int acctNum;
    workingPtr->dataItem.getAccount( acctName, acctNum, acctType );
    cout << acctName << endl;
}

template<typename DataType>
void BSTClass<DataType>::showStructureHelper
       ( 
        BSTNode<DataType> *workingPtr,
        int fullHeight,
        int presentHeight
       ) const
   {
    char acctName[ MAX_STR_LEN ], acctType[ MAX_STR_LEN ];
    int acctNum;

    if( workingPtr != NULL )
       {
        showStructureHelper( workingPtr->left, fullHeight, presentHeight + 1 );

        cout << endl;
        showTabs( fullHeight - presentHeight );

        workingPtr->dataItem.getAccount( acctName, acctNum, acctType );

        cout << acctName << endl;

        showStructureHelper( workingPtr->right, fullHeight, presentHeight + 1 );
       }
   }

template<typename DataType>
int BSTClass<DataType>::getHeightHelper
       (
        BSTNode<DataType> *workingPtr
       ) const
   {
    int sizeLeft, sizeRight;

    if( workingPtr != NULL )
       {
        sizeLeft = getHeightHelper( workingPtr->left ) + 1;
        sizeRight = getHeightHelper( workingPtr->right ) + 1;

        if( sizeLeft > sizeRight )
           {
            return sizeLeft;
           }

        return sizeRight;
       }

    return 0;
   }

template<typename DataType>
void BSTClass<DataType>::copyTreeHelper
       ( 
        BSTNode<DataType> *&workingPtr,      // local working pointer
        const BSTNode<DataType> *sourcePtr  // incoming source pointer
       )
   {
    if( sourcePtr != NULL )
       {
        workingPtr = new BSTNode<DataType>( sourcePtr->dataItem, NULL, NULL );
        copyTreeHelper( workingPtr->left, sourcePtr->left );
        copyTreeHelper( workingPtr->right, sourcePtr->right );
       }
   }

template <typename DataType>
void BSTClass<DataType>::clearTreeHelper
       ( 
        BSTNode<DataType> *workingPtr 
       )
   {
    if ( workingPtr != NULL )
       {
        clearTreeHelper( workingPtr->left );
        clearTreeHelper( workingPtr->right );
        delete workingPtr;
       }
   }

template <typename DataType>
void BSTClass<DataType>::insertHelper
       ( 
        BSTNode<DataType> *&workingPtr,
        const DataType &newData
       )
   {
    if ( workingPtr == NULL )
       {
        workingPtr = new BSTNode<DataType>( newData, NULL, NULL );
       }

    else if ( newData.compareTo( workingPtr->dataItem ) < 0 )
       {
        insertHelper( workingPtr->left, newData );
       }

    else if ( newData.compareTo( workingPtr->dataItem ) > 0 )
       {
        insertHelper( workingPtr->right, newData);
       }

    else
       {
        workingPtr->dataItem = newData;
       }
   }

template<typename DataType>
void BSTClass<DataType>::isCompleteTreeHelper
       ( 
        BSTNode<DataType> *workingPtr,  // in: pointer to tree node
        int testDepth,                  // in: depth to test for
        int currentDepth                // in: current depth
       ) const
   {
    if( workingPtr != NULL )
       {
        isCompleteTreeHelper( workingPtr->left, testDepth, currentDepth + 1 );
        isCompleteTreeHelper( workingPtr->right, testDepth, currentDepth + 1 );
       }

    else
       {
        checkDepth( AT_BOTTOM, currentDepth - 1 );
       }
   }

template<typename DataType>
void BSTClass<DataType>::preOrderTraversalHelper
       ( 
        BSTNode<DataType> *workingPtr 
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

template<typename DataType>
void BSTClass<DataType>::inOrderTraversalHelper
       ( 
        BSTNode<DataType> *workingPtr 
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

template<typename DataType>
void BSTClass<DataType>::postOrderTraversalHelper
       ( 
        BSTNode<DataType> *workingPtr 
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

template<typename DataType>
void BSTClass<DataType>::showTabs 
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

template<typename DataType>
bool BSTClass<DataType>::checkDepth
       ( 
        int cmdCode,       // in: informs system where to set
        int depth          // in: present depth information
       ) const
   {
    static int depthHolder = 0;
    static int counter = 0;
    static bool fullState = false;
    static bool leftState = false;
    static bool rightState = false;

    switch( cmdCode )
       {
        case INITIALIZE:
           depthHolder = depth;
           break;

        case AT_BOTTOM:
           if( counter == 1 && depth == depthHolder )
              {
               leftState = true;
               fullState = true;
              }

           else if( leftState && !rightState )
              {
               if( depth == depthHolder - 1 )
                  {
                   rightState = true;

                   depthHolder = depth;
                  }
              }

           else if( leftState && rightState && fullState )
              {
               if( depth != depthHolder )
                  {
                   fullState = false;
                  }
              } 
           break;
       }

    counter++;

    return fullState;
   }

template<typename DataType>
int BSTClass<DataType>::toPower
       ( 
        int base,    // in: base
        int exponent // in: times to multiply base by itself
       ) const
   {
    int index, result = 1;
   
    for( index = 0; index < exponent; index++ )
       {
        result *= base;
       }

    return result;
   }

#endif	// define BST_CLASS_CPP


