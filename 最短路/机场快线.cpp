#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<vector>
#include<queue> 
using namespace std;


#define MAXN (int)(500+5)//最大点数
#define INF 0x3f3f3f3f

struct Edge
{
	int from,to,value;
	Edge(int _from,int _to,int _value):from(_from),to(_to),value(_value){} 
	Edge()
	{
		
	}
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

void clear(int n)//便于重复使用 
{
	for(int i=0;i<=n;i++)
	{
		edges[i].clear();//清除所有边
	}
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
		priority_queue<Qnode> pq;
		for(int i=0;i<=n;i++)
		{
			P[i]=i;
		}
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
					P[to]=from;
					dis[to]=dis2;
					pq.push(Qnode(to,dis2));
					//尽管放进去，to会重复也没关系，因为每次取出时都会检查该点是否已求解 
				}
			}
		}
	}
}; 

int point[501];
int size=0;

void printZ(Dijkstra &D,int S,int E)//正向存S到E最短路 
{
	if(D.P[E]!=E)
	{
		printZ(D,S,D.P[E]);
	}
	point[size++]=E; 
} 

void printF(Dijkstra &D,int S,int E)//反向存S到E最短路 
{
	while(D.P[E]!=E)
	{
		point[size++]=E; 
		E=D.P[E];
	}
	point[size++]=E; 
} 

Edge com[2005];

int main()
{
	//freopen("test.txt","w",stdout);
	int N,S,E,i,j,k,ans,tem,M,K,X,Y,Z,cas=1;
	bool used;//是否走B类
	int mid;//中介，若走B类为中介边下标，若不走为中介点编号 
	Dijkstra from,to;
	while(cin>>N>>S>>E)//节点数，起点，终点 
	{
		if(cas!=1)
		{
			printf("\n");
		}
		cas++;
		cin>>M;//普通边数
		from.n=N,from.m=M;
		to.n=N,to.m=M;
		clear(N);
		for(i=1;i<=M;i++)
		{
			scanf("%d %d %d",&X,&Y,&Z);
			edges[X].push_back(Edge(X,Y,Z));
			edges[Y].push_back(Edge(Y,X,Z));
		}
		from.Solve(S);
		to.Solve(E);
		cin>>K;
		for(i=1;i<=2*K;)
		{
			scanf("%d %d %d",&X,&Y,&Z);
			com[i].from=X,com[i].to=Y,com[i].value=Z;
			i++; 
			com[i].from=Y,com[i].to=X,com[i].value=Z;
			i++;
		}
		int MIN=0x7fffffff;
		used=0;
		MIN=from.dis[E];
		for(i=1;i<=2*K;i++)
		{
			//枚举B类边 
			if(from.dis[com[i].from]+to.dis[com[i].to]+com[i].value<MIN)
			{
				mid=i;
				MIN=from.dis[com[i].from]+to.dis[com[i].to]+com[i].value;
				used=1;
			}
		}
		
		size=0;
		
		if(used)
		{
			printZ(from,S,com[mid].from);
			printF(to,E,com[mid].to);
		} 
		else
		{
			printZ(from,S,E);
		}
		
		for(i=0;i<size;i++)
		{
			if(i!=size-1)
			{
				printf("%d ",point[i]);
			}
			else
			{
				printf("%d",point[i]);
			}
		}
		
		putchar('\n');
		if(used)
		{
			printf("%d\n",com[mid].from);
		}
		else
		{
			printf("Ticket Not Used\n");
		}
		printf("%d\n",MIN);
		
	} 
	return 0; 
}

/*
2 1 2
1
1 2 5
1
2 1 4
*/
