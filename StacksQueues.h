#include "LinkedLists.h"

#ifndef __StacksQueues__

#define __StacksQueues__


struct Stack
{
private:
	LinkedList model;
public:

	//constructs
	Stack(int size);
	Stack(int size, void* val);

	//remove and adding functions
	node* push(void* val);
	node* pop();
	//getters
	int getNumNodes();
	node* getHead();
	node* getTail();

};

struct Queue
{

private:
	LinkedList model;
public:
	//constructors
	Queue(int size);
	Queue(int size, void* val);
	//remove and adding functions
	node* enqueue(void* val);
	node* dequeue();
	//getters
	int getNumNodes();
	node* getHead();
	node* getTail();
};

#endif

