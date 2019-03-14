#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
2018青岛赛区网络赛J题 
两个数的倍数，以它们的最小公倍数为循环节构成循环
如5 7
5 7 10 14 15 20 21 25 28 30 35
40 42…… 
*/
using namespace std;

inline long long gcd(long long x,long long y)//求解x与y的最大公约数
{
	long long tem;
	while((tem=x%y)!=0)
	{
		x=y;
		y=tem;
	}
	return y;
}

struct Node
{
	long long num;//数字
	long long pot;//到当前的得分
	long long add;//该加的分数 
	Node(){}
	Node(long long _num):num(_num){}
	bool operator < (const Node& r) const 
	{
		return num<r.num;
	}
};

long long a,b,c,d;//a倍按b次，c倍按d次 
long long v,t;//按一次v+0.5倒计时，总游戏时间0-t 
long long CM;//公倍数 
long long Cnum;//循环节长度 
long long Size;//循环元素个数 

Node cyc[10000001];//一个循环内所有数 

int main()
{
	long long T,i,j,k,ans,tem,pos;
	long long MAX;//循环长度 
	long long bs,ys;//倍数和余数 
	bool L;//灯亮还是灭 
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&v,&t);
		if(a>c)//使a更小 
		{
			swap(a,c);
			swap(b,d);
		}
		CM=(a*c)/gcd(a,c);//公倍数
		Size=0;
		i=1;
		while(i*a<CM)
		{
			cyc[Size].num=i*a;
			cyc[Size].add=b;
			Size++;
			i++; 
		}
		i=1;
		while(i*c<CM)
		{
			cyc[Size].num=i*c;
			cyc[Size].add=d;
			Size++;
			i++;
		}
		cyc[Size].num=CM;
		cyc[Size].add=b+d;
		Size++;
		sort(cyc,cyc+Size);
		Cnum=cyc[Size-1].num;
		if(v>=a)//每次循环前灯亮 
		{
			cyc[0].pot=b;
			if(a==c)
			{
				cyc[0].pot=b+d;
			} 
		}
		else
		{
			cyc[0].pot=b-1;
			if(a==c)
			{
				cyc[0].pot=b+d-1;	
			}
		}
		
		for(i=1;i<Size;i++)
		{
			if(cyc[i].num-cyc[i-1].num<=v)
			{
				cyc[i].pot=cyc[i-1].pot+cyc[i].add;
			}
			else
			{
				cyc[i].pot=cyc[i-1].pot+cyc[i].add-1;
			}
		}
		MAX=cyc[Size-1].pot;
		bs=t/Cnum;
		ys=t%Cnum;
		ans=bs*MAX;
		pos=upper_bound(cyc,cyc+Size,Node(ys))-cyc;
		if(pos!=0)//防止找不到的情况 
		{
			ans+=cyc[pos-1].pot;
		}
		printf("%lld\n",ans+b+d-1);
	} 
	return 0; 
}
/*
100
3 1 7 2 3 8
*/

