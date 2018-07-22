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
给定一个字符串，把它分割成最少个子串，每个子串都是回文串，求最小个数
dp[i]记录以i结尾的子串，最少分割数
dp[i]=min{dp[j-1]+1}，j从1到i，且j到i为回文（从1开始） 
*/

inline bool isHui(string &s,int be,int ed)
{
	be--,ed--;//传入的是按1开始的 
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
		dp[1]=1;//从第二个字符开始
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













