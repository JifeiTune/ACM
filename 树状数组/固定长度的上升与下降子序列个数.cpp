#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
UVALive - 4329
Ping pong
*/
using namespace std;

#define lowbit(x) (x&-x)

int ab[100001];
int low[20001];
int high[20001];
int help[100001]; 
int MAX;

int sum(int n)//求前缀和
{
	int ans=0;
	while(n>0)
	{
		ans+=help[n];
		n-=lowbit(n);
	}
	return ans;
}

void add(int p,int a)//修改值，p位置，a加上的值 
{
	if(p<1)
	{
		return;
	}
	while(p<=MAX)
	{
		help[p]+=a;
		p+=lowbit(p);
	}
} 

int main()
{
	int T,n,i,j,tem;
	long long ans;
	scanf("%d",&T);
	while(T--)
	{
		MAX=0;
		ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&ab[i]);
			MAX=MAX>=ab[i]?MAX:ab[i];
		}
		memset(help,0,sizeof(help));
		for(i=1;i<=n;i++)
		{
			add(ab[i],1);
			low[i]=sum(ab[i]-1);
		}
		memset(help,0,sizeof(help));
		for(i=n;i>=1;i--)
		{
			add(ab[i],1);
			high[i]=sum(ab[i]-1);
		}
		for(i=2;i<n;i++)
		{
			ans+=(long long)low[i]*(n-i-high[i])+(i-low[i]-1)*(long long)high[i];
		}
		printf("%lld\n",ans); 
	} 
	return 0; 
}
/*
10
10 3 1 10 5 9 2 8 6 4 7
*/ 
