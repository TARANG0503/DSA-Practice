/*
Fahrenheit to Celsius Table
Given three values - Start Fahrenheit Value (S), End Fahrenheit value (E) and Step Size (W),
you need to convert all Fahrenheit values from Start to End at the gap of W, into their corresponding Celsius values and print the table.
Input Format :
3 integers - S, E and W respectively
Output Format :
Fahrenheit to Celsius conversion table. One line for every Fahrenheit and Celsius Fahrenheit value.
 Fahrenheit value and its corresponding Celsius value should be separate by tab ("\t")
*/

#include "iostream"
using namespace std;

double FahrenheitToCelsius(double f){
    return (f-32.0)/1.8;;
}

int main(){
    int start;
    int end;
    int gap;
    cin >> start >> end >> gap ;
    while(start!= end){
        cout << start<<"\t"<<(int) FahrenheitToCelsius(start) << endl;
        start+=gap;
    }
}