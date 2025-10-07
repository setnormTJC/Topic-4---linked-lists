#pragma once
#include <iostream>

#include<memory> 

#include "DynamicCharacterArray.h"

void demoSmartPointerNOMemoryLeak()
{
	while (true)
	{
		std::unique_ptr<int> ptr = std::make_unique<int>(1); 
	}

}


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
	std::cout << "Did it work\n";


}

/*Use with CAUTION!*/
void demoRawPointerMemoryLeak()
{
	while (true)
	{
		int* ptrToInt = new int; //"naked" new 
		delete ptrToInt; //uncomment to prevent memory leak!

		//delete "deallocates" memory (it gives it back to the OS)
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


	theArray.push('z'); 
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

void demoNOMemoryLeakWithSmartDynamicCharArray()
{
	while (true)
	{
		SmartDynamicCharacterArray aSmartDynamicCharacterArray; 
		//no call to delete (in a custom destructor)? No problem!
	}
}
