/*
 * C++ program to perform celsius to fahrenheit conversion
 */
#include<iostream>
using namespace std;
 
int main()
{
    float fahrenheit, celsius;
 
    cout << "Enter the temperature in Celsius : ";
    cin >> celsius;
    fahrenheit = (celsius * 9.0) / 5.0 + 32;
    cout << "The temperature in Celsius    : " << celsius << endl;
    cout << "The temperature in Fahrenheit : " << fahrenheit << endl;
    return 0;
}
