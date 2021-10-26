#include<iostream>

using namespace std;

int main()
{
    int years,days,weeks;

    cout<<"Enter No. of days :: ";
    cin>>days;

    years=days/365;
    days=days%365;
    weeks=days/7;
    days=days%7;

    cout<<"\nNo. of Years: : "<<years<<"\nNo. of Weeks :: "<<weeks<<"\nNo. of Days :: "<<days<<"\n";

    return 0;
}
