#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
UVALive - 4794
Sharing Chocolate
*/
using namespace std;

bool onlyOne(int x)
{
	while( (x&1)!=1 )//不断右移直至最后一位为1 
	{
		x=(x>>1);	
	}
	x=(x>>1);//去除最后一个1
	return x==0?1:0;//无1则为真，还有1则为假 
}

int area[16];//保存要切的面积
bool dp[101][1<<15];//短边为i,面积状态为j时是否可切 
bool vis[101][1<<15];//是否已经决策
int SUM[1<<15];//每种面积状态的面积 

bool dfs(int x,int S)//短边为x，面积状态为S能否切s，S确保至少包含两个为1的位 
{
	if(vis[x][S])
	{
		return dp[x][S];
	}
	
	vis[x][S]=1;//置为已决策
	if(onlyOne(S))//S只有一位，之前也检查了面积，必然能分 
	{
		return dp[x][S]=1;
	}
	int y=SUM[S]/x;//更长边 
	int S0=S&(S-1),S1;
	while(S0!=0)//开始枚举子集 
	{
		S1=S^S0;//子集补集
		if(SUM[S0]%x==0)//短边平行切一刀 
		{
			if(dfs(min(x,SUM[S0]/x),S0)&&dfs(min(x,SUM[S1]/x),S1))
			{
				return dp[x][S]=1;
			}
		} 
		if(SUM[S0]%y==0)
		{
			if(dfs(SUM[S0]/y,S0)&&dfs(SUM[S1]/y,S1))
			{
				return dp[x][S]=1;
			}
		}
		S0=S&(S0-1);//子集枚举 
	}
	return dp[x][S]=0;
}

int main()
{
	int n,x,y,i,j,a,b,tem,ans,sum,cas=1,S,all;
	while(scanf("%d",&n)&&n!=0)
	{
		sum=0;
		S=0;
		scanf("%d%d",&x,&y);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&area[i]);
			sum+=area[i];	
		}
		if(sum!=x*y)
		{
			printf("Case %d: No\n",cas++);
			continue;
		}
		memset(vis,0,sizeof(vis));
		memset(SUM,0,sizeof(SUM));
		all=(1<<n);
		for(S=1;S<all;S++)
		{
			for(i=1;i<=n;i++)//涉及到n个位 
			{
				if((S&(1<<(i-1)))!=0)
				{
					SUM[S]+=area[i];
				}
			}
		}
		if(dfs(min(x,y),all-1))
		{
			printf("Case %d: Yes\n",cas++);
		}
		else
		{
			printf("Case %d: No\n",cas++);
		}	
	} 
	return 0; 
}










