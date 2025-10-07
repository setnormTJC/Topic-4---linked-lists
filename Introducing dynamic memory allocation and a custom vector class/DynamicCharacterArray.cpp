#include "DynamicCharacterArray.h"
#include <iostream>

void RawDynamicCharacterArray::push(const char characterToPush)
{
	if (current_size == max_capacity)
	{
		rawPtrToDynamicCharList = new char[max_capacity * 2]; //greedy to ask for double the space (not conservative)

		//copy the contents of the "old" array: 
	}

	else //we've still got space remaining (size < capacity)
	{
		rawPtrToDynamicCharList[current_size] = characterToPush;

		current_size++; 
	}
}

RawDynamicCharacterArray::~RawDynamicCharacterArray()
{
	delete[] rawPtrToDynamicCharList;
	std::cout << "Destructor of RawDynamicCharacterArray called\n";
}



/*******************************************BEGIN the "smart" section:*************************/
void SmartDynamicCharacterArray::push(const char characterToPush)
{
	if (current_size == max_capacity)
	{
		//reallocate - smart pointer will clean up after itself
		
		//fill me in!
	}

	else
	{
		smartPtrToDynamicCharList
	}
}

