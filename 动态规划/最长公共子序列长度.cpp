#include<iostream>
#include<string>
#include<memory.h>
#include<algorithm>
#include<cmath> 
/*
UVA - 10635
Prince and Princess
*/
using namespace std;

int MaxN=250*250+5;

int main()
{
	int T,n,p,q,i,j,tem,ans,Bnum,A[MaxN],B[MaxN],dp[MaxN];
	scanf("%d",&T);
	for(int hh=1;hh<=T;hh++)
	{
		Bnum=0;
		scanf("%d %d %d",&n,&p,&q);
		memset(A,0,sizeof(A));
		for(i=1;i<=p+1;i++)
		{
			scanf("%d",&tem);
			A[tem]=i;//记录把哪个编号改成了i（从1到n依次重新编号）
		}
		for(i=1;i<=q+1;i++)
		{
			scanf("%d",&tem);
			if(A[tem]!=0)
			{
				B[++Bnum]=A[tem];//只记录非零值对应 
			}	
		}
		
		dp[1]=1; 
		for(i=2;i<=Bnum;i++)//动态规划求最长上升子序列，dp[i]表示以B[i]结尾的最长子序列长度 
		{
			int max=0;
			for(j=1;j<i;j++)
			{
				if(B[i]>B[j])
				{
					max=max>dp[j]+1?max:dp[j]+1;//原序列加上B[i]，取最长 
				}
			}
			dp[i]=(max==0)?1:max;//未找到最大时，取1（只有自己） 
		}
		printf("Case %d: %d\n",hh,dp[Bnum]);	
	} 
	return 0; 
}












