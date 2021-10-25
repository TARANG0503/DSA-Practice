/*There's a quite famous riddle that goes like this:

Alice, Bob and Charles are standing in a line. Alice is looking at Bob. Bob is looking at Charles. We know that Alice is married, while Charles is not. Is there a married person among the three who is looking at an unmarried person?

Surprisingly, not many people get the riddle right. An unaware person would say that the answer to the riddle cannot be determined, as the marital status of Bob is unknown. However, look closely, and you'll find that the answer to the riddle is always 'Yes'. If Bob is married, he'll be the married person looking at unmarried Charles. If Bob is unmarried, Alice will be the married person looking at unmarried Bob.

This riddle was too easy for you, and you have decided to modify it:

N people are now standing in a line. For each valid i (1 ≤ i < N), the i'th person is looking at the (i + 1)'th person. Their marital statuses are given as a string S of length N, consisting of characters 'M' (married), 'U' (unmarried), '?' (unknown). The i'th character (1 ≤ i ≤ N) of string S corresponds to the i'th person standing in the line.

Given S, can you tell if there's a married person looking at an unmarried person, regardless of what the ?'s in S are replaced with?
*/

#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long 
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define REP(i,n) for(int i=0;i<n;i++)
#define w(t) int t; cin>>t; while(t--)
#define mod 1000000007
#define fast ios_base::sync_with_stdio(0); cin.tie(0);  cout.tie(0);

using namespace std;

int main(){
    fast; 
    int t;cin>>t; while(t--){
        string s; cin>>s;
		int is=-1,iu=-1;
		for(int i=0;i<s.size();i++){
			if(s[i]=='M'){
				is=i; break;
			}		
		}
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]=='U'){
				iu=i; break;
			}		
		}
		if(is!=-1 && iu!=-1){
			if(is<iu) cout<<"Yes\n";
			else cout<<"No\n";
		}
		else cout<<"No\n";
    }
}