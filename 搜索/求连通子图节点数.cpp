#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
HDU 1312
Red and Black
*/
using namespace std;

char x[21][21];
int num,Sx,Sy,W,H;

void dfs(int i,int j)
{
	if(i>=1&&i<=H&&j>=1&&j<=W&&x[i][j]=='.')
	{
		x[i][j]='#';
		num++;
		dfs(i,j+1);
		dfs(i,j-1);
		dfs(i+1,j);
		dfs(i-1,j);
	}
} 

int main()
{
	int i,j,k,ans,tem;
	while(scanf("%d%d",&W,&H)&&(W!=0||H!=0))
	{
		for(i=1;i<=H;i++)
		{
			for(j=1;j<=W;j++)
			{
				scanf(" %c",&x[i][j]);
				if(x[i][j]=='@')
				{
					Sx=i,Sy=j;//记录起始点 
				}
			}
		}
		num=0;
		x[Sx][Sy]='.';
		dfs(Sx,Sy);
		printf("%d\n",num);
	}
	return 0; 
}

