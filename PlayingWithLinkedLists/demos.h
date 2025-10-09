#pragma once
#include <string>
#include <iostream>


class RawNode
{
public:
    std::string dataOfInterest{};
    RawNode* addressOfNextNode{}; //braces initialize the address to nullptr (0x0)
};

void demoTediousWayOfMakingALinkedList()
{
    //One way to make a linked list of 2 nodes: 
    RawNode head;
    head.dataOfInterest = "Alice";

    RawNode tail;
    tail.dataOfInterest = "Bob";

    head.addressOfNextNode = &tail; //Note the "address of" operator (unary &)

    /*Another way to make a linked list of 2 nodes*/
    RawNode* pHead = new RawNode;

    pHead->addressOfNextNode = nullptr;
    pHead->dataOfInterest = "Alice";

    RawNode* pTail = new RawNode; //new must always be matched by a delete (lest a leak)
    pTail->dataOfInterest = "Bob";

    pHead->addressOfNextNode = pTail;

    std::cout << pHead->dataOfInterest << "\n"; //prints "Alice"
    std::cout << pTail->dataOfInterest << "\n"; //prints Bob

    std::cout << pHead->addressOfNextNode->dataOfInterest << "\n"; //ALSO prints Bob
}