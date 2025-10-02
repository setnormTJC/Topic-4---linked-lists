#pragma once
#include <memory>

class DynamicCharacterArrayADT
{
public: 
	virtual void push(const char characterToPush) = 0;
};

/*"Raw" means "naked/raw" pointers are used in the implementation*/
class RawDynamicCharacterArray : public DynamicCharacterArrayADT
{
private:
	int max_capacity = 5; //how many characters our dynamic array can hold
	char* rawPtrToDynamicCharList = new char[max_capacity]; 
	int current_size = 0; //how many characters our dynamic array is CURRENTLY holding 


public: 
	RawDynamicCharacterArray() = default; 

	void push(const char characterToPush);
};

/*"Smart" means "smart pointers" are used -> no memory leaks*/
class SmartDynamicCharacterArray : public DynamicCharacterArrayADT
{
	std::unique_ptr<char> smartPtrToDynamicCharList = nullptr; //requires <memory> 

};