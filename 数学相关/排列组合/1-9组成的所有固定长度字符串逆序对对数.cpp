#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
/*
��������1-9��ɵĳ���Ϊn�����������������
ÿ�ο���n������λ��i,j(i<j)���������C(n,2)��λ�ö� 
ÿ��λ��ѡ������ͬ��������C(9,2)��
ʣ��n-2��λ��������䣬��pow(9,n-2)��
ȫ������������ 
*/
inline unsigned long long Qpow(unsigned long long x,unsigned long long n)//ָ�����������ƣ�x^(2^0) * x^(2^1)����λ��Ϊ1������ 
{
	if(x==1)
	{
		return 1;	
	}
	unsigned long long tem=x;//x^(2^0)
	unsigned long long ans=1;	
	while(n)
	{
		if(n&1)
		{
			ans=ans*tem;
		}
		n>>=1;
		tem=tem*tem;//x^(2^i)->x^(2^(i+1)) 
	}
	return ans;
} 

int main()
{
    unsigned long long ans,T,n,i,j,k;
    scanf("%llu",&T);
    while(T--)
    {
    	scanf("%llu",&n);
    	ans=n*(n-1)*2;
    	ans*=Qpow(9,n-1);
    	printf("%llu\n",ans);
	}
    return 0;
}
