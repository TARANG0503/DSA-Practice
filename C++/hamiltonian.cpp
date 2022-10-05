#include<iostream>
using namespace std;
bool possible(int visited[],int check)
{
	for(int i=0;i<5;i++)
	{
		if(visited[i]==check)
		{
			return false;
		}
	}
	return true;
}
bool hamcycle(int graph[5][5],int visited[],int start,int j)
{
	if(j==4)
	{
		if(graph[start][visited[0]]==1)
		{
			visited[j]=start;
			return true;
		}
		return false;
	}
	for(int i=0;i<5;i++)
	{
		if(graph[start][i]==1&&possible(visited,i))
		{
			visited[j]=start;
			if(hamcycle(graph,visited,i,j+1))
			{
				return true;
			}
			visited[j]=-1;
		}
	}
	return false;
}
int main()
{
	int graph[5][5]={   {0, 1, 0, 1, 0},
                        {1, 0, 1, 1, 1},
                        {0, 1, 0, 0, 1},
                        {1, 1, 0, 0, 1},
                        {0, 1, 1, 1, 0}  };
    int visited[5];
    for(int i=0;i<5;i++)
    {
    	visited[i]=-1;
	}
	for(int i=0;i<5;i++)
	{
     hamcycle(graph,visited,i,0);
     for(int l=0;l<5;l++)
     {
     	cout<<visited[l]<<" ";
	 }
	 cout<<endl;
     for(int k=0;k<5;k++)
     {
     	visited[k]=-1;
	 }
	}
}
