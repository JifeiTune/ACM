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
			A[tem]=i;//��¼���ĸ���Ÿĳ���i����1��n�������±�ţ�
		}
		for(i=1;i<=q+1;i++)
		{
			scanf("%d",&tem);
			if(A[tem]!=0)
			{
				B[++Bnum]=A[tem];//ֻ��¼����ֵ��Ӧ 
			}	
		}
		
		dp[1]=1; 
		for(i=2;i<=Bnum;i++)//��̬�滮������������У�dp[i]��ʾ��B[i]��β��������г��� 
		{
			int max=0;
			for(j=1;j<i;j++)
			{
				if(B[i]>B[j])
				{
					max=max>dp[j]+1?max:dp[j]+1;//ԭ���м���B[i]��ȡ� 
				}
			}
			dp[i]=(max==0)?1:max;//δ�ҵ����ʱ��ȡ1��ֻ���Լ��� 
		}
		printf("Case %d: %d\n",hh,dp[Bnum]);	
	} 
	return 0; 
}












