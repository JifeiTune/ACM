#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>

using namespace std;

//这种快速幂和每次将幂二分，递归实现的原理不同 
inline long long Qpow(long long x,long long n,long long MOD)//指数看做二进制，x^(2^0) * x^(2^1)（该位需为1）…… 
{
	if(x==1)
	{
		return 1;	
	}
	long long tem=x%MOD;//x^(2^0)
	long long ans=1;	
	while(n)
	{
		if(n&1)
		{
			ans=(ans*tem)%MOD;
		}
		n>>=1;
		tem=(tem*tem)%MOD;//x^(2^i)->x^(2^(i+1)) 
	}
	return ans;
} 

int main()
{
	cout<<Qpow(2,20,100);
	return 0; 
}






