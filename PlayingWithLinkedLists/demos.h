#pragma once
#include <string>
#include <iostream>

#include"LinkedList.h"


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

void demoLeakyLinkedList()
{
    LeakyLinkedList list("Frank");

    list.pushFront("Darth");
    list.pushFront("Carol");
    list.pushFront("Bob");
    list.pushFront("Alice");

    list.traverse();

    std::string valueToGetAddressOf = "Frank";

    //auto addressOfInfo = list.getAddress(valueToGetAddressOf); //getAddress marked as PRIVATE

    list.insertAfter("Eve", "Darth"); //insert Eve after Darth (obviously?)

    list.insertAfter("ZEBRA", "Frank"); //insert ZEBRA after Frank (Z follows F, of course)

    std::cout << "\n\nAfter inserting Eve and ZEBRA (in alphabetical order), list contains: \n";

    list.traverse();

    //what if we try to insert after someone who does not exist? 
    //list.insertAfter("Yet another person", "asfdasdfasdf");

    //final EDGE CASE to test - can we insert at front? 
    //(That's what pushFront is for!)

    list.removeNode("Alice"); //currently the front node 

    list.removeNode("ZEBRA"); //currently the last (tail) node

    list.removeNode("Carol");


    std::cout << "\n\n\nAfter removing Alice, ZEBRA, and Carol:\n";
    list.traverse();

    //std::forward_list<int>::

    auto pHead = list.getPHead();

    list.reverseTraverse(pHead);
}