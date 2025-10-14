// PlayingWithLinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"demos.h"
#include "LinkedList.h"
#include <forward_list>

int main()
{

    LeakyLinkedList list("Alice");

    list.pushFront("Bob"); 
    list.pushFront("Carol");
    list.pushFront("Darth");
    list.pushFront("Frank");

    list.traverse();

    list.insertAfter("Eve", "Darth"); //insert Eve after Darth (obviously?)

    list.insertAfter("ZEBRA", "Frank"); //insert ZEBRA after Frank 

    std::cout << "\n\nAftering adding Eve after Darth, list contains: \n";

    list.traverse(); 

    //std::forward_list<int>::insert_after()
}

