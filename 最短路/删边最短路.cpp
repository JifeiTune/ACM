#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<vector>
#include<queue> 
using namespace std;

/*
本模板点编号从0开始 
*/

#define MAXN (int)(1e3+1)//最大点数
#define INF 0x3f3f3f3f

struct Edge
{
	int from,to,value;
	Edge(int _from,int _to,int _value):from(_from),to(_to),value(_value){} 
};

struct Qnode//为使用优先队列设置的 
{
	int point;//节点 
	int dis;//当前最短距离
	
	Qnode(int _point,int _dis):point(_point),dis(_dis){}
	bool operator < (const Qnode &right) const
	{
		return dis>right.dis;
		//优先队列中是用<比较，将“大”的放堆顶，此处将它意义变反，实现距离小的放堆顶 
	}
};

vector<Edge> edges[MAXN];//每个点出发的所有边，点从0开始编号
bool isOK[MAXN][MAXN];	

void clear(int N)//便于重复使用 
{
	for(int i=0;i<=N;i++)//这样编号从0开始和从1开始都OK 
	{
		edges[i].clear(); 
	}
	memset(isOK,0,sizeof(isOK)); 
}

struct Dijkstra
{
	int n,m;//点数和边数
	int dis[MAXN];//源点到每个节点的最短距离
	bool vis[MAXN];//标记节点是否已求解 
	int P[MAXN];//最短路中本节点上一节点 
	
	void Solve(int S)//求解从S出发到所有点的最短路 
	{
		int i,j;
		int from,to,dis1,dis2;
		Qnode tem(0,0);
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));//初始各点最短路径置为无穷大
		for(int i=0;i<=n;i++)
		{
			P[i]=i;
		}
		priority_queue<Qnode> pq;
		while(!pq.empty())
		{
			pq.pop();//保险？ 
		}
		dis[S]=0;
		Qnode t(S,0); 
		pq.push(t);
		while(!pq.empty()) 
		{
			tem=pq.top();
			pq.pop();//当前距离最小的点已经得解了
			if(vis[tem.point])//防止是垃圾数据
			{
				continue;
			}
			from=tem.point;//当前点 
			dis1=tem.dis;//当前点最短距离 
			vis[from]=1;//置为已求解 
			for(i=0;i<edges[from].size();i++)//该点出发能到达的所有点 
			{
				to=edges[from][i].to;//下一个点
				if(!isOK[from][to])
				{
					continue;
				}
				dis2=dis1+edges[from][i].value;//以当前点为中介点时的距离 
				if(!vis[to]&&dis2<dis[to])//点未被求解且以当前点为中介能达到更短的距离 
				{
					P[to]=from;
					dis[to]=dis2;
					pq.push(Qnode(to,dis2));
					//尽管放进去，to会重复也没关系，因为每次取出时都会检查该点是否已求解 
				}
			}
		}
	}
}; 

int point[1001];//最短路径中的节点顺序 
int size;

void printZ(Dijkstra &D,int S,int E)//正向存S到E最短路 
{
	if(D.P[E]!=E)
	{
		printZ(D,S,D.P[E]);
	}
	point[size++]=E; 
} 

int main()
{
	Dijkstra D;
	int N,M,i,j,k,ans,tem,A,B,V,MAX,t1,t2;
	while(~scanf("%d %d",&N,&M))
	{
		D.n=N,D.m=M;
		clear(N);
		for(i=1;i<=M;i++)
		{
			scanf("%d %d %d",&A,&B,&V);
			edges[A].push_back(Edge(A,B,V)); 
			edges[B].push_back(Edge(B,A,V));
			isOK[A][B]=1;
			isOK[B][A]=1;
		}
		D.Solve(1);
		MAX=0;
		size=0;
		printZ(D,1,N);
		//开始删边
		for(i=0;i<size-1;i++)
		{
			//边为point[i]->point[i+1]
			isOK[point[i]][point[i+1]]=0;
			isOK[point[i+1]][point[i]]=0;
			D.Solve(1);
			MAX=max(MAX,D.dis[N]);
			isOK[point[i]][point[i+1]]=1;
			isOK[point[i+1]][point[i]]=1;
		}
		printf("%d\n",MAX);
	}
	return 0; 
}
/*
3 2
1 2 5
2 3 5
*/ 











