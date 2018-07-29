#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<queue>
/*
路的权值都是一样的，那么直接广搜就OK，先搜到的就是最短的
不需要用那些带权最短路算法 
*/
using namespace std;

struct node
{ 
	int i,j;
	node()
	{
		
	}
	node(int x,int y)
	{
		i=x;
		j=y;
	} 
} pos[10];//1-9工厂的坐标，0代表老鼠洞 

char x[1001][1001];
bool vis[1001][1001];//标记能走的是否已走，不能走的值忽略
int shift[4][2]={{0,1},{0,-1},{-1,0},{1,0}};

int W,H,N;

inline bool isOk(int i,int j)
{
	if(i>=1&&i<=H&&j>=1&&j<=W&&x[i][j]!='X')
	{
		return 1;
	}
	return 0;
}

int bfs(node st,node en)
{
	queue< pair<node,int> > q;
	node tem;
	int i,Nx,Ny,ans;
	q.push(make_pair(st,0));
	while(!q.empty())
	{
		tem=q.front().first;
		ans=q.front().second;
		q.pop();
		for(i=0;i<4;i++)
		{
			Nx=tem.i+shift[i][0];
			Ny=tem.j+shift[i][1];
			if(isOk(Nx,Ny)&&(!vis[Nx][Ny]))//tem点向4个方向偏移
			{
				vis[Nx][Ny]=1;
				if(Nx==en.i&&Ny==en.j)//最先到达，必然最短 
				{
					return ans+1; 
				}
				else
				{
					q.push(make_pair(node(Nx,Ny),ans+1));//新点加入 
				}
			} 
		}
	}
}

int main()
{
	int i,j,k,ans,tem,num;
	char c; 
	scanf("%d%d%d",&H,&W,&N);
	memset(x,0,sizeof(x));
	for(i=1;i<=H;i++)
	{
		for(j=1;j<=W;j++)
		{
			scanf(" %c",&c);
			if(c=='X')
			{
				x[i][j]=c;//只记录不能走的部分 
			}
			if(c=='S')
			{
				pos[0].i=i;
				pos[0].j=j;	
			}
			if(c>='1'&&c<='9')
			{
				pos[c-'0'].i=i;
				pos[c-'0'].j=j;	
			} 
		}
	}
	num=0;
	for(i=0;i<N;i++)
	{
		memset(vis,0,sizeof(vis));
		num+=bfs(pos[i],pos[i+1]);
	}
	printf("%d\n",num);
	return 0; 
}


