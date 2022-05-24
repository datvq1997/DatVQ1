#ifndef CFRACTION_H_INCLUDED
#define CFRACTION_H_INCLUDED

#include<iostream>
using namespace std;

// ==================================================================.
// String : Class for strings
// ==================================================================.
class String
{
private:
    char* str;        //Char array 
    int length;

public:
    friend String operator + (const String&, const String&);    //string concatenation function
    friend ostream& operator << (ostream&, String&);            //string output function
    friend istream& operator >> (istream&, String&);            //string input function
};

#endif // CFRACTION_H_INCLUDED

