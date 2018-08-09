#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<map>
using namespace std;

int x[101][101];
bool vis[101][101];
int dp[101][101];
int shift[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
/*
POJ - 1088
»¬Ñ© 
*/ 
int dfs(int X,int Y,int dis)//´Ó(i,j)³ö·¢£¬ÒÑ»¬dis¾àÀë 
{
	if(dp[X][Y]!=-1)
	{
		return dp[X][Y]+dis;
	}
	vis[X][Y]=1;
	int Nx,Ny,i,j,MAXD=dis;
	for(i=0;i<4;i++)
	{
		Nx=X+shift[i][0];
		Ny=Y+shift[i][1];
		if(Nx>=1&&Nx<=n&&Ny>=1&&Ny<=m&&(!vis[Nx][Ny])&&x[Nx][Ny]<x[X][Y])
		{
			MAXD=max(MAXD,dfs(Nx,Ny,dis+1));
		}
	}
	vis[X][Y]=0;//»Ö¸´×´Ì¬ 
	dp[X][Y]=MAXD-dis;
	return MAXD;
}

int main()
{
	int i,j,k,ans,num=1;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&x[i][j]);
		}
	}
	memset(dp,-1,sizeof(dp));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			memset(vis,0,sizeof(vis));
			num=max(num,dfs(i,j,1));
		}
	}
	printf("%d",num);
	return 0; 
}

