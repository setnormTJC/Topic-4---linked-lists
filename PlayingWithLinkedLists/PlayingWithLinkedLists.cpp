// PlayingWithLinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"demos.h"
#include "LinkedList.h"
#include <forward_list>

int main()
{

    try
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
    }

    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n";

    }
}

