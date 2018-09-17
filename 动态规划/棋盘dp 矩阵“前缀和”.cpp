#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
��w��h����������k��ӣ�ң�������֪
����̵����и�ȣ�ʹ���ÿ�鶼ǡ����һ��ӣ��
����������ɿ����⣬dp[h1][h2][w1][w2]
��ʾ����߽߱�Ϊh1��h2����߽�Ϊw1��w2ʱ������и�ȣ����ұգ�

������������ôͳ�������Ӿ�����ӣ�Ҹ���
����Ԥ�����ÿһ�����Ͻǹ̶�Ϊԭ�������Ͻǣ����½�����ľ�����ӣ�Ҹ���
�����Ӿ�����ӣ�Ҹ������ݳ��㼴�� 
*/
using namespace std;


bool che[21][21];//ĳ�������Ƿ���ӣ��
int Num[21][21];//(1,1)λ���Ͻǣ�(i,j)Ϊ���½ǵľ�����ӣ�Ҹ��� 
int dp[21][21][21][21];
int w,h,k;

#define Sum(h1,h2,w1,w2) (Num[h2][w2]-Num[h1][w2]-Num[h2][w1]+Num[h1][w1])//���������ӣ�Ҹ��� 

int dfs(int h1,int h2,int w1,int w2)//���ⷶΧΪ(h1,h2]��(w1,w2]ʱ��С�и�� 
{
	int tem,i,t1,t2,ans=0x7fffffff;
	if(dp[h1][h2][w1][w2]!=-1)
	{
		return dp[h1][h2][w1][w2];
	}
	tem=Sum(h1,h2,w1,w2);
	if(tem==1||tem==0)//ֻҪһ��ӣ�һ�û�У������� 
	{
		return dp[h1][h2][w1][w2]=0;
	}
	for(i=h1+1;i<h2;i++)//ö�ٺ����� 
	{
		t1=Sum(h1,i,w1,w2);
		t2=Sum(i,h2,w1,w2);
		if(t1>=1&&t2>=1)//�����ڵ���һ�����и������ 
		{
			ans=min(ans,w2-w1+dfs(h1,i,w1,w2)+dfs(i,h2,w1,w2));
		}
	}
	for(i=w1+1;i<w2;i++)//ö��������
	{
		t1=Sum(h1,h2,w1,i);
		t2=Sum(h1,h2,i,w2);
		if(t1>=1&&t2>=1) 
		{
			ans=min(ans,h2-h1+dfs(h1,h2,w1,i)+dfs(h1,h2,i,w2));
		}
	}
	return dp[h1][h2][w1][w2]=ans;
}

int main()
{
	int i,j,ans,X,Y,cas=1;
	while(~scanf("%d%d%d",&h,&w,&k))
	{
		memset(dp,-1,sizeof(dp));
		memset(che,0,sizeof(che));
		memset(Num,0,sizeof(Num));
		for(i=1;i<=k;i++)
		{
			scanf("%d%d",&Y,&X);
			che[Y][X]=1;
		}
		for(i=1;i<=h;i++)//һ��һ�����Num 
		{
			for(j=1;j<=w;j++)
			{
				Num[i][j]=Num[i][j-1]+che[i][j]+Sum(0,i-1,j-1,j);//����һ�������������� 
			}
		}
		printf("Case %d: %d\n",cas++,dfs(0,h,0,w));
	}
	return 0; 
}


