#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
树状数组里前缀和是从1开始算的 
*/
using namespace std;

#define lowbit(x) (x&-x)

int MAX;//树状数组有意义部分最大下标 
int x[100001];

int sum(int n)//求前缀和 
{
	int ans=0;
	while(n>0)
	{
		ans+=x[n];
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
		x[p]+=a;
		p+=lowbit(p);
	}
} 

int main()
{
	
	return 0; 
}


