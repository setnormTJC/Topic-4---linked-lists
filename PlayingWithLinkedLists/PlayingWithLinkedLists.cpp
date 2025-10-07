// PlayingWithLinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


class RawNode
{
public: 
    std::string dataOfInterest{}; 
    RawNode* addressOfNextNode{}; //braces initialize the address to nullptr (0x0)
};

/*No memory leaks here!*/
class SmartNode
{
public: 
    std::unique_ptr<SmartNode> addressOfNextNode; 
    std::string dataOfInterest{};
};

int main()
{
    //One way to make a linked list of 2 nodes: 
    //RawNode head; 
    
    //RawNode tail; 

    //head.addressOfNextNode = &tail; 

    /*Another way to make a linked list of 2 nodes*/
    RawNode* pHead  = new RawNode;

    pHead->addressOfNextNode = nullptr; 
    pHead->dataOfInterest = "Alice"; 

    RawNode* pTail = new RawNode; 
    pTail->dataOfInterest = "Bob"; 

    pHead->addressOfNextNode = pTail; 

  
}

