#include "LinkedList.h"
#include <iostream>

LeakyLinkedList::LeakyLinkedList(const std::string infoInitiallyInTheHeadNode)
{
	LeakyLinkedList::pHead = new Node; 
	//new returns a memory address (that gets stored in pHead)
	//new also allocates memory (on the "heap")

	pHead->info = infoInitiallyInTheHeadNode; 
	pHead->pNext = nullptr; 
}



void LeakyLinkedList::insertAfter(const std::string& newInfo, const std::string& infoInPreviousNode)
{
	//first, call the "helper" method: 
	auto addressOfPreviousNode = getAddress(infoInPreviousNode);
	//NOTE: in the current implementation, helper will throw exception if "infoInPreviousNode" is NOT found
	//(to avoid nullptr exceptions)

	//Now make new Node with newInfo
	Node* pNew = new Node(newInfo, nullptr);

	//update pointers appropriately:
	pNew->pNext = addressOfPreviousNode->pNext; 
	addressOfPreviousNode->pNext = pNew;  


	//WHAT happens if we SWITCH the order of the 2 lines of code above? (students may benefit from testing this)

	//std::cout << "Did it work?\n";
	//pHead; //no purpose here - just included for "mousing over" in debug mode 
}

void LeakyLinkedList::removeNode(const std::string& infoToRemove)
{
	Node* pCurrent = pHead;
	Node* pPrevious = nullptr; //WHY do we need this (inobvious, perhaps)? 

	while (pCurrent != nullptr && pCurrent->info != infoToRemove) //SHOULD avoid nullptr exceptions due to calling getAddress above...
	{
		pPrevious = pCurrent; 
		pCurrent = pCurrent->pNext;
	}

	if (pCurrent == nullptr) throw std::runtime_error("Info you wanted to remove was not found");
	//alternative to exception throwing: you might just inform the user and then "early return" here 
	
	//pCurrent is now the address of the node with the info we want to remove (if it is not nullptr)

	//two scenarios to consider: 
	// 1)removing front node (perhaps easiest), 
	// 2) removing middle node or back node (perhaps more challenging)

	if (pCurrent == pHead)
	{
		pHead = pHead->pNext;
	}

	else //we will need to get hold of the node IN FRONT of the node to remove first:
	{
		//cut the old node out:
		pPrevious->pNext = pCurrent->pNext; //it is good to look at a picture of this or run in Debug mode	
	}

	delete pCurrent;  //prevents leaking an amount of memory ( equal to the size of the Node object )
}

void LeakyLinkedList::pushFront(const std::string& infoToInsertAtFront)
{
	Node* pNew = new Node(infoToInsertAtFront, nullptr);

	pNew->pNext = pHead; 
	pHead = pNew;

	//what happens if you SWAP the order of the two lines above??
}

void LeakyLinkedList::traverse()
{
	Node* pCurrent = pHead; //just copying a memory address here 
	while (pCurrent != nullptr)
	{
		std::cout << pCurrent->info << "\n";
		pCurrent = pCurrent->pNext; 
	}

}

Node* LeakyLinkedList::getPHead()
{
	return pHead; 
}

void LeakyLinkedList::reverseTraverse(Node* pCurrent)
{
	if (pCurrent->pNext != nullptr) //"recursive case"
	{
		reverseTraverse(pCurrent->pNext); //function calls itself ("recursion")
	}

	std::cout << pCurrent->info << "\n";	
}

Node* LeakyLinkedList::getAddress(const std::string& info)
{
	Node* pCurrent = pHead; 

	while (pCurrent!= nullptr && pCurrent->info != info)  //potential for "short circuit" evaluation!
	{
		pCurrent = pCurrent->pNext;
		//careful to avoid nullptr exceptions:
		//if (pCurrent == nullptr) break;  //use as an alternative to a compound while condition
	}

	if (pCurrent == nullptr)
	{
		throw std::runtime_error("getAddress did not find the droid you were looking for!"); //just one way of doing it
	}

	return pCurrent; 
}

Node::Node(const std::string& info, Node* pNext)
	:info(info), pNext(pNext)
{
}

SpaceHogLeakyLinkedList::SpaceHogLeakyLinkedList(const std::string& valueInitiallyInHead)
{
	pHead = new Node(valueInitiallyInHead, nullptr);
	pTail = pHead;  //so far we only have one node, so it is both first and last
}

void SpaceHogLeakyLinkedList::insertAfter(const std::string& newValue, const std::string& infoInPreviousNode)
{
	//fill this out properly, if you like
}

void SpaceHogLeakyLinkedList::pushBack(const std::string& newEndValue)
{
	Node* pNew = new Node(newEndValue, nullptr); 
	//update previous tail node's next pointer to point at this new guy: 
	pTail->pNext = pNew; 
	pTail = pNew; //pNew is the tail now
}

void SpaceHogLeakyLinkedList::popFront()
{
	//A PROPER approach should verify the list is not empty (pHead != nullptr) first!
	
	//briefly: just move pHead forward one step:
	pHead = pHead->pNext;

	/*NOTE that the non-leaky way is: */
	//Node* temp = pHead; 
	//pHead = pHead->pNext; 
	//delete temp; //deallocates the memory occupied by the previous head (which is no longer in the list)
	/*Or just use smart pointers to nodes instead of raw pointers*/
}

std::string SpaceHogLeakyLinkedList::peekFront()
{
	return pHead->info;
}
