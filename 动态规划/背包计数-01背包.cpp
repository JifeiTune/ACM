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
n个不同整数，取其中若干各，使其和为all，问取法有几种

01背包计数问题
深刻理解原背包问题的状态转移，将状态对应的值变成能达到该状态的总数
原背包问题要在状态间取最值，计数时就是各个状态的值求和 
设dp[i][j]为考虑到第i数时，和为j的取法数
既然和要为j，那么不取时，就是dp[i-1][j]，取时，就是dp[i-1][j-val[i]]，求和即可
同样压缩为一维
*/

int dp[1001];//考虑当前数，和为i的取法数
int val[101];//价值

int main()
{
    ios::sync_with_stdio(false);
    int i,j,T,temp,MAX,all,n;
    cin>>n>>all;
    for(i=1;i<=n;i++)
    {
        cin>>val[i];
    }
    dp[0]=1;//没有数，和为0，一种，即什么都不取
    for(i=1;i<=n;i++)
    {
        for(j=all;j>=val[i];j--)
        {
            dp[j]+=dp[j-val[i]];
        }
    }
    cout<<dp[all];
    return 0;
}

