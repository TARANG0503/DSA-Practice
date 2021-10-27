/*
*Fibonacci Number
Given a number N, figure out if it is a member of fibonacci series or not. Return true if the number is member of fibonacci series else false.
Fibonacci Series is defined by the recurrence
F(n) = F(n-1) + F(n-2)
where F(0) = 0 and F(1) = 1
*/

#include "iostream"
using namespace std;

bool fibonacci(int n){
    int last = 0;
    int current = 1;
    while(n>current){
        int temp = current;
        current = current+last;
        last = temp;
        if(current==n){
            return true;
        }
    }
    return false;
}
int main(){
    int number ;
    cin >> number;
    if(fibonacci(number)){
        cout << "true";
    }else{
        cout <<"false";
    }
    cout << endl;
}