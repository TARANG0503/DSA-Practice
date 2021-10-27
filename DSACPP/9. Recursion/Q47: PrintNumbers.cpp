/*
Problem Statement: Print numbers
Problem Level: EASY
Problem Description:
Given is the code to print numbers from 1 to n in increasing order recursively. But it contains few bugs that you need to rectify such that all the test cases pass.
Input Format :
Integer n
Output Format :
Numbers from 1 to n (separated by space)
 */
#include "iostream"
using namespace std;

void printNumbers(int n,int counter =1){
    if(counter>n){
        return;
    }
    cout << counter<<" ";
    counter++;
    printNumbers(n,counter);
}

int main(){
    int n;
    cin >> n;
    printNumbers(n);
    cout << endl;
}