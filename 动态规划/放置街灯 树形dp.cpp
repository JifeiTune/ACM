#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<vector> 
/*
UVA - 10859
Placing Lampposts

在无向无环图（森林）的节点上放灯，可以照亮与该点相邻的所有边，
尽量使灯数少，灯数相同时，尽量使被两灯同时照亮的边数多，
求解灯数和分别被一盏灯、两盏灯照亮的边数。
为了统一成求最小值，改成尽量使仅被一盏灯照亮的边（v2）尽可能少
总灯数为v1，则决策可设为使(M*v1+v2)尽可能小，M在这里取2000 
*/
using namespace std;

vector<int> x[1000];//保存每个节点和与之关联的节点
int dp[1000][2];//某个节点作为根节点时，子树的最佳决策，第二维为0代表父节点未放，为1代表放了
bool vis[1000][2];//某种决策是否考虑过 

int dfs(int i,int j,int f)//i为本节点，j为父节点是否放灯，f为父节点 
{
	if(vis[i][j])
	{
		return dp[i][j];//已决策过的不必再决策 
	}
	int ans1=0,ans2=0,k;
	vis[i][j]=1;//本种决策置为已做
	//本节点放
	ans1+=2000;
	if(f!=-1&&j==0)//父节点未放 
	{
		ans1++;//新增一条仅被一盏灯照亮的边 
	}
	for(k=0;k<x[i].size();k++)
	{
		if(x[i][k]!=f)//千万别漏！自己的父节点也在其中，但不应再搜索 
		{
			ans1+=dfs(x[i][k],1,i);
		}
	}
	//本节点不放
	if(f==-1||j==1)//本节点为根节点或者父节点放了
	{
		for(k=0;k<x[i].size();k++)
		{
			if(x[i][k]!=f)//千万别漏！自己的父节点也在其中，但不应再搜索 
			{
				ans2+=dfs(x[i][k],0,i);
			}
		}
		//要注意，放灯是无条件的，不放却是有条件的，以下步只能在不放的if里执行 
		if(f!=-1)//换成j==1一样的 
		{
			ans2++;
		}
		ans1=min(ans1,ans2);
	}
	return dp[i][j]=ans1;
}

int main()
{
	int T,n,m,a,b,i,j,k,tem,ans;
	scanf("%d",&T);
	while(T--)
	{
		ans=0; 
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			x[i].clear();//清除原来的树 
		}
		memset(vis,0,sizeof(vis));//每种状态置为未决策 
		for(k=0;k<m;k++)
		{
			scanf("%d%d",&a,&b);
			x[a].push_back(b);
			x[b].push_back(a);//无向图，双方互加 
		}
		for(i=0;i<n;i++)
		{
			if(!vis[i][0])//找到未访问节点，以它为根深度搜索一棵树 
			{
				ans+=dfs(i,0,-1);//-1代表无父节点 
			}
		}
		printf("%d %d %d\n",ans/2000,m-ans%2000,ans%2000); 
	}
	return 0; 
}











