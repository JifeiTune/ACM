#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
HDU - 1232
��ͨ����
*/
using namespace std;

int x[1001];

int find(int i)
{
	return x[i]==i?i:x[i]=find(x[i]);
}

int main()
{
	int N,M,i,j,tem,ans,num,a,b,f1,f2;
	while(scanf("%d %d",&N,&M)&&N!=0)
	{
		num=0;
		for(i=1;i<=N;i++)
		{
			x[i]=i;//һ��ʼ�ڵ㸸��Ϊ�Լ� 
		}
		for(i=1;i<=M;i++)
		{
			scanf("%d %d",&a,&b);
			f1=find(a);
			f2=find(b);
			if(f1!=f2)//����ͬһ�����ϲ���ϲ���b���ںϲ���a 
			{
				x[f2]=f1;
			}	
		}
		for(i=1;i<=N;i++)
		{
			if(x[i]==i)//����Ԫ 
			{
				num++;
			}
		}
		printf("%d\n",num-1);
	}
	return 0; 
}






