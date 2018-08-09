#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<queue> 

using namespace std;

/*
POJ 2010
Moo University - Financial Aid

共F资金，从C个学生中选N（奇数）个进行资助
每个学生有分数S和申请资金M
问如何选取使得N个学生分数中位数最大，输出此中位数
分给N个学生的资金和不能超过F

枚举中位数，计算比该分数小的N/2个学生资金最小和
以及比该分数大的N/2个学生资金最小和
最后在符合条件的中位数中找最大即可

可采用优先队列实现，新增学生时，资金与堆顶比较
更小则pop堆顶，push新元素，同时更新资金之和
*/ 
struct stu
{
	long long sco;//分数 
	long long mon;//申请资金
}x[100001];

bool CMP(stu a,stu b)//按分数从小到大排序，便于枚举中位数 
{
	return a.sco<b.sco;
}

long long Left[100001];//Left[i]为i左边N/2个学生的申请资金和的最小值 
long long Right[100001];

int main()
{
	long long N,C,F,i,j,ans,L,R;
	scanf("%lld%lld%lld",&N,&C,&F);
	for(i=1;i<=C;i++)
	{
		scanf("%lld %lld",&x[i].sco,&x[i].mon);
	}
	sort(x+1,x+1+C,CMP);//排行序才能枚举中位数 
	L=N/2+1,R=C-N/2;//可选中位数范围 
	priority_queue<long long> q1,q2;
	Left[L]=0;
	for(i=1;i<L;i++)
	{
		Left[L]+=x[i].mon;
		q1.push(x[i].mon);
	}
	for(i=L+1;i<=R;i++)
	{
		if(x[i-1].mon<q1.top())//有更小的 
		{
			Left[i]=Left[i-1]-q1.top()+x[i-1].mon;
			q1.pop();
			q1.push(x[i-1].mon);
		}
		else
		{
			Left[i]=Left[i-1];
		}
	}
	Right[R]=0;
	for(i=C;i>R;i--)
	{
		Right[R]+=x[i].mon;
		q2.push(x[i].mon);
	}
	for(i=R-1;i>=L;i--)
	{
		if(x[i+1].mon<q2.top())
		{
			Right[i]=Right[i+1]-q2.top()+x[i+1].mon;
			q2.pop();
			q2.push(x[i+1].mon);
		}
		else
		{
			Right[i]=Right[i+1];
		}
	}
	for(i=R;i>=L;i--)
	{
		if(x[i].mon+Left[i]+Right[i]<=F)
		{
			printf("%lld",x[i].sco);
			return 0;
		}
	}
	printf("-1");
	return 0;
}

