#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<vector>
#include<queue> 
using namespace std;


#define MAXN (int)(1e2+1)//最大点数
#define MAXE (int)(1e3+1)//最大边 
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

vector<Edge> edges;//所有边（便于遍历） 
vector<int> points[MAXN];//每个点出发的边下标（0开始） 
bool del[MAXE];//某条边是否删去 
bool eff[MAXE][MAXN];//删去i边是否会影响某个点出发的最短路

int n,m;//点数和边数
int L;

struct Dijkstra
{
	int dis[MAXN];//源点到每个节点的最短距离
	bool vis[MAXN];//标记节点是否已求解 
	
	long long Solve(int S)//返回最短路和 
	{
		int i,j;
		int from,to,dis1,dis2,ans=0;
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
			for(i=0;i<points[from].size()&&(!del[points[from][i]]);i++)//该点出发能到达的所有点 
			{
				to=edges[points[from][i]].to;//下一个点 
				dis2=dis1+edges[points[from][i]].value;//以当前点为中介点时的距离 
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

int main()
{
	memset(del,0,sizeof(del));
	memset(eff,0,sizeof(eff));
	
	return 0; 
}













