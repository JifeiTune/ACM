#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<map>
using namespace std;
/*
UVA 10285滑雪，只能从高的滑向低的，问最长滑行距离
DAG上的记忆化搜索，dp[i][j]记录从(i,j)出发，能滑的最长距离
每个点最多搜索一次，从一点出发能到另一个点，长度就为1+下一点出发长度
有多条路时，取最长长度作为dp[i][j]，类似与求树的高度s 
*/ 
int x[101][101];
bool vis[101][101];
int dp[101][101];
int shift[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m;

int dfs(int X,int Y)//从(i,j)出发，能滑的最长距离 
{
	if(dp[X][Y]!=-1)
	{
		return dp[X][Y];
	}
	vis[X][Y]=1;
	int Nx,Ny,i,j,MAXD=1;
	for(i=0;i<4;i++)
	{
		Nx=X+shift[i][0];
		Ny=Y+shift[i][1];	
		if(Nx>=1&&Nx<=n&&Ny>=1&&Ny<=m&&x[Nx][Ny]<x[X][Y])
		{
			MAXD=max(MAXD,1+dfs(Nx,Ny));
		}
	}
	return dp[X][Y]=MAXD;
}

int main()
{
	int i,j,k,ans,num,T;
	string s;
	scanf("%d",&T);
	while(T--)
	{
		cin>>s;
		scanf("%d %d",&n,&m);
		num=1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%d",&x[i][j]);
			}
		}
		memset(dp,-1,sizeof(dp));
		memset(vis,0,sizeof(vis));
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				num=max(num,dfs(i,j));
			}
		}
		cout<<s<<": ";
		printf("%d\n",num);
	}
	return 0; 
}

