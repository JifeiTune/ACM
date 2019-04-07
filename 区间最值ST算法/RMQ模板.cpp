#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 

using namespace std;

#define num 100001//数组最大长度
 
/*
数组下标从1开始
*/
int x[num]; 
int MAX[num][20];
int MIN[num][20];
int len;//数组实际使用长度 

void init()//初始化数组后别忘了init！ 
{
	int i,j;
	for(i=1;i<=len;i++)
	{
		MAX[i][0]=x[i];
		MIN[i][0]=x[i];//以i开头长度为2^0的最值当然是自己 
	}
	for(j=1;(1<<j)<=len;j++)
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
	int dis=j-i+1,k=0;
	while((1<<(++k))<=dis);
    --k;
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
	len=10000;
	
	return 0; 
}




















