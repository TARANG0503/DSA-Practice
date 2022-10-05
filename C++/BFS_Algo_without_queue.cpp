#include <bits/stdc++.h>
using namespace std;
void bfs(int n, vector<int> a[], int src, vector<int> &v, int dist[]){
    int i,u;
    bool visit[n];
    for(i = 0;i < n;i++){
        dist[i] = INT_MAX;
        visit[i] = false;
    }
    v.push_back(src);
    visit[src] = true;
    dist[src] = 0;
    i = 0;
    while(i < v.size()){
        u = v[i];
        for(int j = 0;j < a[u].size();j++){
            if(visit[a[u][j]] == false){
                visit[a[u][j]] = true;
                dist[a[u][j]] = dist[u]+1;
                v.push_back(a[u][j]);
            }
        }
        i++;
    }
    
}
int main(){
    int n = 6;
    vector<int> adj[n];
    vector<int> v;
    int dist[n];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(3); 
    bfs(n,adj,0,v,dist);
    cout<<"BFS traversal:"<<endl;
    for(int i = 0;i < v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
    cout<<"Distance of each node from source node:"<<endl;
    for(int i = 0;i < n;i++){
        if(dist[i] != INT_MAX)
            cout<<dist[i]<<' ';
        else
            cout<<"INF"<<' ';
    }
    cout<<endl;
}
