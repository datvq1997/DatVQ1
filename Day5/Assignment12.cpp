#include "Assignment12.h"

//**********************************************************
// Name:         Cstack
// Description:  Constructor of Cstack class
// Arguments:	 size: Size of stack
// Return:		 Object stack.
//**********************************************************
template <typename T> Cstack<T>::Cstack(int size)
{
	Csize = size;
	Cptr = new T[Csize];
	memset(Cptr, NULL, sizeof(T) * Csize);
	CcountElement = 0;
}

//**********************************************************
// Name:		push
// Description:	Add an element to the top of the stack
// Arguments:	element: The element will be added to the stack
// Return:		FULLSTACK : Stack is full, cannot add elements
//				OK : Add success element
//				ERROR : Add element failed
//**********************************************************
template <typename T> STATUS Cstack<T>::push(T element)
{
	if (CcountElement == Csize)
	{
		return FULLSTACK;
	} 
	else if (Cptr)
	{
		*Cptr = element;
		Cptr++;
		CcountElement++;
		return OK;
	}
	return ERROR;
}

//**********************************************************
// Name:		pop
// Description: Get the element at the top of the stack
// Arguments:	buf: Buffer to store the retrieved element
// Return:		STACKEMPTY : Stack is empty
//				OK : Add success element
//				ERROR : Add element failed
//**********************************************************
template <typename T> STATUS Cstack<T>::pop(T &buf)
{
	if (CcountElement == 0)
	{
		return STACKEMPTY;
	}
	else if (Cptr)
	{
		Cptr--;
		buf = *Cptr;
		*Cptr = NULL;
		CcountElement--;
		return OK;
	}
	return ERROR;
}

int main()
{
	Cstack<int> A(10);

	A.push(1);
	A.push(2);
	A.push(3);

	int buffer;
	A.pop(buffer);
	cout << "Element of pop: " << buffer << endl;
 }