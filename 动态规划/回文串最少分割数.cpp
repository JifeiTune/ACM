#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<cmath> 
/*
UVA - 11584
Partitioning by Palindromes
*/
using namespace std;

/*
����һ���ַ����������ָ�����ٸ��Ӵ���ÿ���Ӵ����ǻ��Ĵ�������С����
dp[i]��¼��i��β���Ӵ������ٷָ���
dp[i]=min{dp[j-1]+1}��j��1��i����j��iΪ���ģ���1��ʼ�� 
*/

inline bool isHui(string &s,int be,int ed)
{
	be--,ed--;//������ǰ�1��ʼ�� 
	int Blen=(ed-be)/2;
	for(int i=be;i<=be+Blen;i++)
	{
		if(s[i]!=s[ed-i+be])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	string s;
	int T,n,i,j,ans,tem,len,dp[10001],min;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		dp[0]=0; 
		dp[1]=1;//�ӵڶ����ַ���ʼ
		cin>>s;
		len=s.length();
		for(i=2;i<=len;i++)
		{
			min=0x7fffffff;
			for(j=1;j<=i;j++)
			{
				if(isHui(s,j,i))
				{
					min=min<dp[j-1]+1?min:dp[j-1]+1;
				}
			}
			dp[j-1]=min;
		}
		printf("%d\n",dp[len]);
	}
	return 0; 
}













