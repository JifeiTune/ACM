#include<iostream>
#include<cmath>
using namespace std; 
/*
求所有k%n的和
当n>k时结果都为k
小于k部分，打表可以发现
当i>sqrt(n)时，结果根据n/i的值分段，成等差数列
分段求和即可 
*/
inline long long sum(long long be,long long num,long long d)//等差求和 
{
	return num*be+d*num*(num-1)/2;
}


int main()
{
	int n,k,i,front,num,be,tem,end,t1,t2;
	long long ans;
	while(~scanf("%d%d",&n,&k))
	{
		ans=0;
		if(n>k)//后面段 
		{
			ans+=((long long)k)*(n-k);
		}
		front=sqrt(k)+1;
		tem=min(front-1,n);
		for(i=1;i<=tem;i++)//前面段 
		{
			ans+=k%i;
		}
		end=k/front;
		tem=min(n,k);
		tem=k/tem;
		for(i=tem;i<=end;i++)//一段段枚举 
		{
			t1=k/(i+1);
			t2=min(k/i,n);
			num=t2-t1;
			be=k%t2;
			ans+=sum(be,num,i);
		}
		printf("%lld\n",ans);
	}
	
	return 0; 
}





