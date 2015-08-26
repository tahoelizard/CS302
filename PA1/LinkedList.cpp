#include <iostream>
#include "ListNode.h"
#include "LinkedList.h"

LinkedList::LinkedList( int maxSize ){

}
       LinkedList::LinkedList( const LinkedList& other ){

       }
       LinkedList::~LinkedList(){

       }

       // modifiers
       bool LinkedList::insertBeforeCursor( int newDataItem ){

       }
       bool LinkedList::insertAfterCursor( int newDataItem ){

       }
       bool LinkedList::replaceBeforeCursor( int newDataItem ){

       }    
       bool LinkedList::replaceAtCursor( int newDataItem ){

       }
       bool LinkedList::replaceAfterCursor( int newDataItem ){

       }

       bool LinkedList::removeAtCursor( int &dataVal ){

       }
       void LinkedList::clear(){

       }
       
       LinkedList& LinkedList::isAssigned( const LinkedList& other ){

       }
       LinkedList& LinkedList::operator = ( const LinkedList& other ){

       }

       // accessors
       bool LinkedList::getDataAtCursor( int &dataVal ) const{

       }
       void LinkedList::showStructure( char listID ) const{

       }

       bool LinkedList::isEmpty() const{

       }
       bool LinkedList::isFull() const{

       }

       bool LinkedList::goToBeginning(){

       }
       bool LinkedList::goToEnd(){

       }
       bool LinkedList::goToNext(){

       }
       bool LinkedList::goToPrior(){

       }