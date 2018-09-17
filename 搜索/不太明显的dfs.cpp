#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
4���ǹ���ÿ�Ѹ���Ϊn��ÿ���ǹ�������ɫ
һ�����ӣ�������װ5���ǹ� 
ÿ�ο��Դ�����Ѷ�ȡ��һ������������
ÿ����������2���ǹ���ɫ��ͬʱ�����Դ��������ó���ռΪ����
Ϊ������õ����ٶ�
�����ϵ�ǰ���ӵ�״̬��Ӱ�쵽���� 
ʵ���ϵ�4���ǹ��ֱ����ߵĸ���ȷ��ʱ��ֻҪ���״̬�ɴ���һ����Ψһ��
��������ʵ���������״̬�ɲ��ɴ� 
��dp[i][j][k][n]Ϊ���ѷֱ�ʣ��i��j��k��nʱ��໹���õĶ���
dfsһ�鼴�� 
*/
using namespace std;

int pile[5][41];//�Ķ��ǹ� 
int dp[41][41][41][41];
int Left[5];//��ǰ������ʣ���� 

int dfs(int num,int bas)//��ǰ�õ��������������ǹ�������״̬ 
{
	if(dp[Left[1]][Left[2]][Left[3]][Left[4]]!=-1)
	{
		return dp[Left[1]][Left[2]][Left[3]][Left[4]];
	}
	if(num==5)//װ������
	{
		return dp[Left[1]][Left[2]][Left[3]][Left[4]]=0;
	}
	int i,ans=0;
	for(i=1;i<=4;i++)
	{
		if(Left[i]==0)//i��ȡ���� 
		{
			continue;
		}
		Left[i]--;
		if((bas&(1<<pile[i][Left[i]+1]))==0)//û���ظ� 
		{
			
			ans=max(ans,dfs(num+1,bas|(1<<pile[i][Left[i]+1])));
		}
		else//���ظ� 
		{
			ans=max(ans,1+dfs(num-1,bas^(1<<pile[i][Left[i]+1])));
		}
		Left[i]++;//���� 
	}
	return dp[Left[1]][Left[2]][Left[3]][Left[4]]=ans;
}

int main()
{
	int n,i,j,k,ans;
	while(scanf("%d",&n))
	{
		if(n==0)
		{
			break;	
		}
		for(i=n;i>=1;i--)
		{
			for(j=1;j<=4;j++)
			{
				scanf("%d",&pile[j][i]);
			}
		}
		for(i=1;i<=4;i++)
		{
			Left[i]=n;
		}
		memset(dp,-1,sizeof(dp));
		printf("%d\n",dfs(0,0));
	} 
	return 0; 
}


