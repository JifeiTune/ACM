#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<cstdio>
/*
Poj 3625
Building Roads

N个节点，每个节点都有坐标
现在已经有若干边了
让你添加剩余边使得整个图连通
新增边的长度和要最小 
已有的边权值设为0即可 
*/
using namespace std;

#define MAXN (int)(1e3+1)//最多节点数 
#define INF 1e300//极大值 

double cost[MAXN][MAXN];//耗费矩阵（边）
double lowC[MAXN];//每个节点离当前生成的树的最短距离 
bool vis[MAXN];

double Prim(int n)//节点数，假设从0开始编号
{
	int i,j,p;
	double MIN,ans=0;
	vis[1]=1;//先将0号节点加入
	for(i=2;i<=n;i++)
	{
		lowC[i]=cost[1][i];//因为当前只有0号节点 
	}
	for(i=1;i<n;i++)//这个只是次数，需要寻找剩余n-1个点 
	{
		MIN=INF;
		p=-1;
		for(j=1;j<=n;j++)//遍历未加入节点 
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
		for(j=1;j<=n;j++)//遍历未加入节点 
		{
			if(!vis[j]&&cost[j][p]<lowC[j])
			{
				lowC[j]=cost[j][p];
			}
		}
	}
	return ans;
} 

#define DIS(x1,y1,x2,y2) ( sqrt( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) ) )

double X[MAXN],Y[MAXN];

int main()
{
	int N,M,xi,yi,i,j;
	double tem;
	scanf("%d%d",&N,&M);
	for(i=1;i<=N;i++)
	{
		scanf("%lf%lf",&X[i],&Y[i]);
	}
	for(i=1;i<=N;i++)
	{
		cost[i][i]=0;//对角线 
	}
	for(i=2;i<=N;i++)
	{
		for(j=1;j<i;j++)
		{
			tem=DIS(X[i],Y[i],X[j],Y[j]);
			cost[i][j]=tem;
			cost[j][i]=tem;//对称计算 
		}
	}  
	for(i=1;i<=M;i++)
	{
		scanf("%d%d",&xi,&yi);
		cost[xi][yi]=0;
		cost[yi][xi]=0;
	}
	printf("%.2f",Prim(N));
	return 0; 
}
