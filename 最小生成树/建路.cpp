#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<cstdio>
/*
Poj 3625
Building Roads

N���ڵ㣬ÿ���ڵ㶼������
�����Ѿ������ɱ���
�������ʣ���ʹ������ͼ��ͨ
�����ߵĳ��Ⱥ�Ҫ��С 
���еı�Ȩֵ��Ϊ0���� 
*/
using namespace std;

#define MAXN (int)(1e3+1)//���ڵ��� 
#define INF 1e300//����ֵ 

double cost[MAXN][MAXN];//�ķѾ��󣨱ߣ�
double lowC[MAXN];//ÿ���ڵ��뵱ǰ���ɵ�������̾��� 
bool vis[MAXN];

double Prim(int n)//�ڵ����������0��ʼ���
{
	int i,j,p;
	double MIN,ans=0;
	vis[1]=1;//�Ƚ�0�Žڵ����
	for(i=2;i<=n;i++)
	{
		lowC[i]=cost[1][i];//��Ϊ��ǰֻ��0�Žڵ� 
	}
	for(i=1;i<n;i++)//���ֻ�Ǵ�������ҪѰ��ʣ��n-1���� 
	{
		MIN=INF;
		p=-1;
		for(j=1;j<=n;j++)//����δ����ڵ� 
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
		for(j=1;j<=n;j++)//����δ����ڵ� 
		{
			if(!vis[j]&&cost[j][p]<lowC[j])
			{
				lowC[j]=cost[j][p];
			}
		}
	}
	return ans;
} 

#define DIS(x1,y1,x2,y2) ( sqrt( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) ) )

double X[MAXN],Y[MAXN];

int main()
{
	int N,M,xi,yi,i,j;
	double tem;
	scanf("%d%d",&N,&M);
	for(i=1;i<=N;i++)
	{
		scanf("%lf%lf",&X[i],&Y[i]);
	}
	for(i=1;i<=N;i++)
	{
		cost[i][i]=0;//�Խ��� 
	}
	for(i=2;i<=N;i++)
	{
		for(j=1;j<i;j++)
		{
			tem=DIS(X[i],Y[i],X[j],Y[j]);
			cost[i][j]=tem;
			cost[j][i]=tem;//�ԳƼ��� 
		}
	}  
	for(i=1;i<=M;i++)
	{
		scanf("%d%d",&xi,&yi);
		cost[xi][yi]=0;
		cost[yi][xi]=0;
	}
	printf("%.2f",Prim(N));
	return 0; 
}
