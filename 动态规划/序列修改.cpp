#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<vector>
/*
UVALive - 4256
Salesmen
*/
using namespace std;

#define INF 0x7fffffff

vector<int> x[101];//最多100个点
int dp[201][101];//前i个点满足条件，第i个点为j时的最小修改数  
int p[201];//待修改序列 

int main()
{
	int T,n1,n2,n,i,j,k,a,b,tem,ans,MIN;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n1,&n2);
		for(i=1;i<=n1;i++)
		{
			x[i].clear();
			x[i].push_back(i);//自己和自己算连通 
		}
		for(i=1;i<=n2;i++)
		{
			scanf("%d%d",&a,&b);
			x[a].push_back(b);
			x[b].push_back(a); 
		}
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
		}
		for(i=1;i<=n;i++)
		{
			dp[1][i]=1;
		}
		dp[1][p[1]]=0;//dp边界，序列中第一个点修改成别的点，修改数都是1
		for(i=2;i<=n;i++)//序列中n个点 
		{
			for(j=1;j<=n1;j++)//每个点n1种修改 
			{
				MIN=INF;
				if(j==p[i])
				{
					for(k=0;k<x[j].size();k++)//每种修改的相邻边 
					{
						MIN=min(MIN,dp[i-1][x[j][k]]);
					}
				}
				else
				{
					for(k=0;k<x[j].size();k++)//每种修改的相邻边 
					{
						MIN=min(MIN,dp[i-1][x[j][k]]+1);
					}
				}
				dp[i][j]=MIN;	
			}	
		}
		MIN=INF;
		for(i=1;i<=n1;i++)
		{
			MIN=min(MIN,dp[n][i]);
		}
		printf("%d\n",MIN);
	}
	return 0; 
}









