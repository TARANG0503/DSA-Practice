/*
Problem Statement: Check if the Brackets are Balanced
Problem Level: MEDIUM
Problem Description:
For a given a string expression containing only round brackets or parentheses, check if they are balanced or not.
Brackets are said to be balanced if the bracket which opens last, closes first.
Example:
Expression: (()())
Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.

You need to return a boolean value indicating whether the expression is balanced or not.
Note:
The input expression will not contain spaces in between.
*/
#include "iostream"
#include "stack"
using namespace std;
bool balanced(string s){
    stack<char> s1;
    for(int i =0;i<s.length();i++){
        if(s[i] == '('){
            s1.push(')');
        } else if(s[i]=='{'){
            s1.push('}');
        }else if(s[i] == '['){
            s1.push(']');
        }else if(!(s1.empty()) || s[i] == s1.top()){
            s1.pop();
        } else{
            return false;
        }
    }
    return s1.empty();
}
int main(){
    string s = "{()}";
    if(balanced(s)){
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }
}