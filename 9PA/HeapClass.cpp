// Program Information ////////////////////////////////////////////////////////
/**
 * @file HeapClass.cpp
 *
 * @brief Implementation file for HeapClass
 * 
 * @details Implements all member actions for the HeapClass
 *
 * @author Michael Leverington
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



















































/////////////////////////////////add functions////////////////////////////////

template<typename KeyType, typename DataType>
void HeapClass<KeyType, DataType>::addItem
       ( 
        const KeyType &newKey,
        const DataType &newData
       )
   {
    // assignment component
//cout << " starting to add" << endl;
    char patientName[ 30 ], medicalCode[ MAX_STR_LEN ];
    char patientGender;
    HeapNode<KeyType, DataType> *parentHold;



    if(isEmpty()){
      rootNode = new HeapNode<KeyType, DataType>(newKey, newData,NULL,NULL,NULL);
     // cout << "added root to empty heap" << endl;
    }
    else{
      findAddSpot(parentHold);
      //cout << "here" << endl;
      if(parentHold !=NULL){

parentHold->dataItem.getAccount( patientName, medicalCode, patientGender );
//cout << patientName;

      }
else{ //cout << "BOOOOOO" << endl;
}

    //  cout << "found add spot" << endl;
      if(parentHold->left == NULL ){
        parentHold->left =new HeapNode<KeyType, DataType>(newKey, newData,parentHold,NULL,NULL);
     //   cout << "added to left" << endl;
        trickleUp(parentHold->left);
      //  cout << "upped" << endl;
      }
      else{
        parentHold->right =new HeapNode<KeyType, DataType>(newKey, newData,parentHold,NULL,NULL);
      //  cout << "added to right" << endl;
        trickleUp(parentHold->right);
      }
      
    }
   // cout << "added" << endl;
   }


template<typename KeyType, typename DataType>
  bool HeapClass<KeyType, DataType>::findAddSpot(HeapNode<KeyType, DataType>*& holdNode)
  {
     HeapNode<KeyType, DataType> *hold;
    char patientName[ 30 ], medicalCode[ MAX_STR_LEN ];
    char patientGender;

     if(!isEmpty())
     {
     // cout << "not empty" << endl;
      if(getLeftHeight() == getRightHeight()){
       // cout << "equal" << endl;
        //return far left's left
        hold = rootNode;
        rootNode->dataItem.getAccount( patientName, medicalCode, patientGender );
         // cout << patientName;

        while(hold->left != NULL){
          
          hold = hold->left;
        }
        hold->dataItem.getAccount( patientName, medicalCode, patientGender );
       // cout << patientName;
        holdNode = hold;

      }
      else{
       // cout << "not equal" << endl;
        if(findAddHelper(1, rootNode, hold))
        {
          holdNode = hold;
          //cout << "+++++++++++++++" << endl;
          return true;
        }
        else
        {
          return true;
        }
      }
    }
    else{
      //cout << "empty" << endl;
      return false;
    }
   // cout << "done finding" << endl;
  }





template<typename KeyType, typename DataType>
  bool HeapClass<KeyType, DataType>::findAddHelper(int currentDepth, HeapNode<KeyType, DataType>* checkNode,  HeapNode<KeyType, DataType>*& hold)
  {
        char patientName[ 30 ], medicalCode[ MAX_STR_LEN ];
    char patientGender;

/*
    if(checkNode != NULL)
    {
      checkNode->dataItem.getAccount( patientName, medicalCode, patientGender );
      cout << "---checking " << patientName << endl;
        if(checkNode->left == NULL || checkNode->right == NULL){
        hold = checkNode;
        return true;
        }
        else
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
    }
    else
    {
      return false;
    }

*/

    if(checkNode != NULL)
    {   
      if(currentDepth != getRightHeight()){
        //cout <<"same level " << endl;
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
       // cout <<"not same level " << endl;
        if(checkNode->left == NULL || checkNode->right == NULL)
        {
          hold = checkNode;
         // cout <<"done with not same level " << endl;
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

  template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::trickleUp(HeapNode<KeyType, DataType>* moveNode)
{
      char patientName[ 30 ], medicalCode[ MAX_STR_LEN ];
    char patientGender;
    moveNode->dataItem.getAccount( patientName, medicalCode, patientGender );
       // cout << patientName;

  //cout << "up!" << endl;
  while(
    //
    //&& 
    moveNode != rootNode
    )
  {
    //swap
    if(moveNode->keyItem > moveNode->parent->keyItem ){
      //cout << "swapping ";
              moveNode->dataItem.getAccount( patientName, medicalCode, patientGender );
         // cout << patientName;
         // cout << " and ";
          moveNode->parent->dataItem.getAccount( patientName, medicalCode, patientGender );
         // cout << patientName << endl;
      swap(moveNode, moveNode->parent);
    }
      moveNode = moveNode->parent;

  }
 // cout << "done up!" << endl;
}

  template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::swap(HeapNode<KeyType, DataType>* lhNode, HeapNode<KeyType, DataType>* rhNode)
{
         KeyType keyHold;
       DataType dataHold;
  if(rhNode != NULL && lhNode != NULL){
    keyHold = rhNode->keyItem;
    dataHold = rhNode->dataItem;

    rhNode->keyItem = lhNode->keyItem;
    rhNode->dataItem = lhNode->dataItem;

    lhNode->dataItem = dataHold;
    lhNode->keyItem = keyHold;

    return true;
  }
  else{
    return false;
  }
}
/////////////////////////////////delete functions////////////////////////////////
  


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
    
    if(!isEmpty()){

      findPromotion(hold);
      if(hold == rootNode){
        delete rootNode;
        rootNode = NULL;
      }
      else
      {
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



template<typename KeyType, typename DataType>
   bool HeapClass<KeyType, DataType>::findPromotion(HeapNode<KeyType, DataType>*& moveNode)
{
  //stub
  return false;
}



template<typename KeyType, typename DataType>
bool HeapClass<KeyType, DataType>::trickleDown(HeapNode<KeyType, DataType>* moveNode)
{

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


