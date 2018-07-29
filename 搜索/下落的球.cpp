#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
AOJ0033
Ball
*/
using namespace std;

int x[10],Left,Right;

bool dfs(int num,int d)//编号num，放d方向（0左1右） 
{
	if(num==10)
	{
		return 1;
	}
	if((d==0&&x[num]<Left)||(d==1&&x[num]<Right))
	{
		return 0;
	}
	int t1=Left,t2=Right;
	if(d==0)
	{
		Left=x[num];
		if(dfs(num+1,1)||dfs(num+1,0))
		{
			return 1;
		}
		Left=t1;//回溯还原状态 
	}
	else
	{
		Right=x[num];
		if(dfs(num+1,1)||dfs(num+1,0))
		{
			return 1;
		}
		Right=t2;//回溯还原状态 
	}
	return 0;
}

int main()
{
	int T,i,ans;
	bool flag;
	scanf("%d",&T);
	while(T--)
	{
		for(i=0;i<10;i++)
		{
			scanf("%d",&x[i]);
		}
		Left=-1,Right=-1;
		if(dfs(0,0))//第一次放左放右无所谓的 
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0; 
}


