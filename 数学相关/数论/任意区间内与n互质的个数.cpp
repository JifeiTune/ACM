#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<vector> 
/*
求[A,B]中与n互质的数的个数
A、B达到1e15，n达到1e9
转换为先求[1,A]中与n互质的数的个数，再求[1,B]中的
二者相减即为结果
可是即使利用与n互质的数的循环来求，循环也太大了
再转换成先求区间里不互质的数的个数，区间元素个数减去它即为结果 
那么对n分解质因子，区间里只要是质因子的倍数就与之互质，于是求最大倍数即可 
但是不同质因子倍数可能会一样（想想普通筛法求质数表）
*/
using namespace std;

struct Node
{
	int pf;//质因子
	int num;//个数
	Node(){}
	Node(int _pf,int _num):pf(_pf),num(_num){}
}; 

inline void Factor(int x,vector<Node> &ans)//对x进行质因子分解,结果存于ans 
{
	ans.reserve(11);//对int型已经足够 
	int i,num,ed;
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			num=0;
			while(x%i==0)
			{
				num++;
				x/=i;
			}
			ans.push_back(Node(i,num));
		}
	}
	if(x>1)
	{
		ans.push_back(Node(x,1));
	}
}

inline long long Cal(long long R,int x)//[1,R]的大区间里，有多少个与x互质的数
{
	vector<Node> f;
	Factor(x,f);//先对x进行质因数分解
	int i,j,num,tem,size,all;
	long long ans=0;
	size=f.size();
	all=(1<<size)-1;//全集 
	for(i=1;i<=all;i++)
	{
		num=0;//选取的质因子个数 
		tem=1;//选取的质因子乘积 
		for(j=0;j<size;j++)//为1的位需要选取 
		{
			if(i&(1<<j))
			{
				num++;
				tem*=f[j].pf;
			}
		}
		if(num%2==1)//奇加偶减 
		{
			ans+=R/tem;
		}
		else
		{
			ans-=R/tem;
		}
	}
	return R-ans;//减去不互质的即为互质的个数 
}

int main()
{
	long long L,R;
	int n,T,ans,k,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%d",&L,&R,&n);
		printf("Case #%d: %lld\n",cas++,Cal(R,n)-Cal(L-1,n));	
	}
	return 0; 
}


