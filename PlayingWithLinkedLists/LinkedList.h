#pragma once
#include <string>
#include <memory>



/*What operations "should" a linked list provide to a client?*/
class LinkedListADT
{
	/*O(1) complexity (but not really...)*/
	virtual void insertAfter(const std::string& newValue, const std::string& infoInPreviousNode) = 0;
};

/*Raw-pointer based; info in Node will be STRINGS (convenient)*/
struct Node
{
	std::string info{}; 
	Node* pNext{}; //pointer to (address of) next node in list 

	Node() = default; 
	Node(const std::string& info, Node* pNext);

};

/*Smart-pointer based (no memory leaks)*/
struct SmartNode
{
	std::string info; 
	std::unique_ptr<SmartNode> pNext; 
};

/*PROBABLY leaks - because composed of raw node (raw pointer)*/
class LeakyLinkedList : public LinkedListADT
{
private: 
	Node* pHead{}; //the address of the head node in the linked list! Hooray!
	//Node* pTail; //this allows for easier implementation of pushBack(); 
	//Node* pTail; //if you have a DOUBLY-linked list (pNext and pPrevious)
	//int numberOfNodesInList; //4 bytes of unnecessary space 
public: 
	LeakyLinkedList() = default; 
	LeakyLinkedList(const std::string infoInitiallyInTheHeadNode);

	/*O(1) AKA: constant complexity (sort of!)*/
	void insertAfter(const std::string& newInfo, const std::string& infoInPreviousNode) override;

	/*This one gets a bit complicated.
	NOTE: Does NOT handle duplicates (ex: if "alpha" appears in the list more than once)*/
	void removeNode(const std::string& infoToRemove);

	/*O(1) [AKA: constant] time complexity*/
	void pushFront(const std::string& infoToInsertAtFront);

	/*"visits" every node in the list from head to tail*/
	void traverse(); 

	Node* getPHead();

	/*An example of recursion
	* @params pCurrent -> use pHead on the initial call
	*/
	void reverseTraverse(Node* pCurrent);

private: 
	/*A little "helper" method for "insertAfter" - HIDE it from the client (main.cpp) to avoid overkill with detail*/
	Node* getAddress(const std::string& info);
};

/*It's a "space hog" because it allocates space for both front AND back nodes*/
class SpaceHogLeakyLinkedList : public LinkedListADT
{
	Node* pHead{};
	Node* pTail{};

public: 
	SpaceHogLeakyLinkedList() = default; 
	SpaceHogLeakyLinkedList(const std::string& valueInitiallyInHead); 

	void insertAfter(const std::string& newValue, const std::string& infoInPreviousNode) override;

	/*@brief O(1) complexity! To be used for queue's "enqueue" implementation (queues insert at rear (back))*/
	void pushBack(const std::string& newEndValue);
	/*@brief O(1) complexity. To be used for queue's "dequeue" (FIFO -> (front in line is first out)*/
	void popFront(); 

	/*@brief Returns, but does not remove, the person at the front of the list*/
	std::string peekFront(); 
};

/*No leaks - because composed of SmartNode (smart pointers)*/
class AirTightLinkedList
{
	//fill 'er out if your heart desires
};

