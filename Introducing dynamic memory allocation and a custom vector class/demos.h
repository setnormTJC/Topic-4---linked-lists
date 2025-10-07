#pragma once
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

/*Use with CAUTION!*/
void demoRawPointerMemoryLeak()
{
	while (true)
	{
		int* ptrToInt = new int; 
		//delete ptrToInt; //uncomment to prevent memory leak!
	}
}

void demoSimpleDynamicCharacterArray()
{
	RawDynamicCharacterArray theArray;

	theArray.push('a');
	theArray.push('b');
	theArray.push('c');
	theArray.push('d');
	theArray.push('e');

	theArray.push('f'); //exceeds current capacity! reallocate!

}

/*If `RawDynamicCharacterArray` has no DESTRUCTOR that calls `delete`, this function "leaks"!*/
void demoMemoryLeakWithRawDynamicCharArray()
{
	while (true)
	{
		RawDynamicCharacterArray aDynamicCharacterArray;
		//NOTE: this object will get DESTROYED when the close brace is hit (it goes out of scope)
	}
}
