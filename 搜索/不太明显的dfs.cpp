#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
4堆糖果，每堆个数为n，每个糖果都有颜色
一个篮子，最多可以装5个糖果 
每次可以从任意堆顶取出一个放于篮子中
每当篮子中有2个糖果颜色相同时，可以从篮子中拿出并占为己有
为最多能拿到多少对
表明上当前篮子的状态会影响到决策 
实际上当4堆糖果分别拿走的个数确定时，只要这个状态可达，结果一定是唯一的
所以问题实际上是求解状态可不可达 
设dp[i][j][k][n]为各堆分别剩余i、j、k、n时最多还能拿的对数
dfs一遍即可 
*/
using namespace std;

int pile[5][41];//四堆糖果 
int dp[41][41][41][41];
int Left[5];//当前各堆所剩个数 

int dfs(int num,int bas)//当前得到对数，篮子内糖果个数和状态 
{
	if(dp[Left[1]][Left[2]][Left[3]][Left[4]]!=-1)
	{
		return dp[Left[1]][Left[2]][Left[3]][Left[4]];
	}
	if(num==5)//装不下了
	{
		return dp[Left[1]][Left[2]][Left[3]][Left[4]]=0;
	}
	int i,ans=0;
	for(i=1;i<=4;i++)
	{
		if(Left[i]==0)//i堆取完了 
		{
			continue;
		}
		Left[i]--;
		if((bas&(1<<pile[i][Left[i]+1]))==0)//没有重复 
		{
			
			ans=max(ans,dfs(num+1,bas|(1<<pile[i][Left[i]+1])));
		}
		else//有重复 
		{
			ans=max(ans,1+dfs(num-1,bas^(1<<pile[i][Left[i]+1])));
		}
		Left[i]++;//回溯 
	}
	return dp[Left[1]][Left[2]][Left[3]][Left[4]]=ans;
}

int main()
{
	int n,i,j,k,ans;
	while(scanf("%d",&n))
	{
		if(n==0)
		{
			break;	
		}
		for(i=n;i>=1;i--)
		{
			for(j=1;j<=4;j++)
			{
				scanf("%d",&pile[j][i]);
			}
		}
		for(i=1;i<=4;i++)
		{
			Left[i]=n;
		}
		memset(dp,-1,sizeof(dp));
		printf("%d\n",dfs(0,0));
	} 
	return 0; 
}


