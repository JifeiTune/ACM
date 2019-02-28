#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cstdio>
#include<map>
#include<set>
#include<string>
#include<list>
#include<cmath>
#include<stack>
#include<queue>

using namespace std;

/*
n个数，在其中插入k（k<n-1）个乘号
求总的最大值

设dp[i][j]为前i个数，含j个乘号时的最大值
则dp[i][j]通过枚举dp[t][j-1]（t<i）在乘上[t+1,i]组成的数得到
其中的最大值即为所求
*/

long long dp[20][20];//前i个数，j个乘号最大值
long long val[20][20];//[i,j]组成的数的值
char x[20];

int main()
{
    ios::sync_with_stdio(false);
    int n,k,i,j,t;
    long long MAX;
    cin>>n>>k;
    cin>>(x+1);
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++)
    {
        val[i][i]=x[i]-'0';
        for(j=i+1;j<=n;j++)
        {
            val[i][j]=val[i][j-1]*10+x[j]-'0';
            //printf("%d %d %lld\n",i,j,val[i][j]);
        }
        dp[i][0]=val[1][i];
    }
    for(i=2;i<=n;i++)//结尾
    {
        for(j=1;j<i;j++)//乘号个数
        {
            MAX=0;
            for(t=j;t<i;t++)//分割点
            {
                MAX=max(MAX,dp[t][j-1]*val[t+1][i]);
            }
            dp[i][j]=MAX;
        }
    }
    cout<<dp[n][k];
    return 0;
}
