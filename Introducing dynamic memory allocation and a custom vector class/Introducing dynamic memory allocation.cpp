// Introducing dynamic memory allocation and a custom vector class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"demos.h"



int main()
{
	//simplePointerAndDynamicMemoryDemo(); 
	//demoRawPointerMemoryLeak(); 

	//demoSmartPointerNOMemoryLeak(); 

	while (true)
	{
		demoSimpleDynamicCharacterArray(); 
	}

	//demoMemoryLeakWithRawDynamicCharArray(); 

	//demoNOMemoryLeakWithSmartDynamicCharArray(); 

	//SmartDynamicCharacterArray smartArray; 

	//smartArray.push('a'); 
	//smartArray.push('b');
	//smartArray.push('c');
	//smartArray.push('d');
	//smartArray.push('e');

	//smartArray.push('f'); //"re-allocation" will be necessary (I hardcoded the initial capacity to 5)

}
