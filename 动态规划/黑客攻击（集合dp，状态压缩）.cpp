#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
Hackers' Crackdown
*/
using namespace std;

int main()
{
	int n,i,j,tem,ans,m,cas=1;
	int x[16];//ÿ̨���Ժ���ֱ֮�������ĵ���
	int all[1<<16];//���м���
	int dp[1<<16];//ÿ���������ܻ��ֵ�������� 
	while(scanf("%d",&n)&&n!=0)
	{
		memset(x,0,sizeof(x));
		memset(all,0,sizeof(all));
		memset(dp,0,sizeof(dp));
		//����Ŵ�0��ʼ��Ϊ��1��ʼ
		for(i=0;i<n;i++)
		{
			x[i]=(1<<i);//�Լ������Լ�������� 
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&tem);
				x[i]=x[i]|(1<<(tem));
			}	
		}
		for(i=0;i<(1<<n);i++)//2^n������ 
		{
			for(j=0;j<n;j++)//n��λ��Ѱ��Ϊ1λ 
			{
				if(i&(1<<j))
				{
					all[i]=all[i]|x[j];	
				} 
			}
		}
		int qj=(1<<n)-1;
		for(i=1;i<(1<<n);i++)
		{
			for(j=i;j;j=(j-1)&i)
			{
				if(all[j]==qj)
				{
					dp[i]=max(dp[i],dp[i^j]+1);
				}
			}
		}
		printf("Case %d: %d\n",cas++,dp[qj]);
	}	
}











