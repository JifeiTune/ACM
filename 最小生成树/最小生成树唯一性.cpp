#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
判断最小生成树是否唯一
 
*/
using namespace std;

#define MAXN (int)(1e3+1)//最多节点数 
#define INF 0x3f3f3f3f//极大值 


int cost[MAXN][MAXN];//耗费矩阵（边）
int lowC[MAXN];//每个节点离当前生成的树的最短距离 
bool vis[MAXN];

int Prim(int n)//节点数，假设从0开始编号
{
	int i,j,MIN,ans=0,p;
	vis[0]=1;//先将0号节点加入
	for(i=1;i<n;i++)
	{
		lowC[i]=cost[0][i];//因为当前只有0号节点 
	}
	for(i=1;i<n;i++)//这个只是次数，需要寻找剩余n-1个点 
	{
		MIN=INF;
		p=-1;
		for(j=0;j<n;j++)//遍历未加入节点 
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
		for(j=0;j<n;j++)//遍历未加入节点 
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
	memset(cost,0x3f,sizeof(cost));
	int n=3;
	for(int i=0;i<3;i++)
	{
		cost[i][i]=0;
	}
	cost[0][1]=cost[1][0]=1;
	cost[1][2]=cost[2][1]=1;
	cout<<Prim(3);
	return 0; 
}


