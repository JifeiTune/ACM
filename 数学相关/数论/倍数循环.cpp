#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
2018�ൺ����������J�� 
�������ı����������ǵ���С������Ϊѭ���ڹ���ѭ��
��5 7
5 7 10 14 15 20 21 25 28 30 35
40 42���� 
*/
using namespace std;

inline long long gcd(long long x,long long y)//���x��y�����Լ��
{
	long long tem;
	while((tem=x%y)!=0)
	{
		x=y;
		y=tem;
	}
	return y;
}

struct Node
{
	long long num;//����
	long long pot;//����ǰ�ĵ÷�
	long long add;//�üӵķ��� 
	Node(){}
	Node(long long _num):num(_num){}
	bool operator < (const Node& r) const 
	{
		return num<r.num;
	}
};

long long a,b,c,d;//a����b�Σ�c����d�� 
long long v,t;//��һ��v+0.5����ʱ������Ϸʱ��0-t 
long long CM;//������ 
long long Cnum;//ѭ���ڳ��� 
long long Size;//ѭ��Ԫ�ظ��� 

Node cyc[10000001];//һ��ѭ���������� 

int main()
{
	long long T,i,j,k,ans,tem,pos;
	long long MAX;//ѭ������ 
	long long bs,ys;//���������� 
	bool L;//���������� 
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&v,&t);
		if(a>c)//ʹa��С 
		{
			swap(a,c);
			swap(b,d);
		}
		CM=(a*c)/gcd(a,c);//������
		Size=0;
		i=1;
		while(i*a<CM)
		{
			cyc[Size].num=i*a;
			cyc[Size].add=b;
			Size++;
			i++; 
		}
		i=1;
		while(i*c<CM)
		{
			cyc[Size].num=i*c;
			cyc[Size].add=d;
			Size++;
			i++;
		}
		cyc[Size].num=CM;
		cyc[Size].add=b+d;
		Size++;
		sort(cyc,cyc+Size);
		Cnum=cyc[Size-1].num;
		if(v>=a)//ÿ��ѭ��ǰ���� 
		{
			cyc[0].pot=b;
			if(a==c)
			{
				cyc[0].pot=b+d;
			} 
		}
		else
		{
			cyc[0].pot=b-1;
			if(a==c)
			{
				cyc[0].pot=b+d-1;	
			}
		}
		
		for(i=1;i<Size;i++)
		{
			if(cyc[i].num-cyc[i-1].num<=v)
			{
				cyc[i].pot=cyc[i-1].pot+cyc[i].add;
			}
			else
			{
				cyc[i].pot=cyc[i-1].pot+cyc[i].add-1;
			}
		}
		MAX=cyc[Size-1].pot;
		bs=t/Cnum;
		ys=t%Cnum;
		ans=bs*MAX;
		pos=upper_bound(cyc,cyc+Size,Node(ys))-cyc;
		if(pos!=0)//��ֹ�Ҳ�������� 
		{
			ans+=cyc[pos-1].pot;
		}
		printf("%lld\n",ans+b+d-1);
	} 
	return 0; 
}
/*
100
3 1 7 2 3 8
*/

