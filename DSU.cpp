#include <iostream>
#include <set> 
#include <iterator>
#include <bitset> 
#include <bits/stdc++.h> 
using namespace std;
typedef  long long int ll;
ll mod=1000000007;

struct unionfind{
    int n,setsize,*rank,*parent;
    unionfind(int a){
        n=a;setsize=a;
        rank =new int[n+1];
        parent = new int[n+1];
        for(int i=1;i<=n;i++){
            rank[i] = 1;
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x]!=x) return parent[x] = find(parent[x]);
        else return x;
    }
    void merge(int x,int y){
        int xrep=find(x);int yrep=find(y);
        if(xrep!=yrep){
            if(rank[xrep] >= rank[yrep]){
                parent[yrep] = xrep;
                rank[xrep]+=rank[yrep];
            }
            else{
                parent[xrep] = yrep;
                rank[yrep]+= rank[xrep];
                
            }
            setsize-=1;
        }
    }
    
};
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        //ENTER NUMBER OF NODES as n
        //ENTER NUMBER OF QUESRIES as q
        int n,q;
        cin>>n>>q;
        struct unionfind U(n);
        //TWO TYPES OF QUESRIES
        //QUERY TYPE - 0, y, z -> merge(y,z)
        //QUERY TYPE - 1, y, z -> indicate if they are in the same set
        while(q--){
            int x,y,z;
            cin>>x>>y>>z;
            if(!x) U.merge(y,z);
            else {
                int yrep = U.find(y);
                int zrep = U.find(z);
                if(yrep==zrep)
                    cout<<1<<endl;
                else
                    cout<<0<<endl;
            }
        }
        
        
        
        
    
        
    
        
    }
    return 0;
}
