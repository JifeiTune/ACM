#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

/*
归并排序，求逆序对对数
首先应知道，设[L1,R1]，[L2,R2]其中L2>R1
[L1,R1]中数的顺序改变，并不会改变一点在[L1,R1]中
另一点在其他区间的逆序对对数，因为两点相对位置（谁左谁右并没有变）
所以归并时，每当左区间头元素大于右区间头元素，则有逆序对
对数为左区间当前剩下的元素个数 
*/
#define MAXN 100001
int x[MAXN+1];
int y[MAXN+1];//辅助数组 
long long Rnum;//逆序对对数 

void Merge(int L,int R,int M)
{
	//将x中L到M，M+1到R两部分，合并到y中的L到R里
	int i,j,k,tem;
	i=L,j=M+1,k=L;
	while(i<=M&&j<=R)//两部分都还能取时 
	{
		//取更小的放前面
		if(x[i]<=x[j])
		{
			y[k++]=x[i++];
		}
		else//仅当左区间头元素更大时有逆序对（注意是严格大于，不能是大于等于！） 
		{
			Rnum+=M-i+1;//左区间剩下的都比右区间头元素大 
			y[k++]=x[j++];
		}
	}
	//现在要么二者都取完，要么只剩一部分未取完 
	while(i<=M)
	{
		y[k++]=x[i++];
	}
	while(j<=R)
	{
		y[k++]=x[j++];
	}
	for(i=L;i<=R;i++)
	{
		x[i]=y[i];//复制回去 
	}
}

void Part(int L,int R)//拆分 
{
	int M;
	if(R>L)//长度大于1才需要拆分 
	{
		M=(L+R)/2;
		Part(L,M);
		Part(M+1,R);
		Merge(L,R,M);//先拆分成2部分，分别求解后再合并 
	}
}

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
	}
	Rnum=0;
	Part(1,n);
	printf("%lld",Rnum);
    return 0;
}
