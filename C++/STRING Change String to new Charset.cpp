#include<iostream>
using namespace std;

void newChar(char charSet[], string &str){
    int n = str.length();
    char hashChar[26];

    for(int i=0; i<27; ++i){
        hashChar[charSet[i] - 'a'] = 'a' + i;
    }

    for(int i=0; i<n; ++i){
        str[i] = hashChar[str[i] - 'a'];
    }
}

int main(){

    /*Explanation of OUTPUT
        as from char set e is at 3 and c is also at 3 according to original alphabet order, therefore according to charSet e = c;
        g = o
        r = d;
        t = e
    */
    char charSet[27] = "qwertyuiopasdfghjklzxcvbnm";
    string str = "egrt";
    newChar(charSet, str);
    cout << str;
    return 0;
}
