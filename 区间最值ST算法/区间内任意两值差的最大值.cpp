#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<math.h> 

using namespace std;

/*
POJ - 3264
Balanced Lineup
*/ 

#define num 50000//数组最大长度
#define LOG ((int)log2(num))//数组长度以2为底的对数

//假设数组下标从1开始
int x[num+1]; 
int MAX[num+1][LOG+1];
int MIN[num+1][LOG+1];
int len;//数组实际使用长度 

void init()//初始化数组后别忘了init！ 
{
	int f=(int)log2(len),i,j;
	for(i=1;i<=len;i++)
	{
		MAX[i][0]=x[i];
		MIN[i][0]=x[i];//以i开头长度为2^0的最值当然是自己 
	}
	for(j=1;j<=f;j++)
	{
		for(i=1;i+(1<<j)-1<=len;i++)//注意范围，右坐标未超出数组下标才有计算的意义 
		{
			MAX[i][j]=max(MAX[i][j-1],MAX[i+(1<<(j-1))][j-1]); 
			MIN[i][j]=min(MIN[i][j-1],MIN[i+(1<<(j-1))][j-1]);//划分成长度相等的两个子区间 
		}
	}
}

int answer(int i,int j,bool what)//求i到j最值，what为1表示求最大值，为0表示求最小值 
{
	int k=(int)log2(j-i+1);
	if(what)
	{
		return max(MAX[i][k],MAX[j-(1<<k)+1][k]);
	}
	else
	{
		return min(MIN[i][k],MIN[j-(1<<k)+1][k]);
	}
}

int main()
{
	int N,Q,i,j,tem,ans;
	scanf("%d%d",&N,&Q);
	len=N;
	for(i=1;i<=len;i++)
	{
		scanf("%d",&x[i]);	
	} 
	init();
	while(Q--)
	{
		scanf("%d%d",&i,&j);
		printf("%d\n",answer(i,j,1)-answer(i,j,0)); 
	}
	return 0; 
}




















