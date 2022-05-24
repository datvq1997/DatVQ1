#include "String.h"
#define MAXSIZE 1000

//**********************************************************
// Name:         operator+ 
// Description:  string concatenation function
// Arguments:	 obj_a: object contains the string 1
//				 obj_b: object contains string concatenated to string 1
// Return:		 object contains the resulting string
//**********************************************************
String operator+ (const String& obj_a, const String& obj_b)
{
	String obj_result;
	obj_result.length = obj_a.length + obj_b.length-1;
	obj_result.str = new char [obj_result.length];
	obj_result.str = obj_a.str;
	for (int i = 0; i < obj_b.length; i++)
	{
		obj_result.str[obj_a.length+i-1] = obj_b.str[i];
	}
	return obj_result;
}

//**********************************************************
// Name:         inputFraction
// Description:  Support for entering fractions
// Arguments:	 output : The variable will contain the output data 
//				 obj: The object containing the string will be output	 
//**********************************************************
ostream& operator << (ostream& output, String& obj)
{
	output << obj.str << endl;
	return output;
}

//**********************************************************
// Name:         inputFraction
// Description:  Support for entering fractions
// Arguments:	 input : variable containing input data
//				 obj: The object containing the string will be output	 
//**********************************************************
istream& operator >> (istream& input, String& obj)
{
	obj.str = new char[MAXSIZE];
	input.getline(obj.str,MAXSIZE);
	obj.length = (int)input.tellg() - 1;
	return input;
}

int main()
{
	String str_a,str_b,str_result;
	cout << "Input string 1: ";
	cin >> str_a;
	cout << "Input string 2: ";
	cin >> str_b;
	str_result = str_a + str_b;
	cout << "String concatenation results: ";
	cout << str_result;
}