#include <iostream>
using namespace std;
int main()
{
int n, r, sum=0, temp;
cout<<"Enter the no. =";
cin>>n;
temp=n;
while(n>0)
{
    r=n%10;
    sum=sum+(r*r*r);
    n=n/10;
}
if(temp==sum)
{
   cout<<"Armstrong number";
}
else
{
    cout<<"Not Armstrong Number";
}
return 0;
}   
