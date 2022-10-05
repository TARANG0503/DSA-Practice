below code uses recursion with memoization
#include <bits/stdc++.h>
using namespace std;
int ans=0;
map<vector<int>,int>mp;
int recur(vector<int>v){
    
    if(v.size()==1){
        return v[0];
    }
    if(mp.find(v)!=mp.end())
        return mp[v];
        
    int maxi=0;
    
    
    for(int i=1;i<=v.size();i++){
        if(i==1){
            vector<int>go = v;
            go.erase(go.begin()+i-1);
            maxi=max(maxi,v[i-1]*v[i]+recur(go));
        }
        else if(i==v.size()){
            vector<int>go = v;
            go.erase(go.begin()+i-1);
            maxi=max(maxi,v[i-1]*v[i-2]+recur(go));
        }
        else{
            vector<int>go = v;
            go.erase(go.begin()+i-1);
            maxi=max(maxi,v[i-1]*v[i]*v[i-2]+recur(go));
        }
        
    }
    if(mp.find(v)!=mp.end())
    mp[v]=max(mp[v],maxi);
    else
    mp[v]=maxi;
    return mp[v];
}

int main(){
    int n,k;
    cin>>n;
    vector<int>v(n);
    for(int i=1;i<=n;i++)
    cin>>v[i-1];
    cout<< recur(v);
    //return ans;
}


42. Earn Maximum Money

19

ALL

You are given 'n' piggy banks, indexed from 0 to n-1. Each piggy bank contains some amount of money in it which is represented by an array 'nums'. You are asked to break all the piggy banks in any order.

Θ

34

If you break the ith piggy bank, you will get the amount equivalent to (nums[i-1]* nums[i]*

35

nums[i+1]) dollars. If i-1 or i+1 goes out of bounds of the array, then treat it as if there is a piggy bank with 1 US Dollar in it.

31 > int

36

The goal is to return the maximum amount of dollars you can collect by breaking the piggy banks.

37

Input Format

First line contains n, the number of piggy banks. Second line contains an array nums representing the amount of money in each piggy bank.

38

Constraints

39

1 <=n<= 300 0<=nums[i] <= 100 where i is [0, n-1]

40

Output Format An integer representing maximum amount of money

41

Test Resu

LL

D 1080

Sample Input 0

4
