/*
Problem Statement: Staircase
Problem Level: EASY
Problem Description:
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time.
Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.
Input format :
Integer N
Output Format :
Integer W
 */
#include "iostream"
using namespace std;
int stairCase(int num){
    if(num == 1){
        return 1;
    }
    if(num ==2){
        return 2;
    }
    if(num == 3){
        return 4;
    }
    return stairCase(num-1) + stairCase(num-2) + stairCase(num-3);
}

int main(){
    int num;
    cin >> num;
    cout << stairCase(num)<<endl;
}