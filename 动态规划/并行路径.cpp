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
一个正方形网格，每个格子有一个数
每次只能往下和右走，走到某个格子后可以取走其上的数，取走后置为0
问先后走2次，总的收获最大值多少

只能向下和向右走，则可用dp解决，如果走一次，很好解决
走2次，关键就是第二次可能走到第一次已经取走了的数上
增加2个状态，dp数组为4维，假设两次是同时走的

每个点都可能从左或上走来，故有4中情况
两点可能重合，若重合还有减去
*/

int x[11][11];
int dp[11][11][11][11];//第一条路径走到x[i][j]，第二条路径走到x[t1][t2]时的最大值

int main()
{
    ios::sync_with_stdio(false);
    int T,i,j,ans,temp,n,k,lenA,lenB,t1,t2,MAX,a,b,c;
    memset(x,0,sizeof(x));
    cin>>n;
    while(cin>>a>>b>>c)
    {
        if(a==0)
        {
            break;
        }
        x[a][b]=c;
    }
    memset(dp,0,sizeof(dp));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(t1=1;t1<=n;t1++)
            {
                for(t2=1;t2<=n;t2++)
                {
                    dp[i][j][t1][t2]=max(dp[i-1][j][t1-1][t2],dp[i-1][j][t1][t2-1]);
                    dp[i][j][t1][t2]=max(dp[i][j][t1][t2],dp[i][j-1][t1-1][t2]);
                    dp[i][j][t1][t2]=max(dp[i][j][t1][t2],dp[i][j-1][t1][t2-1]);
                    dp[i][j][t1][t2]+=x[i][j]+x[t1][t2];//加上当前2个点取数
                    if(i==t1&&j==t2)
                    {
                        dp[i][j][t1][t2]-=x[i][j];//两点重合，只加一次
                    }
                }
            }
        }
    }
    cout<<dp[n][n][n][n];
    return 0;
}
