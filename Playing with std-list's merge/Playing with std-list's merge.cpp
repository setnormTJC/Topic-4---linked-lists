// Playing with std-list's merge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<list> 
#include <iostream>

int main()
{
    std::list<int> l1 = { 15, 3, 5, 7 }; 
    std::list<int> l2 = { 2, 4, 6 };

    l1.merge(l2); //throws sequence not ordered in DEBUG mode!
                    //(if, for example, l1 = {15, 3, 5, 7} )

    for (const auto& num : l1)
    {
        std::cout << num << "\n";
    }
    //std::cout << "Hello World!\n";
}

