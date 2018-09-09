#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<map>
using namespace std;
/*
原理很简单，合数总是可以看成比自己小的数的倍数
首先所有数都未标记，看做质数，然后从2开始，每当找到一个未标记的数i
认定它为质数，然后标记范围内所有它的倍数（i倍起，因为小于i的数之前筛过）
最后剩下的未标记的就是质数
寻找到sqrt(MAX)即可，因为此时i倍已经可以达到MAX
*/ 
#define MAX (int)(1000)//此处控制筛选范围 

bool x[MAX+1];//标记为1表示是合数，0表示质数 

inline void getP()
{
	long long bs,i;
	long long range=(long long)(sqrt(MAX)+1);
	memset(x,0,sizeof(x));//先全部标记为质数 
	for(i=2;i<=range;i++)
	{
		if(!x[i])//未标记，说明是质数 
		{
			bs=i;//倍数一开始就设为i，因为小于i的数之前已经筛过 
			while(bs*i<=MAX)
			{
				x[bs*i]=1;
				bs++;
			}
		}
	}
} 

int main()
{
	getP();
	int i;
	for(i=2;i<=MAX;i++)
	{
		if(!x[i])
		{
			printf("%lld\n",i);
		}
	}
	return 0; 
}













