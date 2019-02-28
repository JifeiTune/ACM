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

using namespace std;

/*
求最长公共上升子序列，输出长度和该序列
简析见文档

本题还要将之具体输出
用last[i]来表示最优解时某个元素的前一个元素
dp过程更新即可
*/

int A[501];
int B[501];
int dp[501][501];//dp[i][j]表示以A[i]、B[j]结尾时的最长公共上升子序列长度
int last[501];//最优解时上一个点（B中）

void out(int p)
{
    if(last[p]!=p)
    {
        out(last[p]);
    }
    cout<<B[p]<<' ';
}

int main()
{
    int i,j,MAX,ans,lenA,lenB,End,p;
    cin>>lenA;
    for(i=1;i<=lenA;i++)
    {
        cin>>A[i];
        dp[i][0]=0;
    }
    cin>>lenB;
    for(i=1;i<=lenB;i++)
    {
        cin>>B[i];
        dp[0][i]=0;
        last[i]=i;
    }
    dp[0][0]=0;
    ans=0;
    for(i=1;i<=lenA;i++)
    {
        MAX=0;
        for(j=1;j<=lenB;j++)
        {
            if(A[i]!=B[j])
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=MAX+1;
                last[j]=MAX>0?p:j;//只在会增长时更新前一个下标
            }
            if(dp[i][j]>ans)
            {
                ans=dp[i][j];
                End=j;//更新最优解最后一个元素坐标
            }
            if(A[i]>B[j]&&dp[i][j]>MAX)
            {
                MAX=dp[i][j];
                p=j;//记录下标
            }
        }
    }
    cout<<ans<<'\n';
    if(ans>0)
    {
        out(End);
    }
    return 0;
}


