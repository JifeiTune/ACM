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
n个元素划分入k个集合(k<=n)，有几种划分方法
注意元素是不同的，如1、2、3划分入2个集合，有3种：
1    2,3
1,2    3
1,3    2

设dp[i][j]表示前i个元素划分入j个集合时的方法数
则求到dp[i][j]时，第i个元素要么新开一个集合放，要么放入之前已有的集合 
*/ 

long long dp[31][31];//dp[i][j]表示前i个元素划分入j个集合时的方法数


int main()
{
    int i,j,n,k;
    memset(dp,0,sizeof(dp));
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        dp[i][1]=1;//边界
        for(j=2;j<=i&&j<=k;j++)
        {
            dp[i][j]=j*dp[i-1][j]+dp[i-1][j-1];//放入一个非空集合，或者放入一个空集合
        }
    }
    cout<<dp[n][k];
    return 0;
}



