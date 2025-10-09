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

void LeakyLinkedList::insert(const std::string& valueToInsert)
{
	//to be filled in later 
}

void LeakyLinkedList::pushBack(const std::string& valueToInsertAtBack)
{
	Node* pNew = new Node(valueToInsertAtBack, nullptr);

	Node* pCurrent = pHead; 

	while (pCurrent->pNext != nullptr)
	{
		pCurrent = pCurrent->pNext; 
	}

	pCurrent = pNew; //... peters out 

	//NOPE! This ain't it!

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
