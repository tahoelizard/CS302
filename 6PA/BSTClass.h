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

#ifndef BST_CLASS_H
#define BST_CLASS_H

// Header files ///////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

// Class constants ////////////////////////////////////////////////////////////

   // None

// Class definition ///////////////////////////////////////////////////////////

template <typename DataType>
class BSTNode
   {
    public:

       BSTNode( const DataType &nodeData, BSTNode *leftPtr, BSTNode *rightPtr );

       DataType dataItem;

       BSTNode<DataType> *left;
       BSTNode<DataType> *right;
   };

template <typename DataType>
class BSTClass
   {
    public:

       // constants
       static const char TAB = '\t';

       // constructor
       BSTClass();
       BSTClass( const BSTClass<DataType> &copied );

       // destructor
       ~BSTClass();

       // assignment operator
       const BSTClass &operator = (const BSTClass<DataType> &rhData );

       // modifiers
       void copyTree( const BSTClass<DataType> &copied );
       void clearTree();
       void insert( const DataType &newData );
       bool findItem( const DataType &searchDataItem ) const;
       bool removeItem( const DataType &dataItem );

       // accessors
       bool isEmpty() const;
       void preOrderTraversal() const;
       void inOrderTraversal() const;
       void postOrderTraversal() const;
       int getHeight() const;
       void showStructure() const;
 
    private:

       BSTNode<DataType> *rootNode;    
   };

#include "BSTClass.cpp"

#endif	// define BST_CLASS_H



