#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
AOJ0118
Property Distribution
*/
using namespace std;

char x[101][101];
int num,Sx,Sy,W,H;

void dfs(int i,int j,char what)
{
	if(i>=1&&i<=H&&j>=1&&j<=W&&x[i][j]==what)
	{
		x[i][j]=' ';
		dfs(i,j+1,what);
		dfs(i,j-1,what);
		dfs(i+1,j,what);
		dfs(i-1,j,what);
	}
} 

int main()
{
	int i,j,k,ans,tem;
	while(scanf("%d%d",&H,&W)&&(W!=0||H!=0))
	{
		for(i=1;i<=H;i++)
		{
			for(j=1;j<=W;j++)
			{
				scanf(" %c",&x[i][j]);
			}
		}
		num=0;
		for(i=1;i<=H;i++)
		{
			for(j=1;j<=W;j++)
			{
				if(x[i][j]!=' ')
				{
					num++;
					dfs(i,j,x[i][j]);
				}
			}
		}
		printf("%d\n",num);
	}
	return 0; 
}


