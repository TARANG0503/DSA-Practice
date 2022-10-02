#include <bits/stdc++.h>
using namespace std;
void insert(stack<int> &s,int val)
{
    if(s.empty() or s.top()<=val)
    {s.push(val);return;}
    int last=s.top();
    s.pop();
    insert(s,val);
    s.push(last);
}
void sort(stack<int> &s){
    if(!s.empty())
   {
       int x=s.top();
       s.pop();
       sort(s);
       insert(s,x);
   }
 }
 void print(stack<int> &s)
 {
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
 }
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        stack<int> s;
        for (int i = 0; i < n; i++)
           { int x;
           cin>>x;
             s.push(x);}
        
         stack<int> s1;
   while(!s.empty())
   {
       int x=s.top();
       s.pop();
       while(!s1.empty() and s1.top()>x)
       {
        s.push(s1.top());
        s1.pop();
       }
       s1.push(x);
       
   }
   s=s1;
       // sort(s);
        print(s);
    }
    return 0;
}