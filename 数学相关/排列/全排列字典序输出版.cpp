#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 

using namespace std;

void permutation(int x[],int i,int j)//x[i]��x[j]ȫ����
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
		��򵥵�ֱ��swap��ʹ���������ȫ�ǰ��ֵ���
		ʵ���ϣ�ѡȡ��ĳһ���������Ƶ���λ����������֮ǰ��Ӧ�����ƣ�����ǰ��ֵ��� 
		*/ 
		for(n=i;n<=j;n++)
		{
			tem=x[n];//�Ż��棬ÿһ�ν���ѡȡλ���һλ������ʵ�ֲ������ƵĲ��� 
			x[n]=x[i];
			x[i]=tem;
			permutation(x,i+1,j);
		}
		tem=x[i];
		for(n=i;n<j;n++)//���ǵ����Ƹ�ԭ������ݹ��л�Ӱ����һ�ε��õĽ�� 
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


