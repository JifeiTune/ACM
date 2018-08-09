#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<map>
using namespace std;
/*
原理很简单，合数总是可以看成比自己小的数的倍数
首先所有数都未标记，看做质数，然后从2开始，每当找到一个未标记的数
认定它为质数，然后标记范围内所有它的倍数（2倍起），最后剩下的未标记的就是质数
寻找到sqrt(MAX)即可，因为此时倍数已经可以达到MAX 
*/ 
#define MAX (int)(1e6+1)//此处控制筛选范围 

bool x[MAX];//标记为1表示是合数，0表示质数 

int main()
{
	long long bs,i;
	long long range=(long long)(sqrt(MAX)+1);
	memset(x,0,sizeof(x));//先全部标记为质数 
	for(i=2;i<=range;i++)
	{
		if(!x[i])//未标记，说明是质数 
		{
			bs=2;
			while(bs*i<=MAX)
			{
				x[bs*i]=1;
				bs++;
			}
		}
	}
	for(i=2;i<=MAX;i++)
	{
		if(!x[i])
		{
			printf("%lld\n",i);
		}
	}
	return 0; 
}













