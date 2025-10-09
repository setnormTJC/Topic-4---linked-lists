// PlayingWithLinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"demos.h"
#include "LinkedList.h"

int main()
{

    LeakyLinkedList list("Alice");

    //list.pushBack("Bob"); 
    //list.pushBack("Carol");
    //list.pushBack("Darth");

    list.pushFront("Bob"); 
    list.pushFront("Carol");
    list.pushFront("Darth");

    list.traverse(); 

}

