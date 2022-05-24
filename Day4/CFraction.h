#ifndef CFRACTION_H_INCLUDED
#define CFRACTION_H_INCLUDED

#include<iostream>
using namespace std;

// ==================================================================.
// CFraction : Class for fractions
// ==================================================================.
class CFraction
{
    private:
        int num;        //Numerator
        int den;        //Denominator
        int GCD(int a, int b);      //Greatest common divisor
        int LCM(int a, int b);      //Least common multiple

    public:
        void inputFraction();   //Input Fraction
        void printConsole();    //Print fractions to the screen
        void reduceFractions();
        friend CFraction operator+ (const CFraction&, const CFraction&);    //Support adding 2 fractions
        friend CFraction operator- (const CFraction&, const CFraction&);    //support subtracting 2 fractions
        friend CFraction operator* (const CFraction&, const CFraction&);    //support multiplying 2 fractions
        friend CFraction operator/ (const CFraction&, const CFraction&);    //support dividing 2 fractions
};

#endif // CFRACTION_H_INCLUDED
