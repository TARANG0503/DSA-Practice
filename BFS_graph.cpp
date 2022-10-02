#include<iostream> 
#include<vector>
#include <list> 

using namespace std; 
  
class Graph 
{ 
    int V; 
  
    list<int> *adj;    
public: 
    Graph(int V);
    void addEdge(int v, int w);  
    void BFS(int s);   
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
} 
  
void Graph::BFS(int s) 
{ 

    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    //queue structure to traversal
    list<int> queue; 
  
    // Mark the current node as visited and enqueue it 
    visited[s] = true; 
    queue.push_back(s); 
  
    // 'i' will be used to get all adjacent 
    // vertices of a vertex 
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
  
        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} 
  

int main() 
{ 
    int size,edge,i,u,v,init;
    cout<<"Enter the num of vertices of Graph : ";
    cin>>size;
    cout<<"Enter the num of edges : ";
    cin>>edge;
    Graph g(size); 
    for(i=0;i<edge;i++){
    	cout<<"Enter the edge by (u,v) :";
    	cin>>u>>v;
    	g.addEdge(u, v); 
	}
    
  
    cout << "Input the starting vertice : ";
	cin>>init;
    g.BFS(init); 
  
    return 0; 
} 
