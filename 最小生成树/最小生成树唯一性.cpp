#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
�ж���С�������Ƿ�Ψһ
 
*/
using namespace std;

#define MAXN (int)(1e3+1)//���ڵ��� 
#define INF 0x3f3f3f3f//����ֵ 


int cost[MAXN][MAXN];//�ķѾ��󣨱ߣ�
int lowC[MAXN];//ÿ���ڵ��뵱ǰ���ɵ�������̾��� 
bool vis[MAXN];

int Prim(int n)//�ڵ����������0��ʼ���
{
	int i,j,MIN,ans=0,p;
	vis[0]=1;//�Ƚ�0�Žڵ����
	for(i=1;i<n;i++)
	{
		lowC[i]=cost[0][i];//��Ϊ��ǰֻ��0�Žڵ� 
	}
	for(i=1;i<n;i++)//���ֻ�Ǵ�������ҪѰ��ʣ��n-1���� 
	{
		MIN=INF;
		p=-1;
		for(j=0;j<n;j++)//����δ����ڵ� 
		{
			if(!vis[j]&&lowC[j]<MIN)
			{
				MIN=lowC[j];
				p=j;
			}
		}
		if(p==-1)
		{
			return -1;
		}
		vis[p]=1;
		ans+=MIN;
		for(j=0;j<n;j++)//����δ����ڵ� 
		{
			if(!vis[j]&&cost[j][p]<lowC[j])
			{
				lowC[j]=cost[j][p];
			}
		}
	}
	return ans;
} 

int main()
{
	memset(cost,0x3f,sizeof(cost));
	int n=3;
	for(int i=0;i<3;i++)
	{
		cost[i][i]=0;
	}
	cost[0][1]=cost[1][0]=1;
	cost[1][2]=cost[2][1]=1;
	cout<<Prim(3);
	return 0; 
}


