#pragma once
#include <iostream>
#define ERROR 0
#define OK 1
#define FULLSTACK 2
#define STACKEMPTY 3
#define STATUS int

using namespace std;

// ==================================================================.
// Cstack : Class for stack
// ==================================================================.
template <typename T> class Cstack
{
private:
	int Csize;					//Size of stack
	T* Cptr;					//Pointer to element of stack
	int CcountElement;			//The current number of elements in the Stack
public:
	Cstack(int size);			//Constructor

	STATUS push(T element);		//Add an element to the top of the stack
	STATUS pop(T &buf);			//Get the element at the top of the stack

};