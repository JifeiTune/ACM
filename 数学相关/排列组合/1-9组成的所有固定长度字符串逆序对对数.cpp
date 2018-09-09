#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
/*
求所有由1-9组成的长度为n的序列逆序对总数。
每次考虑n中两个位置i,j(i<j)的情况，有C(n,2)个位置对 
每对位置选两个不同的数，有C(9,2)个
剩余n-2个位置随意填充，有pow(9,n-2)个
全部乘起来即可 
*/
inline unsigned long long Qpow(unsigned long long x,unsigned long long n)//指数看做二进制，x^(2^0) * x^(2^1)（该位需为1）…… 
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
