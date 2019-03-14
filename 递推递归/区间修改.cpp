#include<iostream>
#include<cstring>
#include<memory.h>
#include<algorithm>
#include<vector> 
using namespace std;

long long x[110005];//每个点伤害 
long long dam[110005];//每个点走到终点伤害 
/*
HDU4970Killing
Monsters

1-n的区间内，有m个炮台，每个炮台能在[L,R]内每一个整数点上施加K伤害
现在给出num个怪兽，每个怪兽在p点，生命为h，问最后有多少只怪兽能走出n
区间修改，普通树状数组不行，线段树又不会写
其实一开始想到了，对x[L]加上k，x[R+1]减去k，求个前缀和是能求出每一点伤害的
这个确实能用树状数组，但对每个伤害区间，内部每一点都应加K才是最终伤害
这没法用树状数组
后来才发现，递推求和不就完事了……根本用不着树状数组和线段树…… 
*/ 

int main()
{
	int n,m,L,R,K,num,ans,i;
	long long h,p;
	while(scanf("%d",&n)&&n!=0)
	{
		ans=0;
		memset(x,0,sizeof(x));
		memset(dam,0,sizeof(dam));
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d%d",&L,&R,&K);
			x[L]+=K;
			x[R+1]-=K;
		}
		for(i=2;i<=n;i++)//通过求和更新每一点伤害 
		{
			x[i]+=x[i-1];
		}
		for(i=n;i>=1;i--) 
		{
			dam[i]=dam[i+1]+x[i];
		}
		scanf("%d",&num);
		while(num--)
		{
			scanf("%lld%lld",&h,&p);
			{
				if(dam[p]<h)
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0; 
}


