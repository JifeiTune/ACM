#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
对一个序列a1-an
每次询问区间[L,R]，求a(R)*1+a(R-1)*2……+a(L)*L，其中括号内部表示元素下标 
或者修改某个元素的值
因为那个求和非常有规律，所以可以用树状数组求解
一个前缀和为a1,a2,a3……
另一个前缀和为a1*n,a2*(n-1)……
之后对齐减去一个倍数即可
举例：
7   5   2   4   6   8
7*6 5*5 2*4 4*3 6*2 8*1 
sum(1,3)=(7*6+5*5+2*4)-3*(7+5+2)
*/
using namespace std;

#define lowbit(x) (x&-x)

long long MAX;//树状数组有意义部分最大下标 

long long sum(long long n,long long x[])//求前缀和 
{
	long long ans=0;
	while(n>0)
	{
		ans+=x[n];
		n-=lowbit(n);
	}
	return ans;
}

void add(long long p,long long a,long long x[])//修改值，p位置，a加上的值 
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
		if(op==1)//求和 
		{
			printf("%lld\n",(sum(R,y)-sum(L-1,y))-(n-R)*(sum(R,x)-sum(L-1,x)));
		}
		else//修改 
		{
			add(L,-(sum(L,x)-sum(L-1,x))+R,x);
			add(L,-(sum(L,y)-sum(L-1,y))+R*(n-L+1),y);
		}
	}
	return 0; 
}


