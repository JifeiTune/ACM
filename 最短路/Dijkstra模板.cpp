#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<vector>
#include<queue> 
using namespace std;

/*
��ģ����Ŵ�0��ʼ�ʹ�1��ʼ���� 
*/

#define MAXN (int)(1e6+1)//������
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

struct Dijkstra
{
	int n,m;//�����ͱ���
	vector<Edge> edges[MAXN];//ÿ������������бߣ����0��ʼ���
	int dis[MAXN];//Դ�㵽ÿ���ڵ����̾���
	bool vis[MAXN];//��ǽڵ��Ƿ������ 
	
	void clear()//�����ظ�ʹ�� 
	{
		for(int i=0;i<=n;i++)//������Ŵ�0��ʼ�ʹ�1��ʼ��OK 
		{
			edges[i].clear(); 
		}
	}
	
	void Solve(int S)//����S���������е�����· 
	{
		int i,j;
		int from,to,dis1,dis2;
		Qnode tem(0,0);
		memset(vis,0,sizeof(vis));
		memset(dis,0x3f,sizeof(dis));//��ʼ�������·����Ϊ����� 
		priority_queue<Qnode> pq;
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
					//�����¼·����������ʹ��path�����¼��ǰ���·�е�ǰ�ڵ����һ�ڵ������һ�ڵ㼴�� 
					dis[to]=dis2;
					pq.push(Qnode(to,dis2));
					//���ܷŽ�ȥ��to���ظ�Ҳû��ϵ����Ϊÿ��ȡ��ʱ������õ��Ƿ������ 
				}
			}
		}
	}
}; 

int main()
{
	

	return 0; 
}













