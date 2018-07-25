#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 

using namespace std;

void permutation(int x[],int i,int j)//x[i]到x[j]全排列
{
	int n,k,tem;
	if(i==j)
	{
		for(n=0;n<=j;n++)
		{
			printf("%d",x[n]);
		}
		printf("\n");
	}
	else
	{
		/*
		最简单的直接swap，使得输出不完全是按字典序
		实际上，选取到某一个，把它移到首位还不够，它之前的应该右移，这才是按字典序 
		*/ 
		for(n=i;n<=j;n++)
		{
			tem=x[n];//优化版，每一次交换选取位与第一位，即可实现不断右移的操作 
			x[n]=x[i];
			x[i]=tem;
			permutation(x,i+1,j);
		}
		tem=x[i];
		for(n=i;n<j;n++)//最后记得左移复原，否则递归中会影响上一次调用的结果 
		{
			x[n]=x[n+1];		
		}		
		x[j]=tem;
	}
}
int main()
{
	int *x,n,i;
	scanf("%d",&n);
	x=new int[n];
	for(i=0;i<n;i++) x[i]=i+1;
	permutation(x,0,n-1);
	return 0; 
}


