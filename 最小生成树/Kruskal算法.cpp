#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
using namespace std;

/*
起初所有点都孤立 
给边按权值从小到大排序
只要边的两个端点分别在不同的树中（加边后不会有环）就加入
无向图，加边加一条就OK 
*/ 

/*
使用步骤
1.调整MAXN与MAXE
2.每次使用前令Enum=0，然后加边
3.调用Kruskal(n)，n为节点数，则返回最小生成树权值
点编号从0开始和从1开始都OK，因为体现在了edges数组中，无需手动调 
*/ 

#define MAXN (int)(1e3+1)//最大点数 
#define MAXE (int)(1e3+1)//最大边数 

struct Edge
{
	int from,to,value;
};

Edge edges[MAXE];//所有的边
int Enum;//边数，使用前先初始化为0
int points[MAXN];//所有的点编号

void add(int f,int t,int v)//加边 
{
	edges[Enum].from=f;
	edges[Enum].to=t;
	edges[Enum].value=v;
	Enum++;
}

int find(int n)
{
	if(points[n]!=n)
	{
		return points[n]=find(points[n]);
	}
	return n;
}

bool CMP(Edge x,Edge y)
{
	return x.value<y.value;
}

int Kruskal(int n)//n为节点数，编号从0开始还是从1开始都OK 
{
	int i,from,to,val,ans=0,num=0,f1,f2;
	for(i=0;i<=n;i++)//这样点编号从0开始还是从1开始都OK 
	{
		points[i]=i;//并查集初始化 
	}
	sort(edges,edges+Enum,CMP);
	for(i=0;i<Enum;i++)//遍历所有的边 
	{
		from=edges[i].from;
		to=edges[i].to;
		val=edges[i].value;
		f1=find(from);
		f2=find(to);
		if(f1!=f2)//加边不会产生环
		{
			points[f2]=f1;
			num++;//
			ans+=val;//加上权值	
		}
	}
	if(num!=n-1)//图不连通，边少了 
	{
		return -1;
	}
	else
	{
		return ans;
	}
}

int main()
{
	Enum=0;
	add(2,1,1);
	add(2,3,1);
	add(4,2,1);
	add(4,5,1);
	cout<<Kruskal(5);
	return 0; 
}


