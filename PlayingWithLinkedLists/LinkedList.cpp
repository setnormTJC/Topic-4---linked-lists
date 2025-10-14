#include "LinkedList.h"
#include <iostream>

LeakyLinkedList::LeakyLinkedList(const std::string valueInitiallyInTheHeadNode)
{
	LeakyLinkedList::pHead = new Node; 
	//new returns a memory address (that gets stored in pHead)
	//new also allocates memory (on the "heap")

	pHead->info = valueInitiallyInTheHeadNode; 
	pHead->pNext = nullptr; 
}

void LeakyLinkedList::insertAfter(const std::string& newValue, const std::string& valueToInsertAfter)
{
	//first, allocate space for the node we are inserting 
	Node* pNew = new Node(newValue, nullptr);

	//now find the memory address of the node containing `valueToInsertAfter`
	Node* pCurrent = pHead; 

	while (pCurrent->pNext->info != valueToInsertAfter)
	{
		pCurrent = pCurrent->pNext;
	}
	
	pNew->pNext = pCurrent->pNext; //there's a fair bit to "unpack" here!
	pCurrent->pNext = pNew;


	//What happens if we SWITCH the order of the 2 lines of code above? 

}



void LeakyLinkedList::pushFront(const std::string& valueToInsertAtFront)
{
	Node* pNew = new Node(valueToInsertAtFront, nullptr);

	pNew->pNext = pHead; 
	pHead = pNew;

	//what happens if you SWAP the order of the two lines above??
}

void LeakyLinkedList::traverse()
{
	//this is the "array-like" traversal algorithm 
	//for (int i = 0; i <= numberOfNodesInList - 1; ++i)
	//{
	//	std::cout << pHead[i]... (note that this won't work)
	//}
	Node* pCurrent = pHead; //just copying a memory address here 
	while (pCurrent != nullptr)
	{
		std::cout << pCurrent->info << "\n";
		pCurrent = pCurrent->pNext; 
	}

	//Q: Why not this way??
	//while (pHead != nullptr)
	//{
	//	std::cout << pHead->info << "\n";
	//	pHead = pHead->pNext;
	//}
	//A: You "lose your head" this way
	//Keep your head while all about you are losing theirs. 
}

Node::Node(const std::string& info, Node* pNext)
	:info(info), pNext(pNext)
{
}
