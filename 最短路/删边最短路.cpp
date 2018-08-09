#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<vector>
#include<queue> 
using namespace std;

/*
��ģ����Ŵ�0��ʼ 
*/

#define MAXN (int)(1e3+1)//������
#define INF 0x3f3f3f3f

struct Edge
{
	int from,to,value;
	Edge(int _from,int _to,int _value):from(_from),to(_to),value(_value){} 
};

struct Qnode//Ϊʹ�����ȶ������õ� 
{
	int point;//�ڵ� 
	int dis;//��ǰ��̾���
	
	Qnode(int _point,int _dis):point(_point),dis(_dis){}
	bool operator < (const Qnode &right) const
	{
		return dis>right.dis;
		//���ȶ���������<�Ƚϣ������󡱵ķŶѶ����˴���������䷴��ʵ�־���С�ķŶѶ� 
	}
};

vector<Edge> edges[MAXN];//ÿ������������бߣ����0��ʼ���
bool isOK[MAXN][MAXN];	

void clear(int N)//�����ظ�ʹ�� 
{
	for(int i=0;i<=N;i++)//������Ŵ�0��ʼ�ʹ�1��ʼ��OK 
	{
		edges[i].clear(); 
	}
	memset(isOK,0,sizeof(isOK)); 
}

struct Dijkstra
{
	int n,m;//�����ͱ���
	int dis[MAXN];//Դ�㵽ÿ���ڵ����̾���
	bool vis[MAXN];//��ǽڵ��Ƿ������ 
	int P[MAXN];//���·�б��ڵ���һ�ڵ� 
	
	void Solve(int S)//����S���������е�����· 
	{
		int i,j;
		int from,to,dis1,dis2;
		Qnode tem(0,0);
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));//��ʼ�������·����Ϊ�����
		for(int i=0;i<=n;i++)
		{
			P[i]=i;
		}
		priority_queue<Qnode> pq;
		while(!pq.empty())
		{
			pq.pop();//���գ� 
		}
		dis[S]=0;
		Qnode t(S,0); 
		pq.push(t);
		while(!pq.empty()) 
		{
			tem=pq.top();
			pq.pop();//��ǰ������С�ĵ��Ѿ��ý���
			if(vis[tem.point])//��ֹ����������
			{
				continue;
			}
			from=tem.point;//��ǰ�� 
			dis1=tem.dis;//��ǰ����̾��� 
			vis[from]=1;//��Ϊ����� 
			for(i=0;i<edges[from].size();i++)//�õ�����ܵ�������е� 
			{
				to=edges[from][i].to;//��һ����
				if(!isOK[from][to])
				{
					continue;
				}
				dis2=dis1+edges[from][i].value;//�Ե�ǰ��Ϊ�н��ʱ�ľ��� 
				if(!vis[to]&&dis2<dis[to])//��δ��������Ե�ǰ��Ϊ�н��ܴﵽ���̵ľ��� 
				{
					P[to]=from;
					dis[to]=dis2;
					pq.push(Qnode(to,dis2));
					//���ܷŽ�ȥ��to���ظ�Ҳû��ϵ����Ϊÿ��ȡ��ʱ������õ��Ƿ������ 
				}
			}
		}
	}
}; 

int point[1001];//���·���еĽڵ�˳�� 
int size;

void printZ(Dijkstra &D,int S,int E)//�����S��E���· 
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
		//��ʼɾ��
		for(i=0;i<size-1;i++)
		{
			//��Ϊpoint[i]->point[i+1]
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











