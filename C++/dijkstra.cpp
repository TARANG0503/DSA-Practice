#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
  
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        // Code here
        vector<vector<int> > adj_matrix(V, vector<int>(V, 0));
        for(int i=0; i<V; i++)
            for(int j=0; j<adj[i].size(); j++)
                adj_matrix[i][adj[i][j][0]] = adj[i][j][1];
        vector<int> distance(V,INT_MAX);
        distance[S] = 0;
        vector<int> visited(V,false);
        for(int j=0;j<V;j++){
            int loc_min = -1;
            for(int i=0;i<V;i++){
            if(!visited[i] &&(loc_min==-1 || distance[i]<distance[loc_min])){
                loc_min = i;
            }
        }
        visited[loc_min] = true;
        for(int k=0;k<V;k++){
            if(!visited[k] && adj_matrix[loc_min][k]!=0 && distance[k]>(distance[loc_min]+adj_matrix[loc_min][k])){
                distance[k] = distance[loc_min]+adj_matrix[loc_min][k];
            }
        }
        }
     
        return distance;
        
        
    }
};





int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
