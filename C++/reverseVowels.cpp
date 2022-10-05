#include <bits/stdc++.h>
using namespace std;
bool isVowel(char ch) {
   return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}
string reverseVowel(string &s){
   int low = 0;
   int high = s.size() - 1;
   while (low < high) {
      while (low < high && !isVowel(s[low])) {
         low ++;
      }
      while (low < high && !isVowel(s[high])) {
         high --;
      }
      swap(s[low++], s[high--]);
   }
   return s;
}
int main(){
   string a= "chiraggupta";
   string ans= reverseVowel(a);
   cout<<ans;
   return 0;
}
