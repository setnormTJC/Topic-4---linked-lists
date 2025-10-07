#include "DynamicCharacterArray.h"
#include <iostream>

/***************The "raw" implementation section*******************************/
void RawDynamicCharacterArray::push(const char characterToPush)
{
	if (current_size == max_capacity)
	{
		const int SCALING_FACTOR = 2; //double the amount of accessible memory (greedy)

		//rawPtrToDynamicCharList = new char[max_capacity * 2]; //NO! You will "lose" your old data!
		char* ptrToLargerChunkOfMemory = new char[max_capacity * SCALING_FACTOR]; 
		//char* ptrToLargerChunkOfMemory = new char[max_capacity + 1]; //Very conservative

		//copy the contents of the "old" array:
		for (int i = 0; i < max_capacity; ++i)
		{
			ptrToLargerChunkOfMemory[i] = rawPtrToDynamicCharList[i];
		}

		//delete (deallocate) the old "chunk" of memory (lest a memory leak)
		delete [] rawPtrToDynamicCharList; //fixed this after lecture!

		//assign member variable (which "lives" beyond this function) the same address as the new chunk: 
		rawPtrToDynamicCharList = ptrToLargerChunkOfMemory; 

		//update max_capacity
		max_capacity *= SCALING_FACTOR;
	}

	//finally, put the new value in place and update the size member variable: 
	rawPtrToDynamicCharList[current_size] = characterToPush;
	current_size++; 
	
}

RawDynamicCharacterArray::~RawDynamicCharacterArray()
{
	delete[] rawPtrToDynamicCharList;
	std::cout << "Destructor of RawDynamicCharacterArray called\n";
}


//This pragma region thing is an optional (and NON-PORTABLE) "goody" used for "code folding"
#pragma region Smart 
/*******************************************The "smart" implementation section:*************************/
void SmartDynamicCharacterArray::push(const char characterToPush)
{
	if (current_size == max_capacity)
	{
		std::cout << "Please sir (Mr. Operating System), I want some more (memory).\n"; //Oliver Twist ref.
		
		//To be greedy or conservative - that is the question!
		std::unique_ptr <char[]> ptrToBiggerChunkOfMemory = std::make_unique<char[]>(current_size * 2); //greedy!
		//std::unique_ptr <char[]> ptrToBiggerChunkOfMemory = std::make_unique<char[]>(current_size + 1); //conservative

		//Now copy contents of old array into the new location: 
		for (int i = 0; i < current_size; ++i)
		{
			ptrToBiggerChunkOfMemory[i] = smartPtrToDynamicCharList[i]; 
		}

		//Finally, set the member variable (which lives beyond this function) equal to the new memory address: 
		//smartPtrToDynamicCharList = ptrToBiggerChunkOfMemory; 
		//not allowed! (the copy constructor is DELETED in unique_ptr)

		//the correct alternative (std::move() feels a bit complicated): 
		smartPtrToDynamicCharList = std::move(ptrToBiggerChunkOfMemory);
	}

	smartPtrToDynamicCharList.operator[](current_size) = characterToPush;
	current_size++; 
}

/*Note that no custom destructor is needed! No memory leaks with smart pointer (std::unique_ptr)*/
#pragma endregion 