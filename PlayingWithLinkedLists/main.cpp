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
        demoLeakyLinkedList(); 

    }

    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n";

    }
}

