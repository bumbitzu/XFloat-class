#include <iostream>
#include "XFloat.h"
using namespace std;
// Factorial
XFloat factorial(XFloat n)
{
    if (n == "0")
        return "1";
    return n * factorial(n - "1");
}

//Finding pi
XFloat findPi(XFloat circumference, XFloat diameter)
{
    XFloat pi;
    // Important! Set precision if result might be a float with infinite decimal digits like pi
    pi.setPrecision(10);
    pi = circumference / diameter;
    return pi;
}

// Print
void printFactorial(XFloat n)
{
    XFloat fac = "1";
    fac = factorial(n);
    cout << "Factorial of " << n << " is " << fac << endl;
}
void printPi(XFloat circumference, XFloat diameter)
{
    XFloat pi = findPi(circumference, diameter);
	cout << char(-29) << " " << char(-9) << " ";
	cout << pi;
}
int main() {
	try
	{
		printFactorial("30");
		printPi("1000000000", "318309886.18");
	}
	catch (const char* c)
	{
		cout << c;
	}
    return 0;

}