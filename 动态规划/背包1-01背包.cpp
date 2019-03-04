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
01背包
每个背包要么放要么不放
dp[i][j]为考虑到前i个物品，背包容量为j时的最大价值
则dp[i][j]等于dp[i-1][j]（不放）和dp[i-1][j-wei[i]]+val[i]（放）中的最大值

可以发现dp[i][k1]总是由dp[i][k2]得到，故可优化空间，降为1维
但要注意，此时容量的循环应该逆序，即all->wei[i]
因为大容量的求解要用到前一状态（i-1）小容量的最优解，如果顺序来
小容量的解被替换成当前状态（i），影响大容量时的求解

如果要求背包必须放满，那么状态的意义也变为正好放满
初始化时，dp[0][0]=0，不可达状态设为极小值（dp[0][k]，k>=1）
则求解过程中只要有可达状态，max中必然忽略极小值
*/

int dp[31][201];
int val[31];//价值
int wei[31];//重量

int main()
{
    ios::sync_with_stdio(false);
    int i,j,T,temp,MAX,all,n;
    cin>>all>>n;
    for(i=1;i<=n;i++)
    {
        cin>>wei[i]>>val[i];
    }
    for(j=0;j<=all;j++)
    {
        dp[0][j]=0;//根据递推表达式初始化边界
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<wei[i];j++)//此时只能不放
        {
            dp[i][j]=dp[i-1][j];
        }
        for(j=wei[i];j<=all;j++)//此时可放可不放
        {
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-wei[i]]+val[i]);
        }
    }
    cout<<dp[n][all];
    return 0;
}

