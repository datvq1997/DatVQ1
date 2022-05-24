#include "CFraction.h"

//**********************************************************
// Name:         inputFraction
// Description:  Support for entering fractions
// Arguments:
// Return: void
//**********************************************************
void CFraction::inputFraction()
{
    cout << "Input numerator: ";
    cin >> this->num;
    cout << "Input denominator: ";
    cin >> this->den;
    while (this->den == 0)
    {
        cout << "Error denominator = 0, input again: ";
        cin >> this->den;
    }
}

//**********************************************************
// Name:         printConsole
// Description:  Print fractions to the screen
// Arguments:
// Return: void
//**********************************************************
void CFraction::printConsole()
{
    if (this->num % this->den == 0)
    {
        cout << (this->num / this->den) << endl;
    }
    else
    {
        cout << this->num << "/" << this->den << endl;
    }
}

//**********************************************************
// Name:         operator+
// Description:  Support adding 2 fractions
// Arguments:    CFraction_A: Fraction 1
//               CFraction_B: Fraction 2
// Return:       CFraction is the result of the addition.
//**********************************************************
CFraction operator+ (const CFraction& CFraction_A, const CFraction& CFraction_B)
{
    CFraction CFractionResult;
    if (CFraction_A.den != CFraction_B.den)
    {
        CFractionResult.den = CFractionResult.LCM(CFraction_A.den, CFraction_B.den);
        CFractionResult.num = CFraction_A.num * (CFractionResult.den / CFraction_A.den) + CFraction_B.num * (CFractionResult.den / CFraction_B.den);
    }
    else {
        CFractionResult.den = CFraction_A.den;
        CFractionResult.num = CFraction_A.num + CFraction_B.num;
    }
    return CFractionResult;
}

//**********************************************************
// Name:         operator-
// Description:  support subtracting 2 fractions
// Arguments:    CFraction_A: Fraction 1
//               CFraction_B: Fraction 2
// Return:       CFraction is the result of subtraction.
//**********************************************************
CFraction operator- (const CFraction& CFraction_A, const CFraction& CFraction_B)
{
    CFraction CFractionResult;
    if (CFraction_A.den != CFraction_B.den)
    {
        CFractionResult.den = CFractionResult.LCM(CFraction_A.den, CFraction_B.den);
        CFractionResult.num = CFraction_A.num * (CFractionResult.den / CFraction_A.den) - CFraction_B.num * (CFractionResult.den / CFraction_B.den);
    }
    else {
        CFractionResult.den = CFraction_A.den;
        CFractionResult.num = CFraction_A.num - CFraction_B.num;
    }
return CFractionResult;
}

//**********************************************************
// Name:         operator*
// Description:  support multiplying 2 fractions
// Arguments:    CFraction_A: Fraction 1
//               CFraction_B: Fraction 2
// Return:       CFraction is the result of multiplication
//**********************************************************
CFraction operator* (const CFraction& CFraction_A, const CFraction& CFraction_B)
{
    CFraction CFractionResult;
    CFractionResult.den = CFraction_A.den * CFraction_B.den;
    CFractionResult.num = CFraction_A.num * CFraction_B.num;
    int reduceFractions = CFractionResult.GCD(CFractionResult.den, CFractionResult.num);
    if (reduceFractions != 0)
    {
        CFractionResult.den /= reduceFractions;
        CFractionResult.num /= reduceFractions;
    }
    return CFractionResult;
}

//**********************************************************
// Name:         operator/
// Description:  support dividing 2 fractions
// Arguments:    CFraction_A: Fraction 1
//               CFraction_B: Fraction 2
// Return:       CFraction is the result of division
//**********************************************************
CFraction operator/ (const CFraction& CFraction_A, const CFraction& CFraction_B)
{
    CFraction CFractionResult;
    CFractionResult.den = CFraction_A.den * CFraction_B.num;
    CFractionResult.num = CFraction_A.num * CFraction_B.den;
    int reduceFractions = CFractionResult.GCD(CFractionResult.den, CFractionResult.num);
    if (reduceFractions != 0)
    {
        CFractionResult.den /= reduceFractions;
        CFractionResult.num /= reduceFractions;
    }
    return CFractionResult;
}

//**********************************************************
// Name:         GCD
// Description:  Find the greatest common divisor of two numbers
// Arguments:    a,b: two numbers
// Return:       int: greatest common divisor
//**********************************************************
int CFraction::GCD(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    return a;
}

//**********************************************************
// Name:         LCM
// Description:  Find the least common multiple of two numbers
// Arguments:    a,b: two numbers
// Return:       int: least common multiple
//**********************************************************
int CFraction::LCM(int a, int b)
{
    a = (abs(a * b)) / (GCD(a, b));
    return a;
}

int main()
{
    CFraction a;
    cout << "Fraction 1" << endl;
    a.inputFraction();

    CFraction b;
    cout << "Fraction 2" << endl;
    b.inputFraction();

    cout << "===== RESULT ======" << endl;
    CFraction Result;
    Result = a + b;
    cout << "Sum: ";
    Result.printConsole();

    Result = a - b;
    cout << "Sub: ";
    Result.printConsole();

    Result = a * b;
    cout << "Mul: ";
    Result.printConsole();

    Result = a / b;
    cout << "Div: ";
    Result.printConsole();
}
