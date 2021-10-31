#include<iostream>
#include<list>

using namespace std;

class BFS_Graph
{
	int V; 
	list<int> *adj;

    public:
	BFS_Graph(int V); 
	
	void createEdge(int v, int w);

	void BFS(int s);
};

BFS_Graph::BFS_Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void BFS_Graph::createEdge(int v, int w)
{
	adj[v].push_back(w);
}

void BFS_Graph::BFS(int s)
{
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
		visited[i] = false;
		
	list<int> queue;
	
	visited[s] = true;
	queue.push_back(s);
	
	list<int>::iterator i;

	while(!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();

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

	BFS_Graph g(4);
	g.createEdge(0, 1);
	g.createEdge(0, 2);
	g.createEdge(1, 2);
	g.createEdge(2, 0);
	g.createEdge(2, 3);
	g.createEdge(3, 3);

	cout << "Breadth First Search.... "
		<< "(Vertex 2) \n";
	g.BFS(2);

	return 0;
}
