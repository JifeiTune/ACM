#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
宽w高h的网格上有k个樱桃，坐标已知
问最短的总切割长度，使最后每块都恰好有一个樱桃
类比曾经的巧克力题，dp[h1][h2][w1][w2]
表示方块高边界为h1、h2，宽边界为w1、w2时的最短切割长度（左开右闭）

现在问题是怎么统计任意子矩阵内樱桃个数
可以预处理出每一个左上角固定为原矩阵左上角，右下角任意的矩形内樱桃个数
任意子矩阵内樱桃个数用容斥算即可 
*/
using namespace std;


bool che[21][21];//某坐标上是否有樱桃
int Num[21][21];//(1,1)位左上角，(i,j)为右下角的矩形内樱桃个数 
int dp[21][21][21][21];
int w,h,k;

#define Sum(h1,h2,w1,w2) (Num[h2][w2]-Num[h1][w2]-Num[h2][w1]+Num[h1][w1])//任意矩阵内樱桃个数 

int dfs(int h1,int h2,int w1,int w2)//蛋糕范围为(h1,h2]，(w1,w2]时最小切割长度 
{
	int tem,i,t1,t2,ans=0x7fffffff;
	if(dp[h1][h2][w1][w2]!=-1)
	{
		return dp[h1][h2][w1][w2];
	}
	tem=Sum(h1,h2,w1,w2);
	if(tem==1||tem==0)//只要一个樱桃或没有，不必切 
	{
		return dp[h1][h2][w1][w2]=0;
	}
	for(i=h1+1;i<h2;i++)//枚举横着切 
	{
		t1=Sum(h1,i,w1,w2);
		t2=Sum(i,h2,w1,w2);
		if(t1>=1&&t2>=1)//都大于等于一才有切割的意义 
		{
			ans=min(ans,w2-w1+dfs(h1,i,w1,w2)+dfs(i,h2,w1,w2));
		}
	}
	for(i=w1+1;i<w2;i++)//枚举竖着切
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
		for(i=1;i<=h;i++)//一行一行填充Num 
		{
			for(j=1;j<=w;j++)
			{
				Num[i][j]=Num[i][j-1]+che[i][j]+Sum(0,i-1,j-1,j);//想象一个矩形向右扩充 
			}
		}
		printf("Case %d: %d\n",cas++,dfs(0,h,0,w));
	}
	return 0; 
}


