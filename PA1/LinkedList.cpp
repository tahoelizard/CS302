#include <iostream>
#include "ListNode.h"
#include "LinkedList.h"

LinkedList::LinkedList( int maxSize )
{
	head = NULL;
	cursor = NULL;
       capacity = maxSize;
	size = 0; 
}

LinkedList::LinkedList( const LinkedList& other )
{
       isAssigned(other);
       capacity = other.capacity;
}

LinkedList::~LinkedList()
{
       size = 0;
       if(!isEmpty())
       {
       	cursor = head;
	       while(cursor != NULL)
              {
	       	cursor = cursor->next; 
	       	delete head;
	       	head = cursor; 
	       }
       }
       head = NULL;
       cursor = NULL;
}

bool LinkedList::insertBeforeCursor( int newDataItem )
{
	if (isEmpty())
       {
	       cursor = new ListNode(newDataItem, NULL);
	       head = cursor;
	       size++;
	       return true;
	}
	else if(isFull())
       {
	       return false;
	}
	else if (cursor==head)
       {
	       ListNode* temp = new ListNode(newDataItem, cursor);
	       head = temp; 
              cursor = head;
              size++;
	       return true;
	}
	else
       {
	       ListNode* temp = new ListNode(newDataItem, cursor);
	       goToPrior();
	       cursor->next = temp; 
	       goToNext();
              size++;
	       return true;
	}
	       	
	return true;
}

bool LinkedList::insertAfterCursor( int newDataItem )
{
       if( isEmpty())
       {
       	cursor = new ListNode(newDataItem, NULL);
	       head = cursor;
	       size++;
	       return true;
       }
       else if(!isFull())
       {
       	ListNode* temp = new ListNode(newDataItem, cursor->next);
       	cursor->next = temp; 
              size++;
              cursor = temp; 
       	return true;
       }
       else{
       	return false;
       }
}

bool LinkedList::replaceBeforeCursor( int newDataItem ){
       if (!isEmpty())
       {
              goToPrior();
       	cursor->dataItem = newDataItem;
       	goToNext();
              return true;
       }
       else
       {
              return false;
       }
}  

bool LinkedList::replaceAtCursor( int newDataItem )
{
       if (!isEmpty())
       {
              cursor->dataItem = newDataItem;    
              return true;
       }
       else
       {
              return false;
       }
       	
}

bool LinkedList::replaceAfterCursor( int newDataItem )
{
       if (!isEmpty())
       {
              goToNext();
              cursor->dataItem = newDataItem;
              goToPrior(); 
              return true;
       }
       else
       {
              return false;
       }
}

bool LinkedList::removeAtCursor( int &dataVal )
{
       if ( !isEmpty() )
       {
              dataVal = cursor->dataItem;
              if(cursor == head)
              {
                     head = head->next; 
                     delete cursor;
                     cursor = head; 
              }
              else
              {
                     ListNode* temp = cursor->next;
                     ListNode* temp2 = cursor;
                     goToPrior();
                     cursor->next = temp; 
                     goToNext();
                     delete temp2;
              }
              size--; 
              return true;
       }
       else
       {
              return false;
       }

}

void LinkedList::clear()
{
       size = 0;
       if(!isEmpty())
       {
              cursor = head;
              while(cursor != NULL)
              {
                     cursor = cursor->next; 
                     delete head;
                     head = cursor; 
              }
              head = NULL;
              cursor = NULL;
       }
}
       
LinkedList& LinkedList::isAssigned( const LinkedList& other )
{
       ListNode* otherPoint;
       ListNode* temp; 

       if (other.isEmpty())
       {
              this->cursor = NULL;
              this->head = NULL;
              this->capacity = other.capacity;
              this->size = 0;
       }
       else
       {
              otherPoint = other.head;
              while(otherPoint != NULL)
              {
                     temp = new ListNode(otherPoint->dataItem, NULL);
                     if (this->isEmpty())
                     {
                            this->head = temp;
                            this->cursor = temp;
                     }
                     else
                     {
                            this->cursor->next = temp;
                            this->cursor = this->cursor->next; 
                     }
                     otherPoint = otherPoint->next;
                     this->size++;
              }
              this->goToBeginning();  
       }
       return *this;
}

LinkedList& LinkedList::operator = ( const LinkedList& other )
{
       return isAssigned(other);
}

bool LinkedList::getDataAtCursor( int &dataVal ) const
{
       if (!isEmpty())
       {
              dataVal = cursor->dataItem;
              return true;
       }
       else
       {
              return false;
       }
}

void LinkedList::showStructure( char listID ) const
{
       if(!isEmpty())
       {
              ListNode *temp = head;
              cout << "  List " << listID << " (" << size << "/" << capacity << "): ";
              while (temp != NULL)
              {
                     if (temp == cursor)
                     {
                            cout << "[";
                     }

                     cout << temp->dataItem; 

                     if (temp == cursor)
                     {
                            cout << "]";
                     }
                     cout << " " ; 
                     temp = temp->next; 
              }
              cout << endl;
       }
       else{
              cout << "  Empty list" << endl; 
       }
}

bool LinkedList::isEmpty() const
{
       if ( head == NULL)
       {
              return true;
       }
       else
       {
              return false;
       }
}

bool LinkedList::isFull() const
{
       if ( size == capacity)
       {
       	return true;
       }
       else
       {
       	return false;
       }
}

bool LinkedList::goToBeginning()
{
       if (!isEmpty())
       {
       	cursor = head;
       	return true;
       }
       else
       {
       	return false;
       }
}

bool LinkedList::goToEnd()
{
       if (!isEmpty())
       {
       	while (cursor->next != NULL)
              {
       		cursor = cursor->next; 
       	}
       	return true;
       }
       else{
       	return false;
       }
}

bool LinkedList::goToNext()
{
       if (!isEmpty() && cursor->next != NULL)
       {
       	cursor = cursor->next; 
       	return true;
       }
       else
       {
       	return false;
       }
}

bool LinkedList::goToPrior()
{
       if(cursor != head)
       {
              ListNode *temp = cursor;
              cursor = head; 
              while(cursor->next != temp)
              {
                     cursor = cursor->next; 
              }
              return true; 
       }
       else{
              return false; 
       }
}