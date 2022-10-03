#include<iostream>
using namespace std;
bool hello(int visited[],int i)
{
	for(int g=0;g<7;g++)
	{
		if(visited[g]==i)
		{
			return false;
		}
	}
	return true;
}
bool possible(int graph[7][7],int visited[],int check)
{
	for(int i=0;i<7;i++)
	{
		if(visited[i]==check)
		{
			return false;
		}
	}
	for(int i=0;i<7;i++)
	{
		if(graph[i][check]==1&&i!=check&&hello(visited,i))
		{
			return false;
		}
	}
	return true;
}
int j=0;
void topological(int graph[7][7],int visited[])
{
	if(j==7)
	{
		return;
	}
	bool t=false;
	for(int i=0;i<7;i++)
	{
		if(possible(graph,visited,i))
		{
			visited[j]=i;
			j++;
			t=true;
		}
	}
	if(t==false)
	{
		return;
	}
	topological(graph,visited);
}
int main()
{
	int graph[7][7]={{0,1,0,0,0,0,0},{1,0,0,0,0,0,0},{1,0,0,0,0,0,0},{1,0,0,0,0,0,0},{0,1,0,0,0,0,0},{0,1,0,0,0,0,0},{0,0,1,0,0,0,0}};
	int visited[7];
	for(int i=0;i<7;i++)
	{
		visited[i]=-1;
	}
	topological(graph,visited);
	for(int p=0;p<7;p++)
	{
		cout<<visited[p];
	}
}
