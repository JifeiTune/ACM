#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
��һ������a1-an
ÿ��ѯ������[L,R]����a(R)*1+a(R-1)*2����+a(L)*L�����������ڲ���ʾԪ���±� 
�����޸�ĳ��Ԫ�ص�ֵ
��Ϊ�Ǹ���ͷǳ��й��ɣ����Կ�������״�������
һ��ǰ׺��Ϊa1,a2,a3����
��һ��ǰ׺��Ϊa1*n,a2*(n-1)����
֮������ȥһ����������
������
7   5   2   4   6   8
7*6 5*5 2*4 4*3 6*2 8*1 
sum(1,3)=(7*6+5*5+2*4)-3*(7+5+2)
*/
using namespace std;

#define lowbit(x) (x&-x)

long long MAX;//��״���������岿������±� 

long long sum(long long n,long long x[])//��ǰ׺�� 
{
	long long ans=0;
	while(n>0)
	{
		ans+=x[n];
		n-=lowbit(n);
	}
	return ans;
}

void add(long long p,long long a,long long x[])//�޸�ֵ��pλ�ã�a���ϵ�ֵ 
{
	if(p<1)
	{
		return;
	}
	while(p<=MAX)
	{
		x[p]+=a;
		p+=lowbit(p);
	}
} 
long long x[100001];
long long y[100001];
int main()
{
	MAX=100000;
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	long long n,i,j,k,ans,q,tem,op,L,R;
	scanf("%lld%lld",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&tem);
		add(i,tem,x);
		add(i,tem*(n-i+1),y);
	}
	while(q--)
	{
		scanf("%lld%lld%lld",&op,&L,&R);
		if(op==1)//��� 
		{
			printf("%lld\n",(sum(R,y)-sum(L-1,y))-(n-R)*(sum(R,x)-sum(L-1,x)));
		}
		else//�޸� 
		{
			add(L,-(sum(L,x)-sum(L-1,x))+R,x);
			add(L,-(sum(L,y)-sum(L-1,y))+R*(n-L+1),y);
		}
	}
	return 0; 
}


