// Introducing dynamic memory allocation and a custom vector class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DynamicCharacterArray.h"

void simplePointerAndDynamicMemoryDemo()
{
	/*Dynamic allocation for holding a single integer*/
	int* ptrToASingleInt = new int;

	*ptrToASingleInt = 5;

	std::cout << ptrToASingleInt << "\n";
	std::cout << *ptrToASingleInt << "\n"; //the asterisk acts as the "dereferencing operator" here


	/*Prompting a user for an array size (at runtime):*/
	std::cout << "Enter the size you would like for the array of integers: \n";
	int desiredArraySize;
	std::cin >> desiredArraySize;

	int* ptrToArray = new int[desiredArraySize];

	//Initialize array elements to a multiple of 2:
	for (int i = 0; i < desiredArraySize; ++i)
	{
		ptrToArray[i] = i * 2;
	}
	//look at these in MEMORY (no printing) 

}

int main()
{
	RawDynamicCharacterArray theArray; 

	theArray.push('a'); 
	theArray.push('b');
	theArray.push('c');
	theArray.push('d');
	theArray.push('e');

	theArray.push('f'); //exceeds current capacity! reallocate!



}
