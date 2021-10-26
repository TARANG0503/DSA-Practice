/*
Problem Statement: Number of digits
Problem Level: EASY
Problem Description:
Given the code to find out and return the number of digits present in a number recursively.
But it contains few bugs, that you need to rectify such that all the test cases should pass.
Input Format :
Integer n
Output Format :
Count of digits
*/
#include "iostream"
using namespace std;

int digits(int num){
    if(num == 0){
        return 0;
    }
    if(num<10){
        return 1;
    }
    return 1 + digits(num/10);

}


int main(){
    int num;
    cin >> num;
    if(num<0){
        cout << digits(-num)<<endl;
    }else{
        cout << digits(num)<<endl;
    }

}