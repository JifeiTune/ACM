#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
一个矩形盒子，里面有n块挡板将盒子分成n+1个部分（编号由0至n）
给出m个点，问每个部分有几个点
第一行为挡板数n，点数m，盒子左上角、右下角坐标
接下来n行为每个挡板上端和下端的横坐标，保证挡板从右向左
接下来m行为点的坐标，保证点不在挡板上，也不越界

点到挡板上下端点的两个向量，求叉积，<0则为左，>0则为右，二分确定处于哪个部分 
*/
using namespace std;

struct P
{
	int i,j;
} board[5001];//挡板上下横坐标

int U,L;//顶部和底部纵坐标 
int m,n;

int num[5001];//每个部分的点数 

inline bool Right(int X,int Y,int p)//点(X,Y)是否在board[p]右边 
{
	return ( (board[p].i-X)*(L-Y)-(board[p].j-X)*(U-Y) )>0; 
}

inline void binS(int X,int Y)//二分查找最后一个处于点左边的板，找到了板下标即为num下标，找不到下标为0 
{
	int i=1,j=n,mid;//区间总是为1到n
	while(i<=j)
	{
		mid=(i+j)/2;
		if(Right(X,Y,mid))
		{
			if(mid!=n&&Right(X,Y,mid+1))//注意mid==n的情况 
			{
				i=mid+1;//注意，向下取整的原因，不会越界 
			} 
			else
			{
				num[mid]++;
				return;
			}
		}
		else
		{
			j=mid-1;
		}
	} 
	num[0]++;
}

int main()
{
	int i,j,k,ans,tem,X1,Y1,X2,Y2;
	while(scanf("%d",&n)&&n!=0)
	{
		scanf("%d %d %d %d %d",&m,&X1,&Y1,&X2,&Y2);
		U=Y1,L=Y2;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&board[i].i,&board[i].j);//都是横坐标 
		}
		memset(num,0,sizeof(num));
		for(i=1;i<=m;i++)
		{
			scanf("%d %d",&X1,&Y1);
			binS(X1,Y1);//二分过程中修改num数组s 
		}
		for(i=0;i<=n;i++)
		{
			printf("%d: %d\n",i,num[i]);
		}
		putchar('\n');
	}
	return 0; 
}


