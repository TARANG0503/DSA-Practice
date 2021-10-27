/*
 * Subsequence of a string
 */
#include "iostream"
#include "math.h"
using namespace std;

int subsequence(string str, string output[]){
    if(str.empty()){
        output[0] = "";
        return 1;
    }
    string smallString = str.substr(1);
    int shortOutput = subsequence(smallString,output);
    for(int i =0;i<shortOutput;i++){
        output[i+shortOutput] = str[0] + output[i];
    }
    return 2* shortOutput;
}

int main(){
    string str;
    cin >> str;
    int len = pow(2,str.length());
    string*output = new string[len];
    subsequence(str,output);
    for(int i=0;i<len;i++){
        cout<<output[i]<<endl;
    }

}