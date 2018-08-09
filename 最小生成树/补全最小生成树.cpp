#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
ͼ���Ѿ�ѡȡ�����ɱ�
�ڴ˻���������С��������Ȩֵ��ȥ���еģ� 
����ѡȡ��Ȩֵ��Ϊ0���� 
*/
using namespace std;

#define MAXN (int)(1e2+1)//���ڵ��� 
#define INF 0x3f3f3f3f//����ֵ 


int cost[MAXN][MAXN];//�ķѾ��󣨱ߣ�
int lowC[MAXN];//ÿ���ڵ��뵱ǰ���ɵ�������̾��� 
bool vis[MAXN];

int Prim(int n)//�ڵ����������0��ʼ���
{
	memset(vis,0,sizeof(vis));
	int i,j,MIN,ans=0,p;
	vis[1]=1;//�Ƚ�0�Žڵ����
	for(i=2;i<=n;i++)
	{
		lowC[i]=cost[1][i];//��Ϊ��ǰֻ��0�Žڵ� 
	}
	for(i=1;i<n;i++)//���ֻ�Ǵ�������ҪѰ��ʣ��n-1���� 
	{
		MIN=INF;
		p=-1;
		for(j=2;j<=n;j++)//����δ����ڵ� 
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
		for(j=2;j<=n;j++)//����δ����ڵ� 
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
	int N,Q,a,b,i,j,tem;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d",&a,&b);
		cost[a][b]=0;
		cost[b][a]=0;
	}
	printf("%d",Prim(N));
	return 0; 
}







