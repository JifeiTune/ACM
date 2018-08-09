#include<iostream>
#include<string>
#include<algorithm>
#include<cmath> 
#include<time.h> 
using namespace std;
/*
HDU 1024
Max Sum Plus Plus
*/ 
#define MAXN (int)(1e6+1)
int x[MAXN];
int dp[MAXN];
int Last[MAXN];

inline int max(int x,int y)
{
	return x>=y?x:y;
}

int main()
{
	int m,n,tem,MAX,i,j;
	char c;
	bool flag;
	while(~scanf("%d%d",&m,&n))//��Ϊn��ѡȡ���ཻ��m�� 
	{
		getchar();//��ȥ��һ���ո� 
		for(i=1;i<=n;i++)
		{ 
			flag=0;//1Ϊ����
			c=getchar();//��һλ 
			if(c=='-')
			{
				flag=1;
				tem=0;
			}	
			else
			{
				tem=c-'0';
			}
			c=getchar(); 
			while(c>='0'&&c<='9')
			{
				tem=tem*10+c-'0';
				c=getchar();
			} 
			if(flag)
			{
				tem=-tem;
			}
			x[i]=tem;
			dp[i]=0;
			Last[i]=0;
		}
		dp[0]=0;
		Last[0]=0;
		for(i=1;i<=m;i++)
        {
            MAX=0x80000000;
            for(j=i;j<=n;j++)
            {
                dp[j]=max(dp[j-1]+x[j],Last[j-1]+x[j]);
                Last[j-1]=MAX;
                MAX=max(MAX,dp[j]);
            }
        }
        printf("%d\n",MAX);
	}
	return 0; 
}


