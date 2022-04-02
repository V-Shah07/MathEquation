#include <stdio.h>
#include "LinkedLists.h"
#include "StacksQueues.h"
//constructors
Stack::Stack(int size) : model(size)
{

}
Stack::Stack(int size, void* value) : model(size, value)
{

}

//remove and adding functions
node* Stack::push(void* val)
{
	return model.addToTail(val);
}
node* Stack::pop()
{
	return model.removeFromTail();
}

//getters
int Stack::getNumNodes()
{
	return model.getCurNodeCt();
}
node* Stack::getHead()
{
	return model.getHead();
}
node* Stack::getTail()
{
	return model.getTail();
}


//constructors

Queue::Queue(int size) : model(size)
{

}

Queue::Queue(int size, void* val) : model(size, val)
{

}

//remove and adding functions

node* Queue::enqueue(void* val)
{
	return model.addToTail(val);
}

node* Queue::dequeue()
{
	return model.removeFromHead();
}

//getters

int Queue::getNumNodes()
{
	return model.getCurNodeCt();
}
node* Queue::getHead()
{
	return model.getHead();
}
node* Queue::getTail()
{
	return model.getTail();
}

