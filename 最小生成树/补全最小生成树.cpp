#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
图中已经选取了若干边
在此基础上求最小生成树（权值减去已有的） 
将已选取的权值置为0即可 
*/
using namespace std;

#define MAXN (int)(1e2+1)//最多节点数 
#define INF 0x3f3f3f3f//极大值 


int cost[MAXN][MAXN];//耗费矩阵（边）
int lowC[MAXN];//每个节点离当前生成的树的最短距离 
bool vis[MAXN];

int Prim(int n)//节点数，假设从0开始编号
{
	memset(vis,0,sizeof(vis));
	int i,j,MIN,ans=0,p;
	vis[1]=1;//先将0号节点加入
	for(i=2;i<=n;i++)
	{
		lowC[i]=cost[1][i];//因为当前只有0号节点 
	}
	for(i=1;i<n;i++)//这个只是次数，需要寻找剩余n-1个点 
	{
		MIN=INF;
		p=-1;
		for(j=2;j<=n;j++)//遍历未加入节点 
		{
			if(!vis[j]&&lowC[j]<MIN)
			{
				MIN=lowC[j];
				p=j;
			}
		}
		if(p==-1)
		{
			return -1;
		}
		vis[p]=1;
		ans+=MIN;
		for(j=2;j<=n;j++)//遍历未加入节点 
		{
			if(!vis[j]&&cost[j][p]<lowC[j])
			{
				lowC[j]=cost[j][p];
			}
		}
	}
	return ans;
} 

int main()
{
	int N,Q,a,b,i,j,tem;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d",&a,&b);
		cost[a][b]=0;
		cost[b][a]=0;
	}
	printf("%d",Prim(N));
	return 0; 
}







