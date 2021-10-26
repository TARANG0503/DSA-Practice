/*
Check Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters.
*/

#include "iostream"
using namespace std;
bool palindrome(char str[], int len){
    int index = 0;
    while(index<len/2){
        if(str[index] != str[len-index-1]){
            return false;
        }
        index++;
    }
    return true;
}
int length(char str[]){
    int len = 0;
    while(str[len]!='\0'){
        len++;
    }
    return len;
}
int main(){
    char str[100];
    cin>>str;
    int len = length(str);
    if(palindrome(str,len)){
        cout << "Palindrome " << endl;
    } else{
        cout <<"not a Palindrome " << endl;
    }
}