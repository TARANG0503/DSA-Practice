#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
int maxrec(int a[])
{ int ans=0;
    for(int i=0;i<7;i++)
    { int minh=a[i];
        for(int j=i;j<7;j++)
        {
              minh=min(a[j],minh);
              int l=j-i+1;
              ans=max(ans,l*minh);
        }
    }
    return ans;
}
int using_stack(int a[])
{
     stack<int> s;
   int max_area=0;
   int t;
   int area_with_top;
   int n=7;
   int i=0;
   while (i<n)
   {
     if(s.empty()||a[s.top()]<=a[i])
     {
         s.push(i++);
     }
     else
     {
         t=s.top();
         s.pop();
         if(s.empty())
         area_with_top=a[t]*i;
         else
         {
             area_with_top=a[t]*(i-s.top()-1);
         }
         if(max_area<area_with_top)
         max_area=area_with_top;

     }
     
   }
   while(!s.empty())
   {
       t=s.top();
       s.pop();
       area_with_top = a[t] * (s.empty() ? i :
                                i - s.top() - 1);
 
        if (max_area < area_with_top)
            max_area = area_with_top;
   }
 return max_area;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int a[7]={5,3,2,7,6,2,4};
//cout<<maxrec(a);       //O(n*n)
cout<<using_stack(a);   //O(n)
return 0;
}