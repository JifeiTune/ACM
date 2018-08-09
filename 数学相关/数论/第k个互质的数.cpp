#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<vector>
using namespace std;
/*
超级暴力…… 
更高级的，还没看懂……
若m与x互质，则m与x+m,x+2*m……都互质
于是，求出比m小且与m互质的所有数
它们各自加上m*i(i>=0且i为整数)都与m互质，取余构成循环 
*/
int pri[1000005];//比k小的所有与m互质的数，以后每加m循环一次 
int size;

inline int gcd(int a,int b)
{
	int tem=a%b;
	while(tem!=0)
	{
		a=b;
		b=tem;
		tem=a%b;
	}
	return b;
}

int main()
{
	int m,k,i,j,ans,tem;
	while(~scanf("%d%d",&m,&k))
	{
		size=1;
		pri[0]=1;
		for(i=2;i<m;i++)
		{
			if(gcd(m,i)==1)
			{
				pri[size++]=i;
			}
		}
		if(k<=size)
		{
			printf("%d\n",pri[k-1]);
		}
		else
		{
			i=(k-1)/size;//第i+1次循环
			j=k%size;//循环内第j个
			if(j==0) 
			{
				j=size;
			}
			printf("%d\n",i*m+pri[j-1]);
		}
	}
	return 0; 
}














