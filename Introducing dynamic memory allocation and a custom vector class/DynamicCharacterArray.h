#pragma once
#include <memory> //for "smart" pointers (called std::unique_ptr)

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

	/*pushes at the BACK*/
	void push(const char characterToPush);

	/*If using raw (AKA: "naked") pointers, you should define a custom destructor function
	* This relates to something called the "Rule of 5" in C++
	*/
	~RawDynamicCharacterArray(); 
};

/*"Smart" means "smart pointers" are used -> no memory leaks*/
class SmartDynamicCharacterArray : public DynamicCharacterArrayADT
{
private: 
	int max_capacity = 5;
	int current_size = 0; 
	std::unique_ptr<char[]> smartPtrToDynamicCharList = std::make_unique<char[]>(max_capacity); //requires <memory> 
	//NOTE the "funny" syntax for the template param -> char[]

public: 
	SmartDynamicCharacterArray() = default; 
	void push(const char characterToPush);
};