#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "LinkedLists.h"

//constructors
LinkedList::LinkedList(int size)
{
	curNode = 0;
	head = NULL;
	tail = NULL;
	tokenSize = size;
}
LinkedList::LinkedList(int size, void* val)
{

	curNode = 1;
	tokenSize = size;

	node* element = (node*)malloc(sizeof(node*));
	element->next = element->prev = NULL;
	element->token = (void*)malloc(tokenSize);
	element->token = val;

	head = tail = element;
}


//removing and adding functions
node* LinkedList::addToTail(void* val)
{
	node* new_node = (node*)malloc(sizeof(node*));
	new_node->token = (void*)malloc(tokenSize);
	new_node->token = val;
	new_node->next = NULL;
	new_node->prev = tail;

	if (tail != NULL)
		tail->next = new_node;
	if (head == NULL) //head being NULL means that the linked lists is empty, and this is the first node getting pushed on.
			 //therefore, must make head AND tail point to it
	{
		head = new_node;
	}

	tail = new_node;
	++curNode;
	return new_node;
}

node* LinkedList::removeFromTail()
{
	if (tail == NULL)
	{
		return NULL;
	}
	node* returnValue = tail;
	tail = tail->prev;

	--curNode;
	if (tail == NULL)
	 //tail is NULL. That means that when setting tail to previous, it became NULL, meaning that the one we are trying to pop is the last element.
		  //Therefore, we have to set both the head to NULL as well to make sure the list is represented as empty!
	{

		head = NULL;
		
	}
	return returnValue;
}
node* LinkedList::removeFromHead()
{
	if (head == NULL)
	{
		return NULL;
	}
	node* returnValue = head;
	head = head->next;
	
	--curNode;
	if(head == NULL) //head is null, this means when setting the head to the next element, it became NULL, meaning the one we are trying to dequeue is the last element.
		 //Therefore, we have to set the Tail to NULL as well to make sure the list is represented as empty!
	{
		tail = NULL;
		
	}
	return returnValue;

	
}


//getters
int LinkedList::getCurNodeCt()
{
	return curNode;
}
node* LinkedList::getHead()
{
	return head;
}
node* LinkedList::getTail()
{
	return tail;
}




