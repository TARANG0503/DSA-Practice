/*
 * Print All Substrings
For a given input string(str), write a function to print all the possible substrings.
 */
#include "iostream"
using namespace std;

void printSub(string input, string output=""){
    if(input.length()==0){
        cout << output<<endl;
        return;
    }
    printSub(input.substr(1),output);
    printSub(input.substr(1), output + input[0]);
}
int main(){
    string input;
    cin >> input;
    printSub(input);
}