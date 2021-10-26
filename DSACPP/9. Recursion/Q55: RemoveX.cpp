/*
Problem Statement: Remove X
Problem Level: MEDIUM
Problem Description:
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S
*/
#include "iostream"
using namespace std;
void removeX(char str[], int counter=0){
    if(str[counter] == '\0'){
        return;
    }
    if(str[counter] == 'x'){
        int i =counter;
        for(;str[i]!='\0';i++){
            str[i] = str[i+1];
        }
        str[i] = '\0';
    }
    counter++;
    removeX(str,counter);
}
int main(){
    int len;
    cin >> len;
    char *str = new char[len];
    cin>>str;
    removeX(str);
    cout << str<<endl;
}