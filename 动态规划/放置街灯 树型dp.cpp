#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<vector> 
/*
UVA - 10859
Placing Lampposts

�������޻�ͼ��ɭ�֣��Ľڵ��Ϸŵƣ�����������õ����ڵ����бߣ�
����ʹ�����٣�������ͬʱ������ʹ������ͬʱ�����ı����࣬
�������ͷֱ�һյ�ơ���յ�������ı�����
Ϊ��ͳһ������Сֵ���ĳɾ���ʹ����һյ�������ıߣ�v2����������
�ܵ���Ϊv1������߿���Ϊʹ(M*v1+v2)������С��M������ȡ2000 
*/
using namespace std;

vector<int> x[1000];//����ÿ���ڵ����֮�����Ľڵ�
int dp[1000][2];//ĳ���ڵ���Ϊ���ڵ�ʱ����������Ѿ��ߣ��ڶ�άΪ0�����ڵ�δ�ţ�Ϊ1�������
bool vis[1000][2];//ĳ�־����Ƿ��ǹ� 

int dfs(int i,int j,int f)//iΪ���ڵ㣬jΪ���ڵ��Ƿ�ŵƣ�fΪ���ڵ� 
{
	if(vis[i][j])
	{
		return dp[i][j];//�Ѿ��߹��Ĳ����پ��� 
	}
	int ans1=0,ans2=0,k;
	vis[i][j]=1;//���־�����Ϊ����
	//���ڵ��
	ans1+=2000;
	if(f!=-1&&j==0)//���ڵ�δ�� 
	{
		ans1++;//����һ������һյ�������ı� 
	}
	for(k=0;k<x[i].size();k++)
	{
		if(x[i][k]!=f)//ǧ���©���Լ��ĸ��ڵ�Ҳ�����У�����Ӧ������ 
		{
			ans1+=dfs(x[i][k],1,i);
		}
	}
	//���ڵ㲻��
	if(f==-1||j==1)//���ڵ�Ϊ���ڵ���߸��ڵ����
	{
		for(k=0;k<x[i].size();k++)
		{
			if(x[i][k]!=f)//ǧ���©���Լ��ĸ��ڵ�Ҳ�����У�����Ӧ������ 
			{
				ans2+=dfs(x[i][k],0,i);
			}
		}
		//Ҫע�⣬�ŵ����������ģ�����ȴ���������ģ����²�ֻ���ڲ��ŵ�if��ִ�� 
		if(f!=-1)//����j==1һ���� 
		{
			ans2++;
		}
		ans1=min(ans1,ans2);
	}
	return dp[i][j]=ans1;
}

int main()
{
	int T,n,m,a,b,i,j,k,tem,ans;
	scanf("%d",&T);
	while(T--)
	{
		ans=0; 
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			x[i].clear();//���ԭ������ 
		}
		memset(vis,0,sizeof(vis));//ÿ��״̬��Ϊδ���� 
		for(k=0;k<m;k++)
		{
			scanf("%d%d",&a,&b);
			x[a].push_back(b);
			x[b].push_back(a);//����ͼ��˫������ 
		}
		for(i=0;i<n;i++)
		{
			if(!vis[i][0])//�ҵ�δ���ʽڵ㣬����Ϊ���������һ���� 
			{
				ans+=dfs(i,0,-1);//-1�����޸��ڵ� 
			}
		}
		printf("%d %d %d\n",ans/2000,m-ans%2000,ans%2000); 
	}
	return 0; 
}











