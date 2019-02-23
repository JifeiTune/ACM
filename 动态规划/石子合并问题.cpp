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
一排石子堆，每次可以合并相邻两堆
合并的花费是两堆总的石子数
最后要合并成一堆，问总的最小花费

考虑最后一次合并，必然是[1,k],[k,N]合并
花费为合并成[1,k]和[k,N]的最小值之和
再加上，[1,N]的总的石子数

假设合并成[1,k]和[k,N]的最小值都知道
那枚举k就行了
对合并成[1,k]和[k,N]最小值的求解也一样
递归+dp解决
*/

int dp[101][101];//dp[i][j]表示将i到j的石子堆合并成一堆时的最小花费
int sum[101];//前缀和，用来求i到j的石子总量

int solve(int L,int R)
{
    if(dp[L][R]!=-1)
    {
        return dp[L][R];
    }
    int k,i,j,temp,ans=0x7fffffff;
    for(k=L;k<R;k++)
    {
        temp=solve(L,k)+solve(k+1,R);
        ans=min(ans,temp);
    }
    dp[L][R]=ans+sum[R]-sum[L-1];
    return dp[L][R];
}

int main()
{
    ios::sync_with_stdio(false);
    int N,i,ans=1;
    cin>>N;
    sum[0]=0;
    memset(dp,-1,sizeof(dp));
    for(i=1;i<=N;i++)
    {
        cin>>sum[i];
        sum[i]+=sum[i-1];
        dp[i][i]=0;//同一堆石子无需合并，花费为0
    }
    cout<<solve(1,N);
    return 0;
}
