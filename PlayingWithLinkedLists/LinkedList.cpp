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

	pCurrent = pNew; 

	//NOPE! This ain't it!

}

void LeakyLinkedList::traverse()
{
	//this is the "array-like" traversal algorithm 
	//for (int i = 0; i <= numberOfNodesInList - 1; ++i)
	//{
	//	std::cout << pHead[i]... (note that this won't work)
	//}
	Node* pCurrent = pHead; //ex: 0x1122
	while (pCurrent != nullptr)
	{
		std::cout << pCurrent->info << "\n";
		pCurrent = pCurrent->pNext; 
	}

}

Node::Node(const std::string& info, Node* pNext)
	:info(info), pNext(pNext)
{
}
