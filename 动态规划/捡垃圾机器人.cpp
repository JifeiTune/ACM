#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
UVALive - 3983
Robotruck
�ر�ע�⣡���������������Ŀո񣬾�Ȼֱ��WA�� 
*/
using namespace std;

int w[100001];//����
int Tdis[100001];//�ӵ�һ������;�ߵ��õ�ľ��� 
int ori[100001];//ԭ��ֱ�ӵ��õ����
int dp[100001];//����i��֮ǰȫ����������̾��� 

inline int fun(int i)
{
	return dp[i]+ori[i+1]-Tdis[i+1];
} 

int main()
{
	int T,C,n,i,j,la,lb,a,b,tem,ans,MIN;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&C,&n);
		if(n==0)
		{
			printf("0\n");
			if(T>0)
			{
				putchar('\n');
			}
			continue;
		}
		scanf("%d%d%d",&la,&lb,&w[1]);//la��lb֮����Ϊ��һ����
		ori[1]=la+lb;
		Tdis[1]=0;
		dp[0]=0;
		dp[1]=2*ori[1];//dp�߽� 
		for(i=2;i<=n;i++)
		{
			scanf("%d%d%d",&a,&b,&w[i]);
			ori[i]=a+b;
			Tdis[i]=Tdis[i-1]+abs(a-la)+abs(b-lb);
			la=a,lb=b;
		}
		for(i=2;i<=n;i++)
		{
			tem=w[i],MIN=fun(i-1);
			for(j=i-1;j>=1&&tem+w[j]<=C;j--)//��ǰѰ��װ���µ����� 
			{
				tem+=w[j];	
				MIN=min(MIN,fun(j-1));
			}
			dp[i]=MIN+Tdis[i]+ori[i];
		}
		printf("%d\n",dp[n]);
		if(T>0)
		{
			putchar('\n');
		}
	} 
	return 0; 
}










