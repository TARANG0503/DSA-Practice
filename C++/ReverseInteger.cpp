//QUESTION: reverse digits of a number

//123 -> 321

//We put extra conditions to check overflow

//Code-

#include<bits/stdc++.h>
using namespace std;

int reverse(int x) {
        int rev=0;
        for(int i=x;i!=0;i=i/10)
        {
            int d=i%10;
            if(rev>INT_MAX/10 || (rev==INT_MAX/10 && d>7)) return 0; 
            if(rev<INT_MIN/10 || (rev==INT_MIN/10 && d<-8)) return 0; 
            rev=rev*10 +d;
        }
        return rev;
        
    }

int main()
{
    int n;
    cin>>n;
    
    cout<<reverse(n);
}