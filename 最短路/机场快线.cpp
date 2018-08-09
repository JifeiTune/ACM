#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<vector>
#include<queue> 
using namespace std;


#define MAXN (int)(500+5)//������
#define INF 0x3f3f3f3f

struct Edge
{
	int from,to,value;
	Edge(int _from,int _to,int _value):from(_from),to(_to),value(_value){} 
	Edge()
	{
		
	}
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

void clear(int n)//�����ظ�ʹ�� 
{
	for(int i=0;i<=n;i++)
	{
		edges[i].clear();//������б�
	}
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
		priority_queue<Qnode> pq;
		for(int i=0;i<=n;i++)
		{
			P[i]=i;
		}
		while(!pq.empty())
		{
			pq.pop();//���գ� 
		}
		dis[S]=0;
		pq.push(Qnode(S,0));
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

int point[501];
int size=0;

void printZ(Dijkstra &D,int S,int E)//�����S��E���· 
{
	if(D.P[E]!=E)
	{
		printZ(D,S,D.P[E]);
	}
	point[size++]=E; 
} 

void printF(Dijkstra &D,int S,int E)//�����S��E���· 
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
	bool used;//�Ƿ���B��
	int mid;//�н飬����B��Ϊ�н���±꣬������Ϊ�н���� 
	Dijkstra from,to;
	while(cin>>N>>S>>E)//�ڵ�������㣬�յ� 
	{
		if(cas!=1)
		{
			printf("\n");
		}
		cas++;
		cin>>M;//��ͨ����
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
			//ö��B��� 
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
