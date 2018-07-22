#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
#include<vector>
/*
UVALive - 4256
Salesmen
*/
using namespace std;

#define INF 0x7fffffff

vector<int> x[101];//���100����
int dp[201][101];//ǰi����������������i����Ϊjʱ����С�޸���  
int p[201];//���޸����� 

int main()
{
	int T,n1,n2,n,i,j,k,a,b,tem,ans,MIN;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n1,&n2);
		for(i=1;i<=n1;i++)
		{
			x[i].clear();
			x[i].push_back(i);//�Լ����Լ�����ͨ 
		}
		for(i=1;i<=n2;i++)
		{
			scanf("%d%d",&a,&b);
			x[a].push_back(b);
			x[b].push_back(a); 
		}
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&p[i]);
		}
		for(i=1;i<=n;i++)
		{
			dp[1][i]=1;
		}
		dp[1][p[1]]=0;//dp�߽磬�����е�һ�����޸ĳɱ�ĵ㣬�޸�������1
		for(i=2;i<=n;i++)//������n���� 
		{
			for(j=1;j<=n1;j++)//ÿ����n1���޸� 
			{
				MIN=INF;
				if(j==p[i])
				{
					for(k=0;k<x[j].size();k++)//ÿ���޸ĵ����ڱ� 
					{
						MIN=min(MIN,dp[i-1][x[j][k]]);
					}
				}
				else
				{
					for(k=0;k<x[j].size();k++)//ÿ���޸ĵ����ڱ� 
					{
						MIN=min(MIN,dp[i-1][x[j][k]]+1);
					}
				}
				dp[i][j]=MIN;	
			}	
		}
		MIN=INF;
		for(i=1;i<=n1;i++)
		{
			MIN=min(MIN,dp[n][i]);
		}
		printf("%d\n",MIN);
	}
	return 0; 
}









