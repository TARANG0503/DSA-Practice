#include <iostream>
using namespace std;

int octaltodecimal(int n){
    int sum=0, x=1;
    while (n>0)
    {
        int ld=n%10;
        sum+=x*ld;
        x*=8;
        n/=10;
    }
    return sum;
    
}
int main()
{
    int a;
    cin>>a;
    cout<<octaltodecimal(a);
    return 0;
}