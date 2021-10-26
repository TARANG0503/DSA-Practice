/*
Problem Statement: x to the power n
Problem Level: EASY
Problem Description:
Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
Do this recursively.
Input format :
Two integers x and n (separated by space)
 */
#include "iostream"
using namespace std;

long pow(int num, int power){
    if(power == 1){
        return num;
    }
    if(power == 0){
        return 1;
    }
    return num*pow(num,power-1);
}


int main(){
    int num, power;
    cin >> num >> power;
    cout << pow(num,power)<<endl;

}