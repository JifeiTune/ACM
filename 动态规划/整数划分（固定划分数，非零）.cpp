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
整数n划分成k份，k份的和为n（划分后不计顺序，如1,3和3,1是同一个划分）
问划分总数

设dp[i][j]表示将i划分成j份的划分数
当i<j时为0，i==j时为1
i>j时，若j份都>1，即先划分为j个1，剩下的i-j再分成j份
若存在==1的， 则先将i-1分成j-1份，剩下的1自成1份
即dp[i][j]=dp[i-j][j]+dp[i-1][j-1]
*/

long long dp[201][7];//dp[i][j]表示i个元素划分成j份的方法数


int main()
{
    int i,j,n,k;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        dp[i][1]=1;//分成1份只有1种分法
        for(j=2;j<=i&&j<=k;j++)
        {
            if(i<j)
            {
                dp[i][j]=0;
            }
            else if(i==j)
            {
                dp[i][j]=1;
            }
            else
            {
                dp[i][j]=dp[i-j][j]+dp[i-1][j-1];
            }
        }
    }
    cout<<dp[n][k];
    return 0;
}


