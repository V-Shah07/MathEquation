#ifndef __LinkedLists__
#define __LinkedLists__

struct node
{
	node* next, * prev;
	void* token;
};
struct LinkedList
{
private:
	int curNode;
	int tokenSize;
	node* head, * tail;
public:
	//constructors
	LinkedList(int size);
	LinkedList(int size, void* val);

	node* addToTail(void* val);
	node* removeFromTail();
	node* removeFromHead();

	//getters
	int getCurNodeCt();
	node* getHead();
	node* getTail();

};



#endif



