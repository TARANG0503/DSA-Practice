/*You are given an array of N non-negative integers: A1, A2, ..., AN. 
An alternating subsequence is a subsequence in which the indices of any two consecutive elements differ by exactly two in the original array. That is, if Ai1, Ai2, ..., Aik is some subsequence, 
then for it to be an alternating subsequence, (i2 - i1 = 2), (i3 - i2 = 2), and so on should all hold true. 
Among all alternating subsequences, find the one which has maximum sum of elements, and output that sum.*/
#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,pd=0,curr=0,max=0;
        cin>>n;
        long long int arr[n];
        for(long long int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(i%2==0)
            curr+=arr[i];
            else pd+=arr[i];
        }
        max=pd>curr?pd:curr;
        cout<<max<<endl;
    }
    return 0;
}