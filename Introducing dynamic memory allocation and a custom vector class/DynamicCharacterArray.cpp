#include "DynamicCharacterArray.h"

void RawDynamicCharacterArray::push(const char characterToPush)
{
	if (size == capacity)
	{
		rawPtrToDynamicCharList = new char[capacity * 2]; //greedy to ask for double the space (not conservative)

		// more to come here .. 
	}

	else //we've still got space remaining (size < capacity)
	{
		rawPtrToDynamicCharList[size] = characterToPush;

		size++; 
	}
}
