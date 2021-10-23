/*Lapindrome is defined as a string which when split in the middle,
gives two halves having the same characters and same frequency of each character. 
If there are odd number of characters in the string, we ignore the middle character and check for lapindrome. 
For example gaga is a lapindrome, since the two halves ga and ga have the same characters with same frequency.
Also, abccab, rotor and xyzxy are a few examples of lapindromes. Note that abbaab is NOT a lapindrome. The two halves contain the same characters but their frequencies do not match.
Your task is simple. Given a string, you need to tell if it is a lapindrome.*/

#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
   cin.ignore();
   string str1,str2;
   while(t--)
   {
      string str;
      getline(cin,str);
      int l=str.length();
      int m=l/2;
      if(l%2==0)
      {
         str1=str.substr(0,m);
         str2=str.substr(m);
      }
      else
      {
         str1=str.substr(0,m);
         str2=str.substr(m+1); 
      }
      sort(str1.begin(),str1.end());
      sort(str2.begin(),str2.end());
      if(str1==str2)
      {
         cout<<"YES"<<endl;
      }
      else
      {
         cout<<"NO"<<endl;
      }
      
   }
  return 0;
}