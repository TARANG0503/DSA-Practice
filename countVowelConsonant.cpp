#include <iostream>
#include <set>
using namespace std;

int main() {
    cout<<"Enter a string to find the number of vowel and consonant"<<endl;
    string s;
    getline(cin, s);
    set<char> vowels;
    vowels.insert('a');
    vowels.insert('e');
    vowels.insert('i');
    vowels.insert('o');
    vowels.insert('u');
    //Capital alphabets
    vowels.insert('A');
    vowels.insert('E');
    vowels.insert('I');
    vowels.insert('O');
    vowels.insert('U');
    int vowel = 0;
    int consonant = 0;
    for(int i = 0; i < s.length(); i++) {
        if((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90)) {
            if(vowels.count(s[i]) == 1) {
                vowel++;
            }
            else {
                consonant++;
            }
        }
    }
    cout<<"The number of vowels are "<<vowel<<endl;
    cout<<"The number of consonants are "<<consonant<<endl;
}