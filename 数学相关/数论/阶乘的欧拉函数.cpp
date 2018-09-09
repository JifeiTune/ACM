#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
求[1-n!]中，所有质因子都大于m的数的个数
所有质因子都大于m，可等价转换为与m!互质
于是相当于求[1-n!]中与m!互质的数的个数
特别注意题目中有n>=m，即n!必为m!的倍数
于是可以用那种质因子循环的方式求
关键就是求出m!的欧拉函数了 
最后要除去1，因为1虽然与m!互质，但不是质因子 
*/
using namespace std;

#define MAX (int)(10000000)//此处控制筛选范围 
#define MOD 100000007

bool x[MAX+1];//标记为1表示是合数，0表示质数 
int Fe[MAX+1];//阶乘的欧拉函数 

inline void getP()
{
	long long bs,i;
	long long range=(long long)(sqrt(MAX)+1);
	memset(x,0,sizeof(x));//先全部标记为质数 
	for(i=2;i<=range;i++)
	{
		if(!x[i])//未标记，说明是质数 
		{
			bs=i;//倍数一开始就设为i，因为小于i的数之前已经筛过 
			while(bs*i<=MAX)
			{
				x[bs*i]=1;
				bs++;
			}
		}
	}
}

void getFe()//递推得到每个阶乘的欧拉函数 
{
	int i;
	Fe[1]=1;
	Fe[2]=1;
	for(i=3;i<=MAX;i++)
	{
		if(!x[i])//质数
		{
			Fe[i]=(((long long)Fe[i-1])*(i-1))%MOD;
		}
		else
		{
			Fe[i]=(((long long)Fe[i-1])*i)%MOD;	
		}	
	} 
}

int main()
{
	getP();
	getFe();
	int n,m,i;
	long long tem;
	while(scanf("%d%d",&n,&m))
	{
		if(n==0&&m==0)
		{
			break;
		}
		tem=1;
		for(i=m+1;i<=n;i++)
		{
			tem=(tem*i)%MOD;//先求n!/m! 
		}
		printf("%lld\n",(tem*Fe[m]-1+MOD)%MOD); 
	}
	return 0; 
}


