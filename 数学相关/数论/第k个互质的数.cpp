#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<vector>
using namespace std;
/*
������������ 
���߼��ģ���û��������
��m��x���ʣ���m��x+m,x+2*m����������
���ǣ������mС����m���ʵ�������
���Ǹ��Լ���m*i(i>=0��iΪ����)����m���ʣ�ȡ�๹��ѭ�� 
*/
int pri[1000005];//��kС��������m���ʵ������Ժ�ÿ��mѭ��һ�� 
int size;

inline int gcd(int a,int b)
{
	int tem=a%b;
	while(tem!=0)
	{
		a=b;
		b=tem;
		tem=a%b;
	}
	return b;
}

int main()
{
	int m,k,i,j,ans,tem;
	while(~scanf("%d%d",&m,&k))
	{
		size=1;
		pri[0]=1;
		for(i=2;i<m;i++)
		{
			if(gcd(m,i)==1)
			{
				pri[size++]=i;
			}
		}
		if(k<=size)
		{
			printf("%d\n",pri[k-1]);
		}
		else
		{
			i=(k-1)/size;//��i+1��ѭ��
			j=k%size;//ѭ���ڵ�j��
			if(j==0) 
			{
				j=size;
			}
			printf("%d\n",i*m+pri[j-1]);
		}
	}
	return 0; 
}














