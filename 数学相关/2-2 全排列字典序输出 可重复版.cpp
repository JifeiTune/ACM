#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>

using namespace std;

void permutation(int x[],int i,int j)
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
		permutation(x,i+1,j);//��һλ�϶����Լ��ظ����������� 
		for(n=i+1;n<=j;n++)
		{
			if(x[i]!=x[n])//����ʱ��ֹ�ظ������ɱ����ظ����� 
			{
				tem=x[n];
				x[n]=x[i];
				x[i]=tem;
				permutation(x,i+1,j);
			}
		}
		tem=x[i];
		for(n=i;n<j;n++) 
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
	for(i=0;i<n;i++) scanf("%d",&x[i]);
	sort(x,x+n);//�������룬������ 
	permutation(x,0,n-1);
	return 0; 
}


