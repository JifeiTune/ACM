#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>

using namespace std;

//���ֿ����ݺ�ÿ�ν��ݶ��֣��ݹ�ʵ�ֵ�ԭ��ͬ 
inline long long Qpow(long long x,long long n,long long MOD)//ָ�����������ƣ�x^(2^0) * x^(2^1)����λ��Ϊ1������ 
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






