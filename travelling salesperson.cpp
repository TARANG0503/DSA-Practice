#include<iostream>
using namespace std;
int traverse[5],gh=0;
int reduced(int grid[5][5])
{
	int cost=0,min,fun;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(j==0)
			{
				min=grid[i][j];
				fun=j;
			}
			else if(min>grid[i][j])
			{
				min=grid[i][j];
				fun=j;
			}
		}
		cost=cost+grid[i][fun];
		for(int j=0;j<5;j++)
		{
			grid[i][j]=grid[i][j]-min;
		}
	}
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(j==0)
			{
				min=grid[j][i];
				fun=j;
			}
			else if(min>grid[j][i])
			{
				min=grid[j][i];
				fun=j;
			}
		}
		cost=cost+grid[fun][i];
		for(int j=0;j<5;j++)
		{
			grid[j][i]=grid[j][i]-min;
		}
	}
	return cost;
}
bool issafe(int i)
{
	for(int d=0;traverse[d]!='\0';d++)
	{
		if(traverse[d]==i)
		{
			return false;
		}
	}
	return true;
}
int solve(int grid[5][5],int upbound,int cost,int start)
{
	cost=cost+reduced(grid);
	traverse[gh]=start;
	gh++;
	int min,fun;
	for(int i=0;i<5;i++)
	{
		if(start!=i&&grid[start][i]<100&&issafe(i))
		{
			if(i==0)
			{
				min=grid[start][i];
				fun=i;
			}
			else if(min>grid[start][i])
			{
				min=grid[start][i];
				fun=i;
			}
		}
		solve(grid,upbound,cost+min,i);
	}
	return cost;
}
int main()
{
	int grid[5][5]={{1000,20,30,10,11},{15,1000,16,4,2},{3,5,1000,2,4},{19,6,18,1000,3},{16,4,7,16,1000}};
	solve(grid,10000,0,0);
}
