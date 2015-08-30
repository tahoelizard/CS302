#include <iostream>
#include "ListNode.h"
#include "LinkedList.h"

LinkedList::LinkedList( int maxSize ){
	cout << "made a list" <<  endl; 
	capacity = maxSize;
	head = NULL;
	cursor = NULL;
	size = 0; 
}
       LinkedList::LinkedList( const LinkedList& other ){
              if (!other.isEmpty()){
                     ListNode* current;
                     ListNode* previous;
                     if(other.head == NULL){
                            head = NULL;
                            size = 0;
                            cursor = NULL;
                            capacity = other.capacity;

                            cout << "nothing to copying" <<  endl; 
                     }
                     else{
                            current = other.head;
                            
                            head = new ListNode (current->dataItem, NULL);
                            cursor = head;
                            size = 1;

                            while(current->next != NULL){
                                   cout << "copying " << cursor->dataItem << endl; 
                                   current = current->next; 
                                   previous = cursor;
                                   cursor = new ListNode (current->dataItem, NULL);
                                   previous->next = cursor; 
                                   size++;
                            }
                     }
              }
                    

       }
       LinkedList::~LinkedList(){
       		size = 0;
       		if(!isEmpty()){
       			cursor = head;
	       		while(cursor != NULL){
	       		    cout << "deleting " << cursor->dataItem << endl; 
	       		      cursor = cursor->next; 
	       			delete head;
	       			head = cursor; 
	       		}
       		}
       }

       // modifiers
       bool LinkedList::insertBeforeCursor( int newDataItem ){
	       	if (isEmpty()){
	       		cursor = new ListNode(newDataItem, NULL);
	       		head = cursor;
	       		size++;
	       		cout << "size is: " << size << endl;
	       		cout << cursor->dataItem << endl;
	       		cout << "me1" << endl;
	       		return true;
	       	}
	       	else if(isFull()){
	       		cout << "size is: " << size << endl;
	       		return false;
	       	}
	       	else if (cursor==head){
	       		ListNode* temp = new ListNode(newDataItem, cursor);
	       		head = temp; 
                            size++;
	       		cout << "size is: " << size << endl;
	       		return true;
	       	}
	       	else{
                            //currently creates infinite loop
	       		ListNode* temp = new ListNode(newDataItem, cursor);
                            //gtp broken
	       		goToPrior();
	       		cursor->next = temp; 
	       		goToNext();
	       		goToNext();
                            size++;
	       		cout << "size is: " << size << endl;
	       		return true;
	       	}
	       	
	       	return true;
       }
       bool LinkedList::insertAfterCursor( int newDataItem ){
       	if( isEmpty()){
       		cursor = new ListNode(newDataItem, NULL);
	       	head = cursor;
	       	size++;
                     cout << "size is: " << size << endl;
	       	return true;
       	}
       	else if(!isFull()){
       		ListNode* temp = new ListNode(newDataItem, cursor->next);
       		cursor->next = temp; 
                     size++;
                     cout << "size is: " << size << endl;
       		return true;
       	}
       	else{
       		return false;
       	}
       	
       }
       bool LinkedList::replaceBeforeCursor( int newDataItem ){
       	if (!isEmpty()){
                     goToPrior();
       	      cursor->dataItem = newDataItem;
       	      goToNext();
                    return true;
              }
              else{
                     return false;
              }
       }    
       bool LinkedList::replaceAtCursor( int newDataItem ){
              if (!isEmpty()){
                     cursor->dataItem = newDataItem;    
                     return true;
              }
              else{
                     return false;
              }
       	
       }
       bool LinkedList::replaceAfterCursor( int newDataItem ){
              if (!isEmpty()){
                    goToNext();
                     cursor->dataItem = newDataItem;
                     goToPrior(); 
                     return true;
              }
              else{
                     return false;
              }
       	
       }

       bool LinkedList::removeAtCursor( int &dataVal ){

              ListNode* temp = cursor->next;
              ListNode* temp2 = cursor;
              goToPrior();
              cursor->next = temp; 
              delete temp2;
       }
       void LinkedList::clear(){

       }
       
       LinkedList& LinkedList::isAssigned( const LinkedList& other ){

       }
       LinkedList& LinkedList::operator = ( const LinkedList& other ){

       }

       // accessors
       bool LinkedList::getDataAtCursor( int &dataVal ) const{
       	if (!isEmpty()){
       		dataVal = cursor->dataItem;
       		return true;
       	}
              else{
                     return false;
              }
       	
       }
       void LinkedList::showStructure( char listID ) const{
              ListNode *temp = head;
              cout << "Showing " << listID << " list:" << endl;
              while (temp != NULL){
                     cout << temp->dataItem; 
                     if (temp == head){
                            cout << "h";
                     }
                     if (temp == cursor){
                            cout << "c";
                     }
                     cout << endl; 
                     temp = temp->next; 
              }
              
       }

       bool LinkedList::isEmpty() const{
       		if ( head == NULL)
       		{
       			cout << "empty" << endl;
       			return true;
       		}
       		else{
       			return false;
       		}

       }
       bool LinkedList::isFull() const{
       		if ( size == capacity){
       			cout << "full" << endl;
       			return true;
       		}
       		else{
       			return false;
       		}
       }

       bool LinkedList::goToBeginning(){
       		if (!isEmpty()){
       			cursor = head;
       			cout << "At the begining" << endl;
       			return true;
       		}
       		else{
       			return false;
       		}

       }
       bool LinkedList::goToEnd(){
       		if (!isEmpty()){
       			while (cursor->next != NULL){
       				cursor = cursor->next; 
       			}
       			cout << "at the end" << endl;
       			return true;
       		}
       		else{
       			return false;
       		}
       }
       bool LinkedList::goToNext(){
       		if (!isEmpty() && cursor->next != NULL){
       			cursor = cursor->next; 
       			return true;
       		}
       		else{
       			return false;
       		}
       }
       bool LinkedList::goToPrior(){
              ListNode *temp = cursor;
              cursor = head; 
              while(cursor->next != temp){
                     cursor = cursor->next; 
              }
       }