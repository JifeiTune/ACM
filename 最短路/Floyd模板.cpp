#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
假设点编号从1开始 
*/
using namespace std;

#define MAXN (int)(1e3+1)
#define INF 0x3f3f3f3f

int x[MAXN][MAXN];

void Floyd(int n)
{
	int i,j,k;
	for(k=1;k<=n;k++)//选取每一个节点作为中间节点 
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(x[i][k]+x[k][j]<x[i][j])
				{
					x[i][j]=x[i][k]+x[k][j];
				}
			}
		}
	}
}

inline void add(int i,int j,int v)
{
	x[i][j]=v;
	x[j][i]=v;
}

int main()
{
	
	int i,j;
	memset(x,0x3f,sizeof(x));
	for(i=1;i<=3;i++)
	{
		x[i][i]=0;
	}
	add(1,2,1);
	add(2,3,2);
	Floyd(3);
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			printf("%d ",x[i][j]);
		}
		putchar('\n');
	}
	return 0; 
}


