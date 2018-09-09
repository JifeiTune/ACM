#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<vector> 
/*
��[A,B]����n���ʵ����ĸ���
A��B�ﵽ1e15��n�ﵽ1e9
ת��Ϊ����[1,A]����n���ʵ����ĸ���������[1,B]�е�
���������Ϊ���
���Ǽ�ʹ������n���ʵ�����ѭ������ѭ��Ҳ̫����
��ת�������������ﲻ���ʵ����ĸ���������Ԫ�ظ�����ȥ����Ϊ��� 
��ô��n�ֽ������ӣ�������ֻҪ�������ӵı�������֮���ʣ���������������� 
���ǲ�ͬ�����ӱ������ܻ�һ����������ͨɸ����������
*/
using namespace std;

struct Node
{
	int pf;//������
	int num;//����
	Node(){}
	Node(int _pf,int _num):pf(_pf),num(_num){}
}; 

inline void Factor(int x,vector<Node> &ans)//��x���������ӷֽ�,�������ans 
{
	ans.reserve(11);//��int���Ѿ��㹻 
	int i,num,ed;
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			num=0;
			while(x%i==0)
			{
				num++;
				x/=i;
			}
			ans.push_back(Node(i,num));
		}
	}
	if(x>1)
	{
		ans.push_back(Node(x,1));
	}
}

inline long long Cal(long long R,int x)//[1,R]�Ĵ�������ж��ٸ���x���ʵ���
{
	vector<Node> f;
	Factor(x,f);//�ȶ�x�����������ֽ�
	int i,j,num,tem,size,all;
	long long ans=0;
	size=f.size();
	all=(1<<size)-1;//ȫ�� 
	for(i=1;i<=all;i++)
	{
		num=0;//ѡȡ�������Ӹ��� 
		tem=1;//ѡȡ�������ӳ˻� 
		for(j=0;j<size;j++)//Ϊ1��λ��Ҫѡȡ 
		{
			if(i&(1<<j))
			{
				num++;
				tem*=f[j].pf;
			}
		}
		if(num%2==1)//���ż�� 
		{
			ans+=R/tem;
		}
		else
		{
			ans-=R/tem;
		}
	}
	return R-ans;//��ȥ�����ʵļ�Ϊ���ʵĸ��� 
}

int main()
{
	long long L,R;
	int n,T,ans,k,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%d",&L,&R,&n);
		printf("Case #%d: %lld\n",cas++,Cal(R,n)-Cal(L-1,n));	
	}
	return 0; 
}


