#include <iostream>
#include "ListNode.h"

//constructor
ListNode::ListNode( int nodeData, ListNode* nextPtr){
	dataItem = nodeData;
	next = nextPtr;
}

