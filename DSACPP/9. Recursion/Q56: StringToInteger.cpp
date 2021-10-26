/*
Problem Statement: String to Integer
Problem Level: MEDIUM
Problem Description:
Write a recursive function to convert a given string into the number it represents.
That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
 */
#include "iostream"
#include "math.h"
using namespace std;

int stringToInt(char str[],int len,int index=0){
    if(str[index] == '\0'){
        return 0;
    }
    int sr = str[index];
    index++;
    return (sr-48)*pow(10,len-index) + stringToInt(str,len,index) ;
}

int main(){
    int len;
    cin >> len;
    char *str = new char[len];
    cin >> str;
    cout << stringToInt(str,len);
}