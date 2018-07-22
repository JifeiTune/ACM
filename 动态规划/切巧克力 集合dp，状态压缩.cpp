#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
UVALive - 4794
Sharing Chocolate
*/
using namespace std;

bool onlyOne(int x)
{
	while( (x&1)!=1 )//��������ֱ�����һλΪ1 
	{
		x=(x>>1);	
	}
	x=(x>>1);//ȥ�����һ��1
	return x==0?1:0;//��1��Ϊ�棬����1��Ϊ�� 
}

int area[16];//����Ҫ�е����
bool dp[101][1<<15];//�̱�Ϊi,���״̬Ϊjʱ�Ƿ���� 
bool vis[101][1<<15];//�Ƿ��Ѿ�����
int SUM[1<<15];//ÿ�����״̬����� 

bool dfs(int x,int S)//�̱�Ϊx�����״̬ΪS�ܷ���s��Sȷ�����ٰ�������Ϊ1��λ 
{
	if(vis[x][S])
	{
		return dp[x][S];
	}
	
	vis[x][S]=1;//��Ϊ�Ѿ���
	if(onlyOne(S))//Sֻ��һλ��֮ǰҲ������������Ȼ�ܷ� 
	{
		return dp[x][S]=1;
	}
	int y=SUM[S]/x;//������ 
	int S0=S&(S-1),S1;
	while(S0!=0)//��ʼö���Ӽ� 
	{
		S1=S^S0;//�Ӽ�����
		if(SUM[S0]%x==0)//�̱�ƽ����һ�� 
		{
			if(dfs(min(x,SUM[S0]/x),S0)&&dfs(min(x,SUM[S1]/x),S1))
			{
				return dp[x][S]=1;
			}
		} 
		if(SUM[S0]%y==0)
		{
			if(dfs(SUM[S0]/y,S0)&&dfs(SUM[S1]/y,S1))
			{
				return dp[x][S]=1;
			}
		}
		S0=S&(S0-1);//�Ӽ�ö�� 
	}
	return dp[x][S]=0;
}

int main()
{
	int n,x,y,i,j,a,b,tem,ans,sum,cas=1,S,all;
	while(scanf("%d",&n)&&n!=0)
	{
		sum=0;
		S=0;
		scanf("%d%d",&x,&y);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&area[i]);
			sum+=area[i];	
		}
		if(sum!=x*y)
		{
			printf("Case %d: No\n",cas++);
			continue;
		}
		memset(vis,0,sizeof(vis));
		memset(SUM,0,sizeof(SUM));
		all=(1<<n);
		for(S=1;S<all;S++)
		{
			for(i=1;i<=n;i++)//�漰��n��λ 
			{
				if((S&(1<<(i-1)))!=0)
				{
					SUM[S]+=area[i];
				}
			}
		}
		if(dfs(min(x,y),all-1))
		{
			printf("Case %d: Yes\n",cas++);
		}
		else
		{
			printf("Case %d: No\n",cas++);
		}	
	} 
	return 0; 
}










