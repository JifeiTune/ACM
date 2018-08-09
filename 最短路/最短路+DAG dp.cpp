#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<vector>
#include<queue> 
using namespace std;

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

struct Dijkstra
{
	int n,m;//点数和边数
	vector<Edge> edges[MAXN];//每个点出发的所有边，点从0开始编号
	int dis[MAXN];//源点到每个节点的最短距离
	bool vis[MAXN];//标记节点是否已求解 
	
	void clear()//便于重复使用 
	{
		for(int i=0;i<=n;i++)//这样编号从0开始和从1开始都OK 
		{
			edges[i].clear(); 
		}
	}
	
	void Solve(int S)//求解从S出发到所有点的最短路 
	{
		int i,j;
		int from,to,dis1,dis2;
		Qnode tem(0,0);
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));//初始各点最短路径置为无穷大 
		priority_queue<Qnode> pq;
		while(!pq.empty())
		{
			pq.pop();//保险？ 
		}
		dis[S]=0;
		pq.push(Qnode(S,0));
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
				dis2=dis1+edges[from][i].value;//以当前点为中介点时的距离 
				if(!vis[to]&&dis2<dis[to])//点未被求解且以当前点为中介能达到更短的距离 
				{
					//若想记录路径，在这里使用path数组记录当前最短路中当前节点的下一节点或者上一节点即可 
					dis[to]=dis2;
					pq.push(Qnode(to,dis2));
					//尽管放进去，to会重复也没关系，因为每次取出时都会检查该点是否已求解 
				}
			}
		}
	}
}; 

vector<int> map[MAXN];
bool isOk[MAXN][MAXN];
int dp[MAXN];

/*
直接暴力dfs，假设有两条符合的路径形成y型，汇合节点为A
那么搜两条路时，y以后的路重复搜索了，数据量大当然会T
所以采取记忆化搜索，搜过一次，沿途都保存（很像并查集的路径压缩） 
*/
int dfs(int D)//返回从D点出发到2的路径个数
{
	if(D==2)
	{
		return 1;
	}
	if(dp[D]!=-1)
	{
		return dp[D];
	}
	dp[D]=0;
	for(int i=0;i<map[D].size();i++)
	{
		dp[D]+=dfs(map[D][i]);
	}
	return dp[D];
}

int main()
{
	int n,m,a,b,v,i,j,k,tem;
	Dijkstra D;
	while(scanf("%d",&n)&&n!=0)
	{
		scanf("%d",&m);
		D.n=n,D.m=m;
		D.clear();
		memset(isOk,0,sizeof(isOk)); 
		for(i=1;i<=m;i++)
		{
			scanf("%d%d%d",&a,&b,&v);
			D.edges[a].push_back(Edge(a,b,v));
			D.edges[b].push_back(Edge(b,a,v));
			isOk[a][b]=1;
			isOk[b][a]=1;
		}
		D.Solve(2);
		for(i=1;i<=n;i++)
		{
			map[i].clear();	
		}
		for(i=1;i<n;i++)//枚举任意两点 
		{
			for(j=i+1;j<=n;j++)
			{
				if(D.dis[i]<D.dis[j]&&isOk[j][i])
				{
					map[j].push_back(i);
				}
				else if(D.dis[i]>D.dis[j]&&isOk[i][j])//严格小于，加边 
				{
					map[i].push_back(j);
				}
			}
		}
		/*
		for(i=1;i<=n;i++)
		{
			for(j=0;j<map[i].size();j++)
			{
				printf("%d %d\n",i,map[i][j]);
			}
		}
		*/
		memset(dp,-1,sizeof(dp));
		dfs(1); 
		//新的图，求从1到2的路径个数
		printf("%d\n",dfs(1));  
	} 
	
	return 0; 
}













