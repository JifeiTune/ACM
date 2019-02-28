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
n个数，可以取其中任意多个
但所取的和必须为k的倍数
问这个和最大是多少

和01背包类似，每个数要么放要么不放
dp[i][j]表示考虑前i个数
其和%k等于j时的最大解
注：涉及到倍数一般都考虑取余解决
*/
int x[101];
int dp[101][101];

int main()
{
    ios::sync_with_stdio(false);
    int i,j,ans,temp,n,k,t1,t2,MAX;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    memset(dp,-1,sizeof(dp));//-1代表该状态不可达
    dp[0][0]=0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<k;j++)
        {
            if(dp[i-1][(j-x[i]%k+k)%k]!=-1)//放（如果放了能达到该状态）
            {
                t1=dp[i-1][(j-x[i]%k+k)%k]+x[i];
            }
            else
            {
                t1=-1;
            }
            t2=dp[i-1][j];//不放
            dp[i][j]=max(t1,t2);
        }
    }
    cout<<dp[n][0];
    return 0;
}
