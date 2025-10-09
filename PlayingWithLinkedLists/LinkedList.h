#pragma once
#include <string>
#include <memory>



/*What operations "should" a linked list provide to a client?*/
class LinkedListADT
{
	virtual void insert(const std::string& valueToInsert) = 0;
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
	//Node* pTail; //if you have a DOUBLY-linked list (pNext and pPrevious)
	//int numberOfNodesInList; //4 bytes of unnecessary space 
public: 
	LeakyLinkedList() = default; 
	LeakyLinkedList(const std::string valueInitiallyInTheHeadNode);

	void insert(const std::string& valueToInsert); 


	void pushBack(const std::string& valueToInsertAtBack);
	void pushFront(const std::string& valueToInsertAtFront);

	/*"visits" every node in the list from head to tail*/
	void traverse(); 
};

/*No leaks - because composed of SmartNode (smart pointers)*/
class AirTightLinkedList
{

};

