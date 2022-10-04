#include<iostream>
using namespace std;
extern int color[4];
bool issafe(int graph[4][4],int r, int colo, int color[])
{
	for(int h=0;h<4;h++)
	{
		if(graph[r][h]==1)
		{
			if(color[h]==colo)
			{
				return false;
			}
		}
	}
	return true;
}
bool colr(int graph[4][4],int r)
{
	if(r==4)
	{
		return true;
	}
	for(int i=1;i<=4;i++)
	{
		if(issafe(graph,r,i,color))
		{
			color[i-1]=i;
			if(colr(graph,r+1))
			{
				return true;
			}
			color[i-1]=0;
		}
	}
	return false;
}
int main()
{
	int graph[4][4]={{0, 1, 1, 1},{1, 0, 1, 0},{1, 1, 0, 1},{1, 0, 1, 0}};
	cout<<colr(graph,0);
}
