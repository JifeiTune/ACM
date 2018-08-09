#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
using namespace std;

/*
������е㶼���� 
���߰�Ȩֵ��С��������
ֻҪ�ߵ������˵�ֱ��ڲ�ͬ�����У��ӱߺ󲻻��л����ͼ���
����ͼ���ӱ߼�һ����OK 
*/ 

/*
ʹ�ò���
1.����MAXN��MAXE
2.ÿ��ʹ��ǰ��Enum=0��Ȼ��ӱ�
3.����Kruskal(n)��nΪ�ڵ������򷵻���С������Ȩֵ
���Ŵ�0��ʼ�ʹ�1��ʼ��OK����Ϊ��������edges�����У������ֶ��� 
*/ 

#define MAXN (int)(1e3+1)//������ 
#define MAXE (int)(1e3+1)//������ 

struct Edge
{
	int from,to,value;
};

Edge edges[MAXE];//���еı�
int Enum;//������ʹ��ǰ�ȳ�ʼ��Ϊ0
int points[MAXN];//���еĵ���

void add(int f,int t,int v)//�ӱ� 
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

int Kruskal(int n)//nΪ�ڵ�������Ŵ�0��ʼ���Ǵ�1��ʼ��OK 
{
	int i,from,to,val,ans=0,num=0,f1,f2;
	for(i=0;i<=n;i++)//�������Ŵ�0��ʼ���Ǵ�1��ʼ��OK 
	{
		points[i]=i;//���鼯��ʼ�� 
	}
	sort(edges,edges+Enum,CMP);
	for(i=0;i<Enum;i++)//�������еı� 
	{
		from=edges[i].from;
		to=edges[i].to;
		val=edges[i].value;
		f1=find(from);
		f2=find(to);
		if(f1!=f2)//�ӱ߲��������
		{
			points[f2]=f1;
			num++;//
			ans+=val;//����Ȩֵ	
		}
	}
	if(num!=n-1)//ͼ����ͨ�������� 
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


