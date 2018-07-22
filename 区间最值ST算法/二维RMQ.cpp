#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 

using namespace std;

#define num (250*250)
#define LOG 250//数组长度以2为底的对数
/*
POJ - 2019 Cornfields  
本题数组较大，但所存值最大只为250，故使用unsigned char来存 
*/
unsigned char x[num+1];//将二维数组按一维存 
unsigned char MAX[num+1][LOG+1];
unsigned char MIN[num+1][LOG+1];
int len;//矩阵宽度 

#define trans(i,j) ((i-1)*len+j)//二维坐标变成一维坐标 

inline short max(short x,short y)
{
	return x>y?x:y;
}

inline short min(short x,short y)
{
	return x<y?x:y;
}

inline double log2(double x)
{
	return  log(x)/log(2.0)+1e-8;
}

inline void init()//初始化数组后别忘了init！
{
	int f=(int)log2(len),i,j,k;
	for(i=1;i<=len*len;i++)
	{
		MAX[i][0]=x[i];
		MIN[i][0]=x[i];//以i开头长度为2^0的最值当然是自己 
	}
	for(j=1;j<=f;j++)
	{
		for(k=1;k<=len;k++)//一行一行来 
		{
			for(i=trans(k,1);i+(1<<j)-1<=trans(k,len);i++)//注意范围，右坐标未超出数组下标才有计算的意义 
			{
				MAX[i][j]=max(MAX[i][j-1],MAX[i+(1<<(j-1))][j-1]); 
				MIN[i][j]=min(MIN[i][j-1],MIN[i+(1<<(j-1))][j-1]);//划分成长度相等的两个子区间 
			}
		}
	}
}

inline int answer(int i,int j,int k,bool what)//以(i,j)为左上角，宽为k的子矩阵最值 
{
	int but=i+k-1,ans,wid=k;
	k=(int)log2(k);
	if(what)
	{
		ans=MAX[trans(i,j)][0];
		for(;i<=but;i++)
		{
			ans=max(ans,max(MAX[trans(i,j)][k],MAX[trans(i,j)+wid-(1<<k)][k]));
		}
		return ans;
	}
	else
	{
		ans=MIN[trans(i,j)][0];
		for(;i<=but;i++)
		{
			ans=min(ans,min(MIN[trans(i,j)][k],MIN[trans(i,j)+wid-(1<<k)][k]));
		}
		return ans;
	}
}

int main()
{
	int N,B,K,i,j,ans,tem;
	scanf("%d%d%d",&N,&B,&K);
	len=N;
	for(i=1;i<=len;i++)
	{
		for(j=1;j<=len;j++)
		{
			scanf("%u",&x[trans(i,j)]);
		}
	}
	init();
	while(K--)
	{
		scanf("%d%d",&i,&j);
		printf("%d\n",answer(i,j,B,1)-answer(i,j,B,0));	
	} 
	return 0; 
}



















