// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
// Return all critical connections in the network in any order.

class Solution {
public:
    vector<vector<int>>ans;
    vector<int>g[100000];
    int vis[100000],time[100001],low[100000];
    int timer=0;
    void dfs(int node, int parent){
        vis[node]=1;
        time[node]=low[node]=timer++;
        for(auto it:g[node]){
            if(it==parent)continue;
            if(not vis[it]){
                dfs(it, node);
                low[node] = min(low[node],low[it]);
                if(low[it]>time[node]){
                    ans.push_back({it,node});
                }
            }
            else{
                low[node]=min(low[node],time[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        ans.clear();
        timer=0;
        for(auto it:connections){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        for(int i=0; i<n; i++){
            if(not vis[i]){
                dfs(i,-1);
            }
        }
        return ans;
    }
};
