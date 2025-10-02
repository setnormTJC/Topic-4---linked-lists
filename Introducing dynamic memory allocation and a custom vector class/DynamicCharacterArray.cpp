#include "DynamicCharacterArray.h"

void RawDynamicCharacterArray::push(const char characterToPush)
{
	if (size == capacity)
	{
		rawPtrToDynamicCharList = new char[capacity * 2]; //greedy to ask for double the space (not conservative)

		//copy the contents of the "old" array: 
	}

	else //we've still got space remaining (size < capacity)
	{
		rawPtrToDynamicCharList[size] = characterToPush;

		size++; 
	}
}
