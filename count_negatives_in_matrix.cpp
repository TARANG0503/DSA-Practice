#include<bits/stdc++.h>
using namespace std;
void online()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
int coutNegatives(vector<vector<int>> &grid){
   int answer=0;
        
        for(int i=0;i<grid.size();i++){
            int ans=0;
            int s=0;
            int e=grid[i].size()-1;
            int mid = s+(e-s)/2;
            while(s<=e){
            if(grid[i][mid]<0){
               ans=grid[i].size()-mid;
               e=mid-1; 
            }
            else{
                s=mid+1;
            }
                mid=s+(e-s)/2;
        }
            answer=answer+ans;
        }
        
        return answer;
}
int main(){
    online();
    int m,n;
    cin>>m>>n;
    vector<vector<int>> arr(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(auto a:arr){
        for(auto b:a)
        cout<<b<<" ";
        cout<<endl;
    }
    cout<<coutNegatives(arr);
    return 0;

}